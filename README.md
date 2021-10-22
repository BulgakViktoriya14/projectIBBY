# drupal 8 template

TODO
1. Запускаем composer install
2. Заменить файл web/sites/default/settings.php  на  environments/settings.php
3. Копируем файл и меняем доступы к базе environments/examples/default.settings.php  в  environments/local/settings.php
4. В файле environments/local/settings.php в строке 27  заменить '^trysitedemo\.com' на '<sitename>.loc'
5. Чистим кеш (drush cr), по необходимости подтягиваем конфиги (drush cim)
6. Переходим в  web/themes/custom/subtheme -> npm install
7. Запускаем gulp
