<?php
/**
 * @file
 * caw_search_api_settings.features.inc
 */

/**
 * Implements hook_block_class_features_default_class().
 */
function caw_search_api_settings_block_class_features_default_class() {
  return array(
    'views:-exp-gotosolr_nodes-page' => array(
      'module' => 'views',
      'delta' => '-exp-gotosolr_nodes-page',
      'css_classes' => 'well',
    ),
  );
}

/**
 * Implements hook_ctools_plugin_api().
 */
function caw_search_api_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function caw_search_api_settings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function caw_search_api_settings_default_search_api_index() {
  $items = array();
  $items['allthenodes'] = entity_import('search_api_index', '{
    "name" : "AllTheNodes",
    "machine_name" : "allthenodes",
    "description" : "Index all nodes",
    "server" : "gotosolr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "500",
      "fields" : {
        "body:summary" : { "type" : "text", "boost" : "5.0" },
        "body:value" : { "type" : "text", "boost" : "3.0" },
        "field_landing_page_item:field_s_image_credits" : { "type" : "list\\u003Ctext\\u003E" },
        "field_landing_page_item:field_s_lp_item_description:value" : { "type" : "list\\u003Ctext\\u003E" },
        "field_landing_page_item:field_s_lp_item_link:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_landing_page_item:field_s_lp_item_link:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_landing_page_item:field_s_lp_item_title" : { "type" : "list\\u003Ctext\\u003E", "boost" : "3.0" },
        "field_related_content" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_related_content:description" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_related_content:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "field_s_event_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_s_landing_page_lead_text" : { "type" : "text" },
        "field_s_news_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_s_news_date" : { "type" : "date" },
        "field_s_program_service_subtitle" : { "type" : "text" },
        "field_s_resource_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_s_subsites" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stanford_event_categories:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_stanford_event_categories:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_stanford_event_email" : { "type" : "text", "boost" : "0.3" },
        "field_stanford_event_location" : { "type" : "text" },
        "field_stanford_event_sponsor" : { "type" : "text" },
        "field_stanford_subsite_sub_tags" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_stanford_subsite_sub_tags:description" : { "type" : "text" },
        "field_stanford_subsite_sub_tags:name" : { "type" : "text" },
        "field_tags:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "title" : { "type" : "text", "boost" : "0.8" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "vid" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : {
              "article" : "article",
              "page" : "page",
              "stanford_help_page" : "stanford_help_page",
              "stanford_event_importer" : "stanford_event_importer"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "field_stanford_event_email" : true,
              "field_stanford_event_location" : true,
              "field_stanford_event_sponsor" : true,
              "field_s_landing_page_lead_text" : true,
              "field_s_program_service_subtitle" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true,
              "field_tags:description" : true,
              "field_stanford_event_categories:name" : true,
              "field_stanford_event_categories:description" : true,
              "field_related_content:name" : true,
              "field_related_content:description" : true,
              "field_stanford_subsite_sub_tags:name" : true,
              "field_stanford_subsite_sub_tags:description" : true,
              "field_landing_page_item:field_s_image_credits" : true,
              "field_landing_page_item:field_s_lp_item_title" : true,
              "field_landing_page_item:field_s_lp_item_description:value" : true,
              "field_landing_page_item:field_s_lp_item_link:title" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_stanford_event_email" : true,
              "field_stanford_event_location" : true,
              "field_stanford_event_sponsor" : true,
              "field_s_landing_page_lead_text" : true,
              "field_s_program_service_subtitle" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true,
              "field_tags:description" : true,
              "field_stanford_event_categories:name" : true,
              "field_stanford_event_categories:description" : true,
              "field_related_content:name" : true,
              "field_related_content:description" : true,
              "field_stanford_subsite_sub_tags:name" : true,
              "field_stanford_subsite_sub_tags:description" : true,
              "field_landing_page_item:field_s_image_credits" : true,
              "field_landing_page_item:field_s_lp_item_title" : true,
              "field_landing_page_item:field_s_lp_item_description:value" : true,
              "field_landing_page_item:field_s_lp_item_link:title" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "title" : true,
              "field_stanford_event_email" : true,
              "field_stanford_event_location" : true,
              "field_stanford_event_sponsor" : true,
              "field_s_landing_page_lead_text" : true,
              "field_s_program_service_subtitle" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true,
              "field_tags:description" : true,
              "field_stanford_event_categories:name" : true,
              "field_stanford_event_categories:description" : true,
              "field_related_content:name" : true,
              "field_related_content:description" : true,
              "field_stanford_subsite_sub_tags:name" : true,
              "field_stanford_subsite_sub_tags:description" : true,
              "field_landing_page_item:field_s_image_credits" : true,
              "field_landing_page_item:field_s_lp_item_title" : true,
              "field_landing_page_item:field_s_lp_item_description:value" : true,
              "field_landing_page_item:field_s_lp_item_link:title" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_stanford_event_email" : true,
              "field_stanford_event_location" : true,
              "field_stanford_event_sponsor" : true,
              "field_s_landing_page_lead_text" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true,
              "field_tags:description" : true,
              "field_stanford_event_categories:name" : true,
              "field_stanford_event_categories:description" : true,
              "field_related_content:name" : true,
              "field_related_content:description" : true,
              "field_stanford_subsite_sub_tags:name" : true,
              "field_stanford_subsite_sub_tags:description" : true,
              "field_landing_page_item:field_s_image_credits" : true,
              "field_landing_page_item:field_s_lp_item_title" : true,
              "field_landing_page_item:field_s_lp_item_description:value" : true,
              "field_landing_page_item:field_s_lp_item_link:title" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_s_landing_page_lead_text" : true,
              "field_s_program_service_subtitle" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_tags:name" : true,
              "field_tags:description" : true,
              "field_stanford_event_categories:name" : true,
              "field_stanford_event_categories:description" : true,
              "field_related_content:name" : true,
              "field_related_content:description" : true,
              "field_stanford_subsite_sub_tags:name" : true,
              "field_stanford_subsite_sub_tags:description" : true,
              "field_landing_page_item:field_s_image_credits" : true,
              "field_landing_page_item:field_s_lp_item_title" : true,
              "field_landing_page_item:field_s_lp_item_description:value" : true,
              "field_landing_page_item:field_s_lp_item_link:title" : true
            },
            "file" : "",
            "stopwords" : "a\\r\\nabout\\r\\nabove\\r\\nafter\\r\\nagain\\r\\nagainst\\r\\nall\\r\\nam\\r\\nan\\r\\nand\\r\\nany\\r\\nare\\r\\naren\\u0027t\\r\\nas\\r\\nat\\r\\nbe\\r\\nbecause\\r\\nbeen\\r\\nbefore\\r\\nbeing\\r\\nbelow\\r\\nbetween\\r\\nboth\\r\\nbut\\r\\nby\\r\\ncan\\u0027t\\r\\ncannot\\r\\ncould\\r\\ncouldn\\u0027t\\r\\ndid\\r\\ndidn\\u0027t\\r\\ndo\\r\\ndoes\\r\\ndoesn\\u0027t\\r\\ndoing\\r\\ndon\\u0027t\\r\\ndown\\r\\nduring\\r\\neach\\r\\nfew\\r\\nfor\\r\\nfrom\\r\\nfurther\\r\\nhad\\r\\nhadn\\u0027t\\r\\nhas\\r\\nhasn\\u0027t\\r\\nhave\\r\\nhaven\\u0027t\\r\\nhaving\\r\\nhe\\r\\nhe\\u0027d\\r\\nhe\\u0027ll\\r\\nhe\\u0027s\\r\\nher\\r\\nhere\\r\\nhere\\u0027s\\r\\nhers\\r\\nherself\\r\\nhim\\r\\nhimself\\r\\nhis\\r\\nhow\\r\\nhow\\u0027s\\r\\ni\\r\\ni\\u0027d\\r\\ni\\u0027ll\\r\\ni\\u0027m\\r\\ni\\u0027ve\\r\\nif\\r\\nin\\r\\ninto\\r\\nis\\r\\nisn\\u0027t\\r\\nit\\r\\nit\\u0027s\\r\\nits\\r\\nitself\\r\\nlet\\u0027s\\r\\nme\\r\\nmore\\r\\nmost\\r\\nmustn\\u0027t\\r\\nmy\\r\\nmyself\\r\\nno\\r\\nnor\\r\\nnot\\r\\nof\\r\\noff\\r\\non\\r\\nonce\\r\\nonly\\r\\nor\\r\\nother\\r\\nought\\r\\nour\\r\\nours\\r\\nourselves\\r\\nout\\r\\nover\\r\\nown\\r\\nsame\\r\\nshan\\u0027t\\r\\nshe\\r\\nshe\\u0027d\\r\\nshe\\u0027ll\\r\\nshe\\u0027s\\r\\nshould\\r\\nshouldn\\u0027t\\r\\nso\\r\\nsome\\r\\nsuch\\r\\nthan\\r\\nthat\\r\\nthat\\u0027s\\r\\nthe\\r\\ntheir\\r\\ntheirs\\r\\nthem\\r\\nthemselves\\r\\nthen\\r\\nthere\\r\\nthere\\u0027s\\r\\nthese\\r\\nthey\\r\\nthey\\u0027d\\r\\nthey\\u0027ll\\r\\nthey\\u0027re\\r\\nthey\\u0027ve\\r\\nthis\\r\\nthose\\r\\nthrough\\r\\nto\\r\\ntoo\\r\\nunder\\r\\nuntil\\r\\nup\\r\\nvery\\r\\nwas\\r\\nwasn\\u0027t\\r\\nwe\\r\\nwe\\u0027d\\r\\nwe\\u0027ll\\r\\nwe\\u0027re\\r\\nwe\\u0027ve\\r\\nwere\\r\\nweren\\u0027t\\r\\nwhat\\r\\nwhat\\u0027s\\r\\nwhen\\r\\nwhen\\u0027s\\r\\nwhere\\r\\nwhere\\u0027s\\r\\nwhich\\r\\nwhile\\r\\nwho\\r\\nwho\\u0027s\\r\\nwhom\\r\\nwhy\\r\\nwhy\\u0027s\\r\\nwith\\r\\nwon\\u0027t\\r\\nwould\\r\\nwouldn\\u0027t\\r\\nyou\\r\\nyou\\u0027d\\r\\nyou\\u0027ll\\r\\nyou\\u0027re\\r\\nyou\\u0027ve\\r\\nyour\\r\\nyours\\r\\nyourself\\r\\nyourselves"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cspan class=\\u0022excerpt-highlight\\u0022\\u003E",
            "suffix" : "\\u003C\\/span\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function caw_search_api_settings_default_search_api_server() {
  $items = array();
  $items['gotosolr'] = entity_import('search_api_server', '{
    "name" : "GoToSolr",
    "machine_name" : "gotosolr",
    "description" : "GoToSolr for CAW",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "https",
      "host" : "eb3d760e-1cec-42ae-be45-1fb4cfad783f-index.solrdata.com",
      "port" : "443",
      "path" : "\\/solr\\/4b1a53fa615f4c73aba69a554a9d9c13.24b7729e02dc47d19c15f1310098f93f",
      "http_user" : "a63396b1-7878-48b0-ba78-d5aeeff88727",
      "http_pass" : "b6f47868-4e92-42ce-aeda-ac9dd6a9b737",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
