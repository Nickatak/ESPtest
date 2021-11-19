#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "utils.h"


extern const String index_template = 
    "<!DOCTYPE html"
    "<html>"
    "   <head>"
    "       <title>Home page template!</title>"
    "   </head>"
    "   <body>"
    "       <p>\"Home page for the ESP8266\"</p>"
    "   </body>"
    "</html>";

extern const String form_template = 
    "<!DOCTYPE html"
    "<html>"
    "   <head>"
    "       <title>Form template!</title>"
    "   </head>"
    "   <body>"
    "       <form action=\"post_route\" method=\"post\">"
    "       <label>Input 1:</label><input type=\"text\" name=\"input_1\"></input><br>"
    "       <label>Input 2:</label><input type=\"text\" name=\"input_2\"></input><br>"
    "       <input type=\"submit\">Traditional send!</input>"
    "       <button id=\"test-js\">JS send!</input>"
    "       </form>"
    "   </body>"
    "</html>";

#endif
