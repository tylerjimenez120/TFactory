# Lab: Hardware Abstraction using Factory Method Pattern

This repository demonstrates a professional implementation of the **Factory Method Design Pattern** in C++. The project focuses on decoupling high-level application logic from low-level hardware drivers, a critical practice in embedded systems engineering.

## 🎯 Project Overview

In embedded development (STM32/ESP32), software often needs to run on different hardware revisions or even be simulated on a PC for testing. This lab implements a **Sensor Abstraction Layer** that allows the system to switch between real hardware drivers and simulation mocks seamlessly.

### Key Features:
- **Factory Method Pattern:** Centralizes object creation logic.
- **Polymorphism:** Uses a common interface (`ISensor`) for diverse sensor implementations.
- **Memory Safety:** Implements `std::unique_ptr` for automatic resource management (RAII).
- **Unit Testing:** Integrated with GoogleTest to verify factory logic and polymorphic behavior.



## 🛠️ System Architecture

The project is divided into three main components:

1.  **The Interface (`ISensor`):** A pure virtual class that defines the contract for all sensors.
2.  **Concrete Products:**
    - `HardwareTempSensor`: Simulates interaction with MCU registers (e.g., ADC/I2C).
    - `MockTempSensor`: Provides randomized data for PC-based simulation and testing.
3.  **The Creator (`SensorFactory`):** A static factory that instantiates the appropriate sensor based on the system's operational mode (`REAL_HARDWARE` vs `SIMULATION`).



## 🚀 Building and Running

### Prerequisites
- CMake 3.16+
- C++11 compatible compiler
- GoogleTest (automatically fetched via CMake)

### Compilation
From the project root:
```bash
mkdir -p build && cd build
cmake ..
make



./src/cxx_app

./test/test_runner