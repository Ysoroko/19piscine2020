#!/bin/sh

cat /etc/passwd | grep -Fv '#' | awk -F: '{print $1}' | awk 'NR ==2||NR%2==0'|rev|sort -r |sed -n -e "$FT_LINE1","$FT_LINE2"p|sed 's/$/,/g'|tr '\n' '\ '|rev | cut -c 3- | rev | tr '\n' '.'

