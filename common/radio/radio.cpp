#include "radio.h"

void init_radio(uint8_t pin) {
  vw_set_tx_pin(pin);
  vw_setup(2000); // bps
}

void transmit_data(packet * packets, uint8_t size) {

  for (uint8_t i = 0; i < size; i++) {
    uint8_t buffer[sizeof(packet)];
    memcpy(buffer, &packets[i], sizeof(packet));
    vw_send(buffer, sizeof(packet));
    vw_wait_tx();
    delay(50);
  }

}

uint8_t generate_checksum(packet p) {
  return 
    uint8_t(251) ^ 
    (p.version) ^
    (p.type) ^ 
    ((p.id & 0xFF) ^ ((p.value >> 8) & 0xFF)) ^
    ((p.value & 0xFF) ^ ((p.value >> 8) & 0xFF));
}