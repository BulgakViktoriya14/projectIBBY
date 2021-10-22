<?php

/**
 * @file
 * General environment settings.
 */

/**
 * Database settings.
 */
$databases = array();

/**
 * Site configuration files.
 */
$config_directories[CONFIG_SYNC_DIRECTORY] = '../config/sync';

/**
 * Salt.
 */
// TODO:SET SALT.
$settings['hash_salt'] = 'A6d8uPcxoNAOJVOBVtL-6j46UaHq52EQOWCQvGkNuf6dM8dnIl0LyDyKp1HwLCkETXA-T693fw';

/**
 * Control for update.php.
 */
$settings['update_free_access'] = FALSE;

/**
 * Common services definition file.
 */
$settings['container_yamls'][] = __DIR__ . '/services.yml';

/**
 * Environment detect and indicator.
 */
include __DIR__ . "/environment.inc";

/**
 * Environment specific settings.
 */
include __DIR__ . "/$environment/settings.php";
