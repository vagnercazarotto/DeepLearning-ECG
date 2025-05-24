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
