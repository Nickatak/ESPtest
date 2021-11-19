#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "utils.h"

extern const String form_template =
"<!DOCTYPE html>"
"<html>"
"    <head>"
"        <title>Form page</title>"
"        <meta charset='utf-8'>"
"        <script>"
"            window.addEventListener(\"DOMContentLoaded\", () => {"
"                const button = document.getElementById(\"test-js\");"
""
"                button.addEventListener(\"click\", (evt) => {"
"                    evt.preventDefault();"
""
"                    let data = {"
"                        \"input_1\": evt.target.parentNode.querySelector(\"input[name='input_1'\").value,"
"                        \"input_2\": evt.target.parentNode.querySelector(\"input[name='input_2'\").value,"
"                    };"
""
"                    data = Object.keys(data).map((key) => {"
"                        return `${key}=${data[key]}`;"
"                    }).join('&');"
""
"                    fetch(\"/post_route\", {"
"                        \"method\": \"POST\","
"                        \"headers\": {"
"                            \"Content-Type\": \"application/x-www-form-urlencoded;charset=UTF-8\""
"                        },"
"                        \"body\": data"
"                    })"
"                });"
"            });"
"        </script>"
"    </head>"
"    <body>"
"        <form action=\"/post_route\" method=\"POST\">"
"            <label for=\"input_1\">Input 1:</label><input type=\"text\" name=\"input_1\"><br>"
"            <label for=\"input_2\">Input 2:</label><input type=\"text\" name=\"input_2\"><br>"
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
"        <meta charset='utf-8'>"
"    </head>"
"    <body>"
"        <h1>ESP8266 HOMEPAGE!</h1>"
"    </body>"
"</html>";
#endif