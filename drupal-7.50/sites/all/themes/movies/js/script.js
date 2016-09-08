/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document) {

  //'use strict';

  // To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.tooltip = {
    attach: function (context, settings) {

      // Place your code here.

      // When we mouse over a link in the top ten list view
      $('.newsview  a').mouseover(function() {

        // Get the tooltip text from the next column along.
        tooltip_text =  $(this).parents('article').find('.field-name-body p').html();

        // Create a div which is appended to the outside of the a tag.
        $('<div class="news-tooltip">' + tooltip_text +'</div>').appendTo($(this).parents('header'));
      });

      // When we mouse off a link in the top ten list view
      $('.newsview a').mouseout(function() {

        // Remove any tooltips.
        $('.news-tooltip').remove();
      })

    }
  };

})(jQuery, Drupal, this, this.document);
