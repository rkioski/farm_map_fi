<?php
/**
 * @file
 * farm_map_fi.default_openlayers_sources.inc
 */

/**
 * Implements hook_default_openlayers_sources().
 */
function farm_map_fi_default_openlayers_sources() {
  $export = array();

  // Generate a Taustakartta source.
  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'farm_map_fi_source_taustakartta';
  $ol_source->name = 'Taustakartta';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => 'http://tiles.kartat.kapsi.fi/taustakartta/{z}/{x}/{y}.jpg',
  );
  $export['farm_map_fi_source_taustakartta'] = $ol_source;

  // Generate a Ortokuva source.
  $ol_source = new stdClass();
  $ol_source->disabled = FALSE; /* Edit this to true to make a default ol_source disabled initially */
  $ol_source->api_version = 1;
  $ol_source->machine_name = 'farm_map_fi_source_ortokuva';
  $ol_source->name = 'Ilmakuva';
  $ol_source->description = '';
  $ol_source->factory_service = 'openlayers.Source:XYZ';
  $ol_source->options = array(
    'url' => 'http://tiles.kartat.kapsi.fi/ortokuva/{z}/{x}/{y}.jpg',
  );
  $export['farm_map_fi_source_ortokuva'] = $ol_source;

  return $export;
}
