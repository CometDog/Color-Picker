#include "pebble.h"
#include "gcolor_definitions.h"
#include "elements.h"
#include "libs/pebble-assist.h"

/********************************************************* 
 *                   Aesthetic Updates                   *
 *********************************************************/

static void update_text() {
  if (layernum == 1) {
    text_layer_set_text(s_color_text_1, colorname[color1]);
    if (color1 < 31) {
      text_layer_set_colors(s_color_text_1, GColorWhite, (GColor)gcolor[color1]);
    }
    else if (color1 >= 31) {
      text_layer_set_colors(s_color_text_1, GColorBlack, (GColor)gcolor[color1]);
    }
  }
  else if (layernum == 2) {
    text_layer_set_text(s_color_text_2, colorname[color2]);
    if (color2 < 31) {
      text_layer_set_colors(s_color_text_2, GColorWhite, (GColor)gcolor[color2]);
    }
    else if (color2 >= 31) {
      text_layer_set_colors(s_color_text_2, GColorBlack, (GColor)gcolor[color2]);
    }
  }
  else if (layernum == 3) {
   text_layer_set_text(s_color_text_3, colorname[color3]); 
   if (color3 < 31) {
      text_layer_set_colors(s_color_text_3, GColorWhite, (GColor)gcolor[color3]);
    }
    else if (color3 >= 31) {
      text_layer_set_colors(s_color_text_3, GColorBlack, (GColor)gcolor[color3]);
    }
  }
}

/********************************************************* 
 *                    Click Handlers                     *
 *********************************************************/

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  layernum = 1;
  color1 += 1;
  if (color1 > 63) {
    color1 = 0;
  }
  update_text();
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  layernum = 2;
  color2 += 1;
  if (color2 > 63) {
    color2 = 0;
  }
  update_text();
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  layernum = 3;
  color3 += 1;
  if (color3 > 63) {
    color3 = 0;
  }
  update_text();
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 300, up_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, 300, select_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 300, down_click_handler);
}

/********************************************************* 
 *                      Window Loads                     *
 *********************************************************/

static void main_window_load(Window *window) {
  
  GRect bounds = window_get_bounds(window);

  s_color_layer_1 = layer_create(GRect(0,0,144,56));
  s_color_layer_2 = layer_create(GRect(0,56,144,56));
  s_color_layer_3 = layer_create(GRect(0,112,144,56));

  s_color_text_1 = text_layer_create(GRect(0,0,144,56));
  s_color_text_2 = text_layer_create(GRect(0,0,144,56));
  s_color_text_3 = text_layer_create(GRect(0,0,144,56));
  
  text_layer_set_colors(s_color_text_1, GColorWhite, (GColor)gcolor[color1]);
  text_layer_set_colors(s_color_text_2, GColorWhite, (GColor)gcolor[color2]);
  text_layer_set_colors(s_color_text_3, GColorWhite, (GColor)gcolor[color3]);

  text_layer_set_text(s_color_text_1, colorname[color1]);
  text_layer_set_text(s_color_text_2, colorname[color2]);
  text_layer_set_text(s_color_text_3, colorname[color3]);

  text_layer_set_text_alignment(s_color_text_1, GTextAlignmentCenter);
  text_layer_set_text_alignment(s_color_text_2, GTextAlignmentCenter);
  text_layer_set_text_alignment(s_color_text_3, GTextAlignmentCenter);

  layer_add_to_window(s_color_layer_1, window);
  layer_add_to_window(s_color_layer_2, window);
  layer_add_to_window(s_color_layer_3, window);

  text_layer_add_to_layer(s_color_text_1, s_color_layer_1);
  text_layer_add_to_layer(s_color_text_2, s_color_layer_2);
  text_layer_add_to_layer(s_color_text_3, s_color_layer_3);
}

static void main_window_unload(Window *window) {

  layer_destroy_safe(s_color_layer_1);
  layer_destroy_safe(s_color_layer_2);
  layer_destroy_safe(s_color_layer_3);
  
  text_layer_destroy_safe(s_color_text_1);
  text_layer_destroy_safe(s_color_text_2);
  text_layer_destroy_safe(s_color_text_3);
}

/********************************************************* 
 *                  (De)Initialization                   *
 *********************************************************/

static void init() {
  s_main_window = window_create();
 
  window_handlers(s_main_window, main_window_load, main_window_unload);

  window_stack_push(s_main_window, true);
  
  window_set_click_config_provider(s_main_window, click_config_provider);

}

static void deinit() {
  window_destroy_safe(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}