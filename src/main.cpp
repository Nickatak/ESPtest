#include <Arduino.h>
#include "utils.h"

void setup(void) {
  Serial.begin(115200);
  // This is a blocking call and may hang indefinitely.
  startWifi();
  startServer();
};

void loop(void) {
  server->handleClient();
  MDNS.update();
};