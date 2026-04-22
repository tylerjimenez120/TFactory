// src/main.cpp
#include <iostream>
#include <vector>

#include "sensors/SensorFactory.h"

int main() {
    std::cout << "=== LAB FACTORY METHOD: HARDWARE ABSTRACTION ===" << std::endl;

    // Cambia esto a Mode::REAL_HARDWARE cuando subas el código al chip
    Mode currentMode = Mode::SIMULATION;

    // La fábrica nos entrega el sensor adecuado
    std::unique_ptr<ISensor> mySensor = SensorFactory::createTemperatureSensor(currentMode);

    if (mySensor) {
        std::cout << "Sensor activo: " << mySensor->getSensorName() << std::endl;
        std::cout << "Lectura: " << mySensor->readValue() << " C" << std::endl;
    }

    return 0;
}