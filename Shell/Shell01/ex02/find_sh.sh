#/bin/sh

basename $(find . -name "*.sh" -type f) |  sed 's/\(.*\)\..*/\1/'
