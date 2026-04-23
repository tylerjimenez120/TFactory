// src/sensors/ISensor.h
#ifndef ISENSOR_H
#define ISENSOR_H

#include <string>

// Interfaz base: define EL QUÉ, no el CÓMO.
class ISensor {
   public:
    virtual ~ISensor() {}           // Destructor virtual esencial para polimorfismo
    virtual float readValue() = 0;  // Método virtual puro
    virtual std::string getSensorName() const = 0;
};

#endif