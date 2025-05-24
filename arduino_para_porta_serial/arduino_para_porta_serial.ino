#include <esp_heap_caps.h>

const int ecgPin = 34;
const int ledPin = 2;
const unsigned int sampleRate = 977;
const unsigned long sampleIntervalMicros = 1000000UL / sampleRate;

const int duracaoSegundos = 15;
const int totalAmostras = sampleRate * duracaoSegundos;

uint16_t* ecgData = nullptr;
unsigned long lastMicros = 0;
unsigned long lastTransmitTime = 0;

void piscarLED(int vezes = 3, int tempo = 200) {
  Serial.println("🔔 Piscar LED iniciado...");
  for (int i = 0; i < vezes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(tempo);
    digitalWrite(ledPin, LOW);
    delay(tempo);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  Serial.println("🔧 Tentando alocar PSRAM...");
  ecgData = (uint16_t*)heap_caps_malloc(totalAmostras * sizeof(uint16_t), MALLOC_CAP_SPIRAM);

  if (!ecgData) {
    Serial.println("⚠️ PSRAM não disponível. Tentando alocar na RAM interna...");
    ecgData = (uint16_t*)malloc(totalAmostras * sizeof(uint16_t));
    if (!ecgData) {
      Serial.println("❌ Falha total na alocação de memória.");
      while (true);
    } else {
      Serial.println("✅ Memória alocada com sucesso na RAM interna.");
    }
  } else {
    Serial.println("✅ Memória alocada com sucesso na PSRAM.");
  }

  Serial.println("⌛ Aguardando 5 segundos...");
  delay(5000);
  piscarLED();

  Serial.println("⏱️ Iniciando aquisição de ECG...");
  for (int i = 0; i < totalAmostras;) {
    unsigned long now = micros();
    if (now - lastMicros >= sampleIntervalMicros) {
      lastMicros = now;
      ecgData[i] = analogRead(ecgPin);
      i++;
    }
  }

  Serial.println("✅ Coleta concluída! LED ficará aceso. Transmitindo continuamente...");
  digitalWrite(ledPin, HIGH);  // LED permanece aceso
  lastTransmitTime = millis(); // Marca o tempo da primeira transmissão
}

void loop() {
  unsigned long now = millis();
  if (now - lastTransmitTime >= duracaoSegundos * 1000UL) {
    for (int i = 0; i < totalAmostras; i++) {
      Serial.println(ecgData[i]);
    }
    lastTransmitTime = now;
  }
}
