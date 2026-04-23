#pragma once  // Sugerencia del profe
#include <string>

class ISensor {
   public:
    ISensor() = default;
    virtual ~ISensor() = default;

    // Regla de los 5: Evitamos copias accidentales en interfaces de hardware
    // ❌ Constructor de copia: evita crear un sensor copiando otro (no duplicar hardware)
    ISensor(const ISensor&) = delete;

    // ❌ Asignación por copia: evita copiar datos de un sensor a otro existente
    ISensor& operator=(const ISensor&) = delete;

    // ✔ Constructor de movimiento: permite transferir el recurso (sensor) a un nuevo objeto
    ISensor(ISensor&&) = default;

    // ✔ Asignación por movimiento: permite transferir el recurso a un objeto ya existente
    ISensor& operator=(ISensor&&) = default;

    virtual float readValue() = 0;
    virtual std::string getSensorName() const = 0;
};