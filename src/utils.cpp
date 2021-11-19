#include "utils.h"
#include "routes.h"


ESP8266WebServer *server = new ESP8266WebServer(80);

void startWifi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(STASSID, STAPSK);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.print("Connected to ");
    Serial.println(STASSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("esp8266")) {
        Serial.print("MDNS responder started with hostname:");
        Serial.print(HOSTNAME);
        Serial.println(".local");
    }
};

void startServer() {
    std::vector<route> route_list {
        route{ "/", &handle_index }
    };

    for (auto route_obj : route_list) {
        server->on(route_obj.path, *route_obj.fun_p);
    };

    // Setup not found handler.
    server->onNotFound(handle_not_found);

    server->begin();
    Serial.println("HTTP server started");
};