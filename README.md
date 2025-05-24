
# Automated Cardiac Arrhythmia Detection System Using CNN

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Python](https://img.shields.io/badge/python-3.8%2B-brightgreen)
![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Docs](https://img.shields.io/badge/docs-available-yellow)

---

## Overview

This project aims to develop a complete automated system for the acquisition, preprocessing, classification, and visualization of electrocardiographic (ECG) signals using Convolutional Neural Networks (CNN). The system leverages low-cost hardware components and advanced machine learning techniques to detect and classify cardiac arrhythmias in real-time.

The system consists of:

- **Signal Acquisition**: Using an AD8232 ECG module and an ESP32 microcontroller.
- **Signal Preprocessing**: Noise filtering and feature extraction.
- **Model Training**: 1D Convolutional Neural Network implemented in PyTorch.
- **Evaluation and Visualization**: Model performance metrics and predictions visualization.

The ECG dataset used is the publicly available **Leipzig Heart Center ECG-Database: Arrhythmias in Children and Patients with Congenital Heart Disease**, ensuring reproducibility and robustness.

---

## Table of Contents

- [System Architecture](#system-architecture)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
  - [Signal Acquisition](#signal-acquisition)
  - [Preprocessing](#preprocessing)
  - [Model Training](#model-training)
  - [Evaluation](#evaluation)
- [Dataset](#dataset)
- [Results](#results)
- [Visualizations](#visualizations)
- [References](#references)
- [Acknowledgements](#acknowledgements)
- [Disclaimer](#disclaimer)

---

## System Architecture

1. **Signal Acquisition**: AD8232 module captures ECG signals, ESP32 samples at 977 Hz and transmits data via serial communication.
2. **Preprocessing**: Noise filtering (Notch and Band-pass), normalization, and segmentation based on R-R intervals.
3. **Classification**: 1D CNN implemented with PyTorch for automated classification into:
   - Normal beats (N)
   - Ventricular ectopic beats (V)
   - Supraventricular ectopic beats (S)
4. **Visualization**: Confusion matrix, training curves, and sample predictions.

---

## Hardware Requirements

- ✅ ESP32 Microcontroller
- ✅ AD8232 ECG Sensor
- ✅ ECG Electrodes
- ✅ USB-to-Serial cable
- ✅ PC for data collection and model training

---

## Software Requirements

- Arduino IDE with ESP32 board support
- Python 3.8+
- Jupyter Notebook

### Required Python libraries:

```bash
pip install numpy scipy matplotlib seaborn torch wfdb
```

---

## Project Structure

```text
.
├── ESP32_driver.ino
├── Pre-processing.ipynb
├── Scam_esp32.ipynb
├── CNN_train.ipynb
├── dabatase_exp.ipynb
├── TCC_UCS_Vagner_v7_5.pdf
└── README.md
```

---

## Installation

### 1. ESP32 Setup

- Install the Arduino IDE.
- Add ESP32 board support to the Arduino IDE.
- Install necessary drivers for USB-to-Serial communication.

### 2. Python Environment

```bash
pip install numpy scipy matplotlib seaborn torch wfdb
```

---

## Usage

### Signal Acquisition

- Load `ESP32_driver.ino` into Arduino IDE.
- Connect the AD8232 module to the ESP32.
- Open the serial monitor at the configured baud rate.

**Example Parameters:**

- ADC Pin: GPIO34
- Sample Rate: 977 Hz
- Duration: 15 seconds

### Preprocessing

- Use `Pre-processing.ipynb` to filter, normalize, and segment ECG signals.

### Model Training

- Run `CNN_train.ipynb` to train the CNN model.

### Evaluation

- Analyze training loss and accuracy plots.
- Generate confusion matrix for classification performance.

---

## Dataset

**Leipzig Heart Center ECG-Database**  
Available at: [https://doi.org/10.13026/7a4j-vn37](https://doi.org/10.13026/7a4j-vn37)

---

## Results

- Automated classification of arrhythmias into three categories.
- Feasibility of using low-cost embedded systems for ECG acquisition.
- CNN model attained high accuracy.

---

## Visualizations

### CNN Architecture

![CNN Architecture](images/cnn_architecture.png)

### Confusion Matrix

![Confusion Matrix](images/confusion_matrix.png)

### Training Curves

![Training Curves](images/training_curves.png)

> Add generated figures in the `/images/` folder.

---

## References

- Leipzig Heart Center ECG-Database: [https://doi.org/10.13026/7a4j-vn37](https://doi.org/10.13026/7a4j-vn37)
- PyTorch: [https://pytorch.org](https://pytorch.org)
- AD8232 Datasheet: [https://www.analog.com/en/products/ad8232.html](https://www.analog.com/en/products/ad8232.html)
- ESP32 Docs: [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)

---

## Acknowledgements

Developed as part of the undergraduate thesis by **Vagner Antonio Cazarotto** at **Universidade de Caxias do Sul**, under **Prof. Dr. Alexandre Mesquita**.

---

## Disclaimer

For educational and research purposes only. **NOT** approved for clinical use.
