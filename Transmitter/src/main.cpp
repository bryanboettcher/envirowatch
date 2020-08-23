#define RADIO_PIN 3
#ifndef RADIO_ID
  #error RADIO_ID did not get passed via build scripts
#endif

#include <Arduino.h>
#include <powernap.h>

#include "sensors.h"
#include "radio.h"

Napper napper;

void gather_data(packet * packets, uint8_t &size) {
  for (uint8_t i = 0; i < get_sensor_count(); i++) {
    packets[i].version = 1;
    packets[i].id = RADIO_ID;
    packets[i].type = get_sensor_type(i);
    packets[i].value = get_sensor_value(i);
  }

  size = get_sensor_count();
}

void setup() 
{
  init_radio(RADIO_PIN);
  enable_sensor(TEMPERATURE, &bme280_t);
  enable_sensor(PRESSURE, &bme280_p);
}

void loop()
{ 
  struct packet sensor_data[MAX_SENSORS];
  uint8_t size = MAX_SENSORS;
  gather_data(sensor_data, size);
  transmit_data(sensor_data, size);
  napper.napminutes(1);
}