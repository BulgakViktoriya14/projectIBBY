<?php

/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

use Drupal\Core\Render\Markup;
use Drupal\Component\Render\MarkupInterface;

/**
 * Implements hook_install_tasks().
 */
function kickstart_install_tasks() {
  $tasks = [];
  $tasks['kickstart_set_front_page'] = [];
  $tasks['kickstart_set_default_theme'] = [];

  return $tasks;
}

/**
 * Sets the front page path to /node.
 */
function kickstart_set_front_page() {
  if (Drupal::moduleHandler()->moduleExists('node')) {
    Drupal::configFactory()
      ->getEditable('system.site')
      ->set('page.front', '/node')
      ->save(TRUE);
  }
}

/**
 * Sets the default and administration themes.
 */
function kickstart_set_default_theme() {
  Drupal::configFactory()
    ->getEditable('system.theme')
    ->set('default', 'bootstrap_barrio')
    ->set('admin', 'seven')
    ->save(TRUE);

  // Use the admin theme for creating content.
  if (Drupal::moduleHandler()->moduleExists('node')) {
    Drupal::configFactory()
      ->getEditable('node.settings')
      ->set('use_admin_theme', TRUE)
      ->save(TRUE);
  }
}

/**
 * Implements hook_page_attachments_alter().
 */
function kickstart_page_attachments_alter(array &$attachments) {
  foreach ($attachments['#attached']['html_head'] as $key => $attachment) {
    if ($attachment[1] == 'system_meta_generator') {
      unset($attachments['#attached']['html_head'][$key]);
    }
  }
}

/**
 * Implements hook_mail_alter().
 */
function kickstart_extras_mail_alter(&$message) {
  $message['body'] = array_map(function ($body) {
    if (strlen(strip_tags($body)) === strlen($body)) {
      $body = str_replace("\n", '<br>', $body);
    }
    return $body instanceof MarkupInterface ? $body : Markup::create($body);
  }, $message['body']);

  $message['headers']['Content-Type'] = SWIFTMAILER_FORMAT_HTML;
}
