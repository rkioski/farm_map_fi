<?php
/**
 * @file
 * farm_map_fi.default_openlayers_layers.inc
 */

/**
 * Implements hook_default_openlayers_layers().
 */
function farm_map_fi_default_openlayers_layers() {
  $export = array();

  // Taustakartta layer
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE;
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'farm_map_fi_layer_taustakartta';
  $ol_layer->name = 'Taustakartta';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'farm_map_fi_source_taustakartta',
    'visible' => 0,
  );
  $export['farm_map_fi_layer_taustakartta'] = $ol_layer;

  // Ortokuva layer
  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE;
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'farm_map_fi_layer_ortokuva';
  $ol_layer->name = 'Ilmakuva';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.Layer:Tile';
  $ol_layer->options = array(
    'source' => 'farm_map_fi_source_ortokuva',
    'visible' => 0,
  );
  $export['farm_map_fi_layer_ortokuva'] = $ol_layer;

  return $export;
}

/**
 * Implements hook_default_openlayers_layers_alter().
 */
function farm_map_fi_default_openlayers_layers_alter(&$layers) {

  // Add Kartverket layers to farm_map_layer_group.
  if (!empty($layers['farm_map_layer_group'])) {

    // Create a list of Openlayers layer names.
    $ol_layers = array();

    // Add the layers
    $ol_layers[] = 'farm_map_fi_layer_taustakartta';
    $ol_layers[] = 'farm_map_fi_layer_ortokuva';

    // Merge into existing layers.
    $existing_layers = $layers['farm_map_layer_group']->options['grouplayers'];
    $layers['farm_map_layer_group']->options['grouplayers'] = array_merge($ol_layers, $existing_layers);
  }
}

