#include "utils.h"
#include "routes.h"


ESP8266WebServer *server = new ESP8266WebServer(80);
LiquidCrystal_I2C *lcd = new LiquidCrystal_I2C(0x27, 16, 2);

std::map<std::string, std::string> parse_body(std::string sbody) {
    // Splits "blah1=val1&blah2=val2" => ["blah1=val1", "blah2=val2"]
    std::vector<std::string> pairs;
    size_t pos = 0;
    while ( (pos = sbody.find("&")) != std::string::npos ) {
        pairs.push_back(sbody.substr(0, pos));

        sbody.erase(0, pos + 1);
    }
    pairs.push_back(sbody);

    // Now we need to make the map of {"blah1":"val1", "blah2": "val2"}.
    std::map<std::string, std::string> data;

    for (std::vector<std::string>::iterator pair = pairs.begin(); pair != pairs.end(); pair++) {
        data.insert(
            std::pair(pair->substr(0, pair->find("=")), pair->substr(pair->find("=") + 1))
        );
    };

    return data;
};

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
        route{ "/", &render_index },
        route{ "/form", &render_form },
        route{ "/post_route", &handle_post }
    };

    for (auto route_obj : route_list) {
        server->on(route_obj.path, *route_obj.fun_p);
    };

    // Setup not found handler.
    server->onNotFound(handle_not_found);

    server->begin();
    Serial.println("HTTP server started");
};

void startLCD() {
    lcd->init();
    lcd->clear();
    lcd->backlight();
    lcd->setCursor(0, 0);
}