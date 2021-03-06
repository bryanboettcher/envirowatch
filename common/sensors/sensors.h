#include <Arduino.h>
#include "testing/test_sensors.h"
#include "bme280/bme280_sensors.h"

#ifndef DEFINED_SENSORS

#define MAX_SENSORS 16

typedef enum : uint8_t {
    NUMBER,             // just a raw number (uint16)
    TEMPERATURE,        // in centi-Kelvin
    HUMIDITY,           // 0 - 65535 = 0 - 100%
    PRESSURE,           // mmHg
    BATTERY,            // in 0.01V
    MEASURED_VOLTAGE,   // in 0.01V
    MEASURED_AMPERAGE,  // in 0.001A
    MASS,               // in 10 gram intervals
    BRIGHTNESS,         // unsure of unit                
    DISTANCE,           // in cm
    AIRSPEED,           // in cm/s
} value_type;

typedef uint16_t (*read_sensor)();

void enable_sensor(value_type, read_sensor);
uint8_t get_sensor_count();
value_type get_sensor_type(uint8_t);
uint16_t get_sensor_value(uint8_t);

#define DEFINED_SENSORS
#endif