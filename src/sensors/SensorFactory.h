// src/sensors/SensorFactory.h
#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include <memory>

#include "TempSensors.h"

enum class Mode { REAL_HARDWARE, SIMULATION };

class SensorFactory {
   public:
    static std::unique_ptr<ISensor> createTemperatureSensor(Mode mode) {
        if (mode == Mode::REAL_HARDWARE) {
            return std::make_unique<HardwareTempSensor>();
        } else {
            return std::make_unique<MockTempSensor>();
        }
    }
};

#endif