<?php
/**
 * @file
 * caw_search_api_settings.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function caw_search_api_settings_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'caw_search_api_facets';
  $context->description = 'Places facets on the search api views pages';
  $context->tag = 'Search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search/content*' => 'search/content*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-search-page-title' => array(
          'module' => 'bean',
          'delta' => 'search-page-title',
          'region' => 'main_upper',
          'weight' => '-10',
        ),
        'views--exp-gotosolr_nodes-page' => array(
          'module' => 'views',
          'delta' => '-exp-gotosolr_nodes-page',
          'region' => 'main_upper',
          'weight' => '-9',
        ),
        'stanford_search_api-search_api_reset_facets_block' => array(
          'module' => 'stanford_search_api',
          'delta' => 'search_api_reset_facets_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'facetapi-f7rOKrqvTeKMW42ERkYqIEKDdovo0pvH' => array(
          'module' => 'facetapi',
          'delta' => 'f7rOKrqvTeKMW42ERkYqIEKDdovo0pvH',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'facetapi-DcmaYZHSG0i1RJfKqK00HaWsm7s7yFsw' => array(
          'module' => 'facetapi',
          'delta' => 'DcmaYZHSG0i1RJfKqK00HaWsm7s7yFsw',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'facetapi-WWIx05pCImpa8Doygcwuhr8NW0iRRbRT' => array(
          'module' => 'facetapi',
          'delta' => 'WWIx05pCImpa8Doygcwuhr8NW0iRRbRT',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places facets on the search api views pages');
  t('Search');
  $export['caw_search_api_facets'] = $context;

  return $export;
}
