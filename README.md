A nicely modularized webserver for the ESP8266.  I tried to make this as pythonic as possible, because sometimes C++ just sucks.

To add a basic route, simply:

1. Add a template (EG: templates/example_template.html).
2. Write all inline HTML/JS (I know, it kind of still sucks).
3. Run `parser.py`.
4. Add a function to `server->send()` your template in `routes.h`/`routes.cpp`.
5. Modify the `route_list` in the `startServer()` function inside of `utils.cpp` to assign it a path.
