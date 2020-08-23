#include "radio.h"

void init_radio(uint8_t pin) {
  vw_set_tx_pin(pin);
  vw_setup(2000); // bps
}

void transmit_data(packet * packets, uint8_t size) {

  while(size --> 0) {
    uint8_t buffer[sizeof(packet)];
    memcpy(buffer, &packets[size], sizeof(packet));
    vw_send(buffer, sizeof(packet));
    vw_wait_tx();
    delay(50);
  }

}