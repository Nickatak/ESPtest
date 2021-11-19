#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "utils.h"

extern const String form_template =
"<!DOCTYPE html>"
"<html>"
"    <head>"
"        <title>Form page</title>"
"    </head>"
"    <body>"
"        <form action=\"/post_route\" method=\"POST\">"
"            <label for=\"input_1\">Input 1:</label><input type=\"text\" name=\"input_1\"><br>"
"            <label for=\"input_1\">Input 1:</label><input type=\"text\" name=\"input_1\"><br>"
"            <button type=\"submit\">Send the normal way!</button>"
"            <button id=\"test-js\">Send with AJAX!</button>"
"        </form>"
"    </body>"
"</html>";
extern const String index_template =
"<!DOCTYPE html>"
"<html>"
"    <head>"
"        <title>ESP8266 Homepage</title>"
"    </head>"
"    <body>"
"        <h1>ESP8266 HOMEPAGE!</h1>"
"    </body>"
"</html>";
#endif