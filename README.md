# ⚡ Vajra-Shield — Proactive Forensic Blackbox (C Implementation)

> *"A digital guardian that watches when no one else can."*

[![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Windows-informational?style=flat-square&logo=windows)](https://github.com/Aadi7171/Vajra-Shield-C)
[![Build](https://img.shields.io/badge/Build-MinGW%2FGCC-success?style=flat-square)](https://github.com/Aadi7171/Vajra-Shield-C/blob/main/build.bat)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)
[![Live Demo](https://img.shields.io/badge/Live%20Demo-GitHub%20Pages-00e5ff?style=flat-square&logo=github)](https://aadi7171.github.io/Vajra-Shield-C/)

**Vajra-Shield** is an edge-AI terminal simulation of a real-time personal safety blackbox, written entirely in **pure C**. It models the core safety intelligence that would run on a low-power wearable device — detecting danger silently, without relying on the victim to press any button.

---

## 🌐 Live Demo

> **[▶ Try the Interactive Demo →](https://aadi7171.github.io/Vajra-Shield-C/)**

An interactive web simulation featuring:
- 🛡️ **3D animated shield model** — drag to rotate, reacts to sensor state
- 📊 **Live sensor feeds** — heart rate, accelerometers, threat level
- ⚠️ **Scenario simulations** — normal, jogging, attack, adrenaline-stillness
- 🔐 **Duress PIN keypad** — try `1234` (safe) or `4321` (silent SOS!)
- 📡 **Bluetooth sweep** — animated MAC address discovery
- 🗄️ **Forensic vault** — SHA-256 hash generation

---

## 🧠 The Concept

Most personal safety devices are **reactive** — they need you to press a button. Vajra-Shield is **proactive**. It uses sensor fusion and behavioral heuristics to detect if someone is in danger even when they can't act, and triggers a silent SOS automatically.

This repository is the embedded systems prototype of that concept, simulating sensor data and decision logic in a lightweight C terminal application.

---

## ✨ Features Simulated

| Module | Description |
|---|---|
| 🔬 **Sensor Fusion** | Simulates accelerometer + biometric data to detect physical chaos |
| 💓 **Adrenaline-Stillness Paradox** | Triggers SOS if heart rate is high but the body is completely stationary (victim pinned / tied up) |
| 🌀 **Aperiodic Chaos Detection** | Distinguishes rhythmic motion (jogging) from violent struggle using magnitude thresholds — simulating FFT filtration |
| 🔐 **Duress Protocol** | Full "Hostage Mode" — Safe-PIN `1234` vs. Duress-PIN `4321` triggers a silent, covert SOS |
| 📡 **Digital DNA Sweeping** | Mock detection of nearby Bluetooth MAC addresses to log environment witnesses |
| 🗄️ **Forensic Vault** | Mock hashing of distress data, ready for SpacetimeDB ingestion as tamper-proof evidence |

---

## 🗂️ Project Structure

```
Vajra-Shield-C/
├── src/
│   ├── main.c                    # Entry point & interactive test suite
│   ├── sensor_fusion.c/.h        # Accelerometer + biometric data simulation
│   ├── activity_classifier.c/.h  # Chaos detection & movement classification
│   ├── bluetooth_sweeper.c/.h    # MAC address environment sweep
│   ├── forensic_vault.c/.h       # Data hashing & secure vault logic
│   └── utils.c/.h                # Shared utilities
├── docs/
│   └── index.html                # Interactive web demo (GitHub Pages)
├── build.bat                     # One-click build script (Windows)
├── LICENSE
└── README.md
```

---

## 🛠️ Build & Run (Windows)

### Prerequisites
- [MinGW / GCC for Windows](https://www.mingw-w64.org/) installed and added to `PATH`

### Steps

```bash
# 1. Clone the repository
git clone https://github.com/Aadi7171/Vajra-Shield-C.git
cd Vajra-Shield-C

# 2. Build the project
build.bat

# 3. Run the interactive test suite
bin/vajra_shield.exe
```

---

## 🔑 Test PINs

| PIN | Mode |
|---|---|
| `1234` | ✅ Safe Mode — no alert triggered |
| `4321` | 🚨 Duress Mode — silent SOS triggered |

---

## 💡 How the Logic Works

```
[Sensor Data] ──► [Fusion Layer]
                        │
             ┌──────────▼──────────────┐
             │  Chaos Classifier       │
             │  - Heart Rate High?     │
             │  - Body Still?          │──► Adrenaline-Stillness Paradox ──► SOS
             │  - Aperiodic Motion?    │──► Violent Struggle Detected ──► SOS
             └─────────────────────────┘
                        │
             [Duress PIN Check] ──► Silent Alert + Forensic Vault Hash
                        │
             [Bluetooth Sweep] ──► Log MAC environment
```

---

## 🔭 Future Scope

- [ ] Port to ARM Cortex-M (STM32 / ESP32) firmware
- [ ] Integrate with real SpacetimeDB for live forensic ingestion
- [ ] Add GSM/eSIM SOS trigger module
- [ ] Real FFT via CMSIS-DSP library for true aperiodic detection
- [ ] Mobile companion app for alert reception

---

## 👨‍💻 Author

**Aditya** — [@Aadi7171](https://github.com/Aadi7171)

*Built as a proof-of-concept for embedded personal safety systems.*

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
