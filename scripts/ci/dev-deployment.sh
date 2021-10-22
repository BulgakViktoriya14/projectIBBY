#!/bin/bash

cd /home/develop/web/training.trysitedemo.com/public_html
git pull
cd web
../bin/drush cr
#../bin/drush cim -y
../bin/drush updb -y
