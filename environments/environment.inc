<?php

/**
 * @file
 * Set environment indicator.
 */

// Default environment.
$environment = 'local';

// Acquia.
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  $environment = $_SERVER['ENVIRONMENT_INDICATOR'];
}
// Pantheon.
elseif (isset($_ENV['PANTHEON_ENVIRONMENT'])) {
  $environment = $_ENV['PANTHEON_ENVIRONMENT'];
}
// Custom server variable.
elseif (getenv('INSTANCE_ENV')) {
  $environment = getenv('INSTANCE_ENV');
}
else {
  switch (gethostname()) {
    // Replace with nessesary host names.
    case 'web1':
      $environment = 'prod';
      break;

    case 'web2':
      $environment = 'stage';
      break;

    case 'trysitedemo.com':
    case 'web3':
      $environment = 'dev';
      break;

    default:
      $environment = 'local';
      break;
  }
}

// Environment indicator settings.
switch ($environment) {
  case 'local':
    $config['environment_indicator.indicator']['name'] = 'LOCAL';
    $config['environment_indicator.indicator']['bg_color'] = '#737373';
    $config['environment_indicator.indicator']['fg_color'] = '#ffffff';
    break;

  case 'dev':
  case 'develop':
    $config['environment_indicator.indicator']['name'] = 'DEV';
    $config['environment_indicator.indicator']['bg_color'] = '#00802b';
    $config['environment_indicator.indicator']['fg_color'] = '#ffffff';
    break;

  case 'test':
  case 'sta':
  case 'stage':
  case 'preprod':
    $config['environment_indicator.indicator']['name'] = 'STAGE';
    $config['environment_indicator.indicator']['bg_color'] = '#ffff00';
    $config['environment_indicator.indicator']['fg_color'] = '#ffffff';
    break;

  case 'live':
  case 'prod':
    $config['environment_indicator.indicator']['name'] = 'PROD';
    $config['environment_indicator.indicator']['bg_color'] = '#ff0000';
    $config['environment_indicator.indicator']['fg_color'] = '#ffffff';
    break;
}
