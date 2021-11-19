#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "utils.h"

extern const String index_template = 
    "<!DOCTYPE html"
    "<html>"
    "   <head>"
    "       <title>Testing template!</title>"
    "   </head>"
    "   <body>"
    "       <p>\"hello from esp8266!\"</p>"
    "   </body>"
    "</html>";

extern const String form_template = 
    "<!DOCTYPE html"
    "<html>"
    "   <head>"
    "       <title>Testing template!</title>"
    "   </head>"
    "   <body>"
    "       <form action=\"post_route\" method=\"post\">"
    "       <label>Input 1:</label><input type=\"text\" name=\"input_1\"></input><br>"
    "       <label>Input 2:</label><input type=\"text\" name=\"input_2\"></input><br>"
    "       "
    "       </form>"
    "   </body>"
    "</html>";

#endif
