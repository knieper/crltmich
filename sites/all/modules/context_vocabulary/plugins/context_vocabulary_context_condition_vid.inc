<?php
/**
 * @file
 * context_vocabulary class, extends context_condition_node
 */

/**
 * Vocabulary as a context condition.
 */
class context_vocabulary_context_condition_vid extends context_condition_node {
  function condition_values() {
    $values = array();
    foreach (taxonomy_get_vocabularies() as $vocab) {
      $values[$vocab->vid] = check_plain($vocab->name);
    }
    return $values;
  }

  /**
   * Condition form.
   */
  function condition_form($context) {
    $form = parent::condition_form($context);
    $form['#type'] = 'checkboxes';
    $form['#multiple'] = TRUE;

    foreach (taxonomy_get_vocabularies() as $vocab) {
      $opts[$vocab->vid] = check_plain($vocab->name);
    }

    $form['#options'] = $opts;
    return $form;
  }

  /**
   * Execute.
   */
  function execute($node, $op) {
    if ($this->condition_used() && !empty($node->taxonomy)) {
      foreach ($node->taxonomy as $term) {
        foreach ($this->get_contexts($term->vid) as $context) {
          // Check the node form option.
          if ($op === 'form') {
            $options = $this->fetch_from_context($context, 'options');
            if (!empty($options['node_form'])) {
              $this->condition_met($context, $term->vid);
            }
          }
          else {
            $this->condition_met($context, $term->vid);
          }
        }
      }
    }
  }
}
