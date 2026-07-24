# HelioAqua 💧☀️

**HelioAqua** is an energy-harvesting AIoT water quality analyzer designed for filter pitchers, developed by LNL-Engineering. Powered by a solar panel and backed by a supercapacitor, the device tracks water TDS (hardness) and turbidity (microplastics) to dynamically calculate the real-time lifespan and wear of the filter cartridge.

---

## 🚀 Live Simulation

You can test the device logic, interact with the sensors, and view the code execution directly in your browser using the interactive electronics simulator:

🔗 **[Launch HelioAqua Simulation on Wokwi](https://wokwi.com/projects/470075883990942721)**

---

## 🛠️ Hardware Architecture

The system is engineered using energy-efficient components optimized for ambient energy harvesting:

| Component | Purpose | Description |
| :--- | :--- | :--- |
| **ESP32 DevKit** | Main Controller | A low-power MCU with Wi-Fi/Bluetooth capabilities used to process sensor data and transmit IoT metrics. |
| **Solar Panel** | Power Source | Captures ambient light energy to sustain the device completely battery-free. |
| **Supercapacitor** | Energy Buffer | Stores harvested solar energy and handles ESP32 current spikes during active Wi-Fi transmission. |
| **TDS Sensor** | Hardness Analysis | Measures Total Dissolved Solids to track the mineral content and baseline filtration quality. |
| **Turbidity Sensor** | Pureness Analysis | An optical sensor used to detect suspended particles, sediment, and microplastics. |

---

## 📂 Project Structure

The repository is structured for seamless integration with the Wokwi simulation platform:

```text
HelioAqua/
├── .gitignore       # Git ignore rules for temporary and hidden files
├── LICENSE          # Open-source license (GPL-3.0)
├── README.md        # Project documentation
├── diagram.json     # Wokwi virtual hardware layout and wire connections
├── libraries.txt    # List of external Arduino libraries used in the project
└── sketch.ino       # Main Arduino source code containing firmware logic
```

---

## ⚙️ How to Run Locally (via Wokwi CLI or Arduino IDE)

1. Clone the repository:
   ```bash
   git clone https://github.com/loanelly/HelioAqua
   ```
2. Open the project folder in your preferred environment:
   * **Wokwi:** Install the Wokwi VS Code extension and start the project using `diagram.json`.
   * **Arduino IDE:** Rename `sketch.ino` to `HelioAqua.ino` inside a folder named `HelioAqua`, install the dependencies listed in `libraries.txt`, and upload to your ESP32 board.
---
<div align="center">
  <p>🛠️ <b><a href="https://github.com/LNL-Engineering">LNL-Engineering</a></b> — <i>Building secure architectures through physical entropy.</i></p>
  <p>📬 <b>Personal Profile:</b> <a href="https://github.com/loanelly">@loanelly</a></p>
</div>

