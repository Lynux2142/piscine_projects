#! /bin/sh

find . -name "*.sh" -print | rev | cut -d '/' -f1 | cut -d '.' -f2- | rev
