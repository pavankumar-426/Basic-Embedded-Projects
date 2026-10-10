# Basic-Embedded-Projects
# ⚡ Embedded Systems & Microcontroller Project Portfolio

A consolidated repository featuring the **ElectroSentinel.X** major project alongside fundamental microcontroller peripheral interfacing modules—including LED patterns, 7-Segment displays, and keypad scanning.

---

## 📑 Table of Contents
1. [Major Project: ElectroSentinel.X](#-major-project-electrosentinelx)
2. [Module 1: LED Blinking & Patterns](#-module-1-led-blinking--patterns)
3. [Module 2: 7-Segment Display Interfacing](#-module-2-7-segment-display-interfacing)
4. [Module 3: Keypad & Switch Interfacing](#-module-3-keypad--switch-interfacing)
5. [Repository Structure](#-repository-structure)
6. [Toolchain & Software Requirements](#-toolchain--software-requirements)
7. [Getting Started & Simulation](#-getting-started--simulation)
8. [License](#-license)

---

## 🛡️ Major Project: ElectroSentinel.X

### Overview
**ElectroSentinel.X** is an embedded sentinel system engineered for real-time electronic parameter supervision, fault detection, and automated fail-safe protection. It continuously tracks critical metrics (voltage, current, and temperature), triggers rapid relay cutoff during threshold violations, and reports operational telemetry via a local display.

### Key Capabilities
- **Real-Time Sensor Acquisition:** Continuous sampling of analog and digital inputs (voltage divider, current sensor, temperature sensor).
- **Automated Protection:** Low-latency cutoff routines to isolate downstream circuitry during overcurrent, overvoltage, or thermal faults.
- **Diagnostics & Status:** Real-time state readouts on an LCD/OLED display with acoustic buzzer and LED warning indicators.
- **Deterministic Firmware:** Bare-metal modular Embedded C architecture designed for predictable timing and safety.

### Hardware Architecture
* **Target Controller:** Microchip PIC / AVR / STM32
* **Current Sensor:** ACS712 module
* **Voltage Sensing:** Calibrated voltage divider network
* **Temperature Sensor:** LM35 / DS18B20
* **Display Interface:** 16x2 I2C / 4-bit Parallel LCD
* **Actuators:** 5V Relay module, Piezo buzzer, Warning indicator LEDs

---

## 💡 Module 1: LED Blinking & Patterns

### Objectives
- Configure General Purpose Input/Output (GPIO) registers (`TRIS` / `PORT` / `LAT` / `DDR`).
- Implement accurate software delay routines and hardware timer delays.
- Control active-high and active-low discrete components.

### Routines Implemented
1. **Basic Blink:** Simple alternating toggling on single I/O pins.
2. **8-Bit Running Chaser:** Bitwise shifting (`<<` and `>>`) across an 8-LED array.
3. **Binary Counter:** Displaying an unsigned 8-bit integer incrementing from `0x00` to `0xFF`.
4. **Ring & Alternating Patterns:** Odd/even LED flashing and convergence/divergence patterns.

---

## 🔢 Module 2: 7-Segment Display Interfacing

### Objectives
- Decode Binary Coded Decimal (BCD) values into 7-segment display logic using Look-Up Tables (LUT).
- Handle Common Cathode (CC) and Common Anode (CA) pin configurations.
- Implement Time-Division Multiplexing to drive multi-digit displays using minimal I/O pins.

### Segment Look-Up Table (Common Cathode: g-f-e-d-c-b-a)├── ElectroSentinel.X/                  # Major Project
│   ├── firmware/
│   │   ├── inc/                       # Header files (adc.h, lcd.h, protection.h)
│   │   └── src/                       # Driver implementations & main.c
│   ├── hardware/                      # Schematics, pinouts, and BOM
│   ├── simulation/                    # Proteus design file (.pdsprj)
│   └── docs/                          # System flowcharts & architecture docs
│
├── 01_LED_Patterns/                   # LED fundamentals
│   ├── firmware/main.c
│   └── simulation/led_circuit.pdsprj
│
├── 02_7Segment_Display/               # Single & Multiplexed displays
│   ├── firmware/seven_seg.c
│   └── simulation/seven_seg.pdsprj
│
├── 03_Keypad_and_Buttons/             # Switch debouncing & 4x4 matrix scanning
│   ├── firmware/keypad.c
│   └── simulation/keypad.pdsprj
│
└── README.md                          # Repository overview documentation
```c
const unsigned char SEG_LUT[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
├── ElectroSentinel.X/                  # Major Project
│   ├── firmware/
│   │   ├── inc/                       # Header files (adc.h, lcd.h, protection.h)
│   │   └── src/                       # Driver implementations & main.c
│   ├── hardware/                      # Schematics, pinouts, and BOM
│   ├── simulation/                    # Proteus design file (.pdsprj)
│   └── docs/                          # System flowcharts & architecture docs
│
├── 01_LED_Patterns/                   # LED fundamentals
│   ├── firmware/main.c
│   └── simulation/led_circuit.pdsprj
│
├── 02_7Segment_Display/               # Single & Multiplexed displays
│   ├── firmware/seven_seg.c
│   └── simulation/seven_seg.pdsprj
│
├── 03_Keypad_and_Buttons/             # Switch debouncing & 4x4 matrix scanning
│   ├── firmware/keypad.c
│   └── simulation/keypad.pdsprj
│
└── README.md                          # Repository overview documentation

git clone [https://github.com/](https://github.com/)<your-username>/<your-repo-name>.git
cd <your-repo-name>
