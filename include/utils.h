#ifndef UTILS_H
#define UTILS_H

#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <vector>
#include <string>

#define STASSID "NETGEAR80"
#define STAPSK  "elatedcomet583"
#define HOSTNAME "esp8266"

extern ESP8266WebServer *server;

extern std::vector<std::string> string_list;


void startWifi();
void startServer();

struct route {
    String path;
    void (*fun_p)();
};

#endif
