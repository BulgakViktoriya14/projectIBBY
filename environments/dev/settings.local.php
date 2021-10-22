<?php

/**
 * @file
 * Drupal environment-specific configuration file.
 */

error_reporting(E_ALL);
ini_set('display_errors', TRUE);
ini_set('display_startup_errors', TRUE);

/**
 * Show all error messages, with backtrace information.
 *
 * In case the error level could not be fetched from the database, as for
 * example the database connection failed, we rely only on this value.
 */
$config['system.logging']['error_level'] = 'verbose';

/**
 * Enable config split for current environment.
 */
$config['config_split.config_split.dev']['status'] = TRUE;