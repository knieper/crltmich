Description
-----------
The Webform Nodevalues module provides information about a current node to
an attached Webform block. Actually Webform doesn't know about the current
node, so it's not possible to use information provided by the node. With
this module you can populate Webform fields with values of the current node.

Requirements
------------
Drupal 6.x and Webform 6.x
(Tested with Drupal 6.25 and Webform 6.x-3.17.)

Installation
------------
1. Copy the directory "webform_nodevalues" to sites/all/modules.

2. Login as an administrator. Enable the module in "Administer" -> "Site
   Building" -> "Modules".
   
Configuration
-------------
Edit the module file (webform_nodevalues.module).

1. Webform ID
   To set the ID of your Webform, change the $form_id.

2. Webform field populated by the current node title
   To set the key of a Webform field for the node title, change
   "my_webform_field_key" in the following line:
   $form['submitted']['my_webform_field_key']['#value'] = $node->title;

3. Webform field populated by a CCK field of the current node
   To set the key of a Webform field for a CCK field, change
   "my_webform_field_key" and "my_cck_field" in the following line:
   $form['submitted']['my_webform_field_key']['#value'] = $node->my_cck_field[0]['value'];
   
Block configuration
-------------------
1. Make the form "Available as block" in your webform settings
  (node/my_webform/webform/configure > Advanced settings).
2. Activate and configure the block on the block configuration page.
   Important: In the block settings, choose "Show all webform pages in block".
