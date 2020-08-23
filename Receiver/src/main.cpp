#include <Arduino.h>
#include <VirtualWire.h>              //Download it here: http://electronoobs.com/eng_arduino_virtualWire.php

enum value_type {
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
};

struct packet {
  uint8_t version;
  uint16_t id;
  uint16_t value;
  value_type type;
  uint8_t checksum;
};

uint8_t message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages

int received_number = 0;
int LED = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Ready...");
  vw_set_rx_pin(3); // pin
  vw_setup(2000); // bps
  vw_rx_start();
}

void loop()
{
  uint8_t size = VW_MAX_MESSAGE_LEN;


  if (vw_get_message(message, &size)) // non-blocking
  {
    Serial.println("Packet received: ");
    
    packet data;
    memcpy(&data, message, size);
    Serial.print("  ID:    ");
    Serial.println(data.id);
    Serial.print("  Value: ");
    Serial.println(data.value);
  }
}