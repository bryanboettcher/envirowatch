#include "sensors.h"

uint8_t SENSOR_COUNT = 0;
value_type configured_sensor_types[MAX_SENSORS];
read_sensor configured_sensor_callbacks[MAX_SENSORS];

void enable_sensor(value_type type, read_sensor cb) {
    if (SENSOR_COUNT == MAX_SENSORS) return;

    configured_sensor_types    [SENSOR_COUNT] = type;
    configured_sensor_callbacks[SENSOR_COUNT] = cb;

    SENSOR_COUNT++;
}

uint8_t get_sensor_count() {
  return SENSOR_COUNT;
}

value_type get_sensor_type(uint8_t index) {
    return configured_sensor_types[index];
}

uint16_t get_sensor_value(uint8_t index) {
    return configured_sensor_callbacks[index]();
}