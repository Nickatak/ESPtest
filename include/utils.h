#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <vector>

#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "LiquidCrystal_I2C.h"


#define STASSID "NETGEAR80"
#define STAPSK  "elatedcomet583"
#define HOSTNAME "esp8266"

extern ESP8266WebServer *server;
extern LiquidCrystal_I2C *lcd;
std::map<std::string, std::string> parse_body(std::string sbody);

void startWifi();
void startServer();
void startLCD();

struct route {
    String path;
    void (*fun_p)();
};

#endif
