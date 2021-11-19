"""Utility script to convert your templates into a C++-friendly header file.

The file name of your template will dictate the name in the header.  So this means don't use spaces or anything weird.
    EG: test_template.html => extern const test_template = ...
"""
import os


templates = os.listdir("templates")
raw_output = """\
#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "utils.h"

"""

for template in templates:
    filename = template.split('.')[0]
    raw_extern = [f"extern const String {filename} ="]
    with open(os.path.join('templates', template)) as fo:
        data = fo.readlines()

    raw_extern += ['"' + line.replace('"', '\\"').rstrip() + '"' for line in data]

    raw_output += '\n'.join(raw_extern) + ";\n"    
raw_output += "#endif"

with open(os.path.join('include', 'templates.h'), "w") as fo:
    fo.write(raw_output)
