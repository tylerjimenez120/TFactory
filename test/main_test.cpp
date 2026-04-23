#include <gtest/gtest.h>
#include <sensors/SensorFactory.h>

/**
 * @brief Verifica que la fábrica cree el sensor de simulación correctamente
 */
TEST(SensorFactoryTest, CreateMockSensor) {
    auto sensor = SensorFactory::createTemperatureSensor(Mode::SIMULATION);

    ASSERT_NE(sensor, nullptr);  // No debe ser nulo
    EXPECT_EQ(sensor->getSensorName(), "PC_Mock_Simulator");
}

/**
 * @brief Verifica que la fábrica cree el sensor de hardware correctamente
 */
TEST(SensorFactoryTest, CreateHardwareSensor) {
    auto sensor = SensorFactory::createTemperatureSensor(Mode::REAL_HARDWARE);

    ASSERT_NE(sensor, nullptr);
    EXPECT_EQ(sensor->getSensorName(), "STM32_Internal_Temp");
}

/**
 * @brief Verifica el polimorfismo: diferentes clases, misma interfaz
 */
TEST(SensorFactoryTest, PolymorphismCheck) {
    auto s1 = SensorFactory::createTemperatureSensor(Mode::SIMULATION);
    auto s2 = SensorFactory::createTemperatureSensor(Mode::REAL_HARDWARE);

    // Ambos son ISensor*, pero sus valores y comportamientos son distintos
    EXPECT_NE(s1->getSensorName(), s2->getSensorName());
}