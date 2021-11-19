#include "routes.h"
#include "templates.h"


void render_index() {
    Serial.println("RESPONDING to /");
    server->send(200, "text/html", index_template);
};

void render_form() {
    Serial.println("RESPONDING to /form");
    server->send(200, "text/html", form_template);
}

void handle_post() {
    if (server->method() == HTTP_POST) {
        // Response is Arduino-String.
        String temp_1 = server->arg("plain");
        // Now to C string.
        const char *temp_2 = temp_1.c_str();
        // Now to std::string.
        std::string sdata = temp_2;

        // Okay, now we can do some parsing, let's goooooo.


    }
    else {
        // Redirect to /form.
        server->sendHeader("Location", "/form");
        server->send(302, "text/plain", "");
    }
}


void handle_not_found() {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server->uri();
    message += "\nMethod: ";
    message += (server->method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server->args();
    message += "\n";
    for (uint8_t i = 0; i < server->args(); i++) {
    message += " " + server->argName(i) + ": " + server->arg(i) + "\n";
    }

    server->send(404, "text/plain", message);
}