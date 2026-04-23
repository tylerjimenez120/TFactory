#pragma once
#include <iostream>

#include "ISensor.h"

// Simulación de Sensor Real (Target: STM32/ESP32)
class HardwareTempSensor final : public ISensor {
   public:
    float readValue() override {
        // Aquí iría: return HAL_ADC_GetValue(&hadc1);
        std::cout << "[HAL] Leyendo registro ADC físico..." << std::endl;
        return 26.5f;
    }
    std::string getSensorName() const override {
        return "STM32_Internal_Temp";
    }
};

// Sensor de Simulación (Mock) para desarrollo en PC
class MockTempSensor final : public ISensor {
   public:
    float readValue() override {
        return 22.0f + (static_cast<float>(rand() % 50) / 10.0f);
    }
    std::string getSensorName() const override {
        return "PC_Mock_Simulator";
    }
};
