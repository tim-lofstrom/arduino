#include <EEPROM.h>
#include <SPI.h>
#include <Ethernet.h>
#include <NetEEPROM.h>

/* Stores network configuration of a MAC address and manual IP setup
 * to EEPROM.
 */
void setup() {
  byte mac[6] = { 0xCA, 0xFE, 0xBA, 0xBE, 0xAC, 0xCD };
  byte ip[4] = { 10, 8, 1, 197 };
  byte dns[4] = { 192, 168, 100, 7 };
  byte gw[4] = { 10, 8, 1, 1 };
  byte subnet[4] = { 255, 255, 255, 0 };

  NetEeprom.writeManualConfig(mac, ip, dns, gw, subnet);
}

void loop() {
}
