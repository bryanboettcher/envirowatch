#include <Arduino.h>
#include <VirtualWire.h>

#include "sensors.h"

#ifndef DEFINED_RADIO

struct packet {
  uint8_t version:8;
  uint16_t id;
  uint16_t value;
  value_type type;
  uint8_t checksum;
};

void init_radio(uint8_t);
void transmit_data(packet *, uint8_t);
uint8_t generate_checksum(packet);

#define DEFINED_RADIO
#endif