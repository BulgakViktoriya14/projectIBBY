#!/bin/sh

find ./web/modules/custom/ ./web/themes/custom/ ./web/profiles/custom/ -type f -regex '\(.*.module\|.*.inc\|.*.install\|.*.php\|.*.theme\|.*.profile\)' -exec php -l -d display_errors=1 {} \; | grep -i "Parse.error"
if [ $? -eq 0 ]
then
  exit 1
else
  echo "No parsing errors"
  exit 0
fi