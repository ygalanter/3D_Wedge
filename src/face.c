#include "face.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_back;
static GFont s_res_wedgie_regular_45;
static GFont s_res_gothic_24_bold;
static BitmapLayer *s_bitmaplayer_back;
static TextLayer *s_textlayer_minutes;
static TextLayer *s_textlayer_hours;
static TextLayer *s_textlayer_battery;
static TextLayer *s_textlayer_date;
static TextLayer *s_textlayer_dow;
static TextLayer *s_textlayer_ampm;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, 1);
  
  s_res_image_back = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACK);
  s_res_wedgie_regular_45 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_WEDGIE_REGULAR_45));
  s_res_gothic_24_bold = fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  // s_bitmaplayer_back
  s_bitmaplayer_back = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(s_bitmaplayer_back, s_res_image_back);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_back);
  
  // s_textlayer_minutes
  s_textlayer_minutes = text_layer_create(GRect(34, 83, 110, 51));
  text_layer_set_background_color(s_textlayer_minutes, GColorClear);
  text_layer_set_text_color(s_textlayer_minutes, GColorWhite);
  text_layer_set_text(s_textlayer_minutes, "00");
  text_layer_set_text_alignment(s_textlayer_minutes, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_minutes, s_res_wedgie_regular_45);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_minutes);
  
  // s_textlayer_hours
  s_textlayer_hours = text_layer_create(GRect(9, 40, 125, 49));
  text_layer_set_background_color(s_textlayer_hours, GColorClear);
  text_layer_set_text_color(s_textlayer_hours, GColorWhite);
  text_layer_set_text(s_textlayer_hours, "00");
  text_layer_set_font(s_textlayer_hours, s_res_wedgie_regular_45);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_hours);
  
  // s_textlayer_battery
  s_textlayer_battery = text_layer_create(GRect(1, 142, 56, 24));
  text_layer_set_background_color(s_textlayer_battery, GColorClear);
  text_layer_set_text(s_textlayer_battery, "100%");
  text_layer_set_font(s_textlayer_battery, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_battery);
  
  // s_textlayer_date
  s_textlayer_date = text_layer_create(GRect(77, -7, 65, 24));
  text_layer_set_background_color(s_textlayer_date, GColorClear);
  text_layer_set_text(s_textlayer_date, "DEC 31");
  text_layer_set_text_alignment(s_textlayer_date, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_date, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_date);
  
  // s_textlayer_dow
  s_textlayer_dow = text_layer_create(GRect(99, 12, 42, 24));
  text_layer_set_background_color(s_textlayer_dow, GColorClear);
  text_layer_set_text(s_textlayer_dow, "WED");
  text_layer_set_text_alignment(s_textlayer_dow, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_dow, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_dow);
  
  // s_textlayer_ampm
  s_textlayer_ampm = text_layer_create(GRect(1, 122, 48, 24));
  text_layer_set_background_color(s_textlayer_ampm, GColorClear);
  text_layer_set_text(s_textlayer_ampm, "AM");
  text_layer_set_font(s_textlayer_ampm, s_res_gothic_24_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_ampm);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_back);
  text_layer_destroy(s_textlayer_minutes);
  text_layer_destroy(s_textlayer_hours);
  text_layer_destroy(s_textlayer_battery);
  text_layer_destroy(s_textlayer_date);
  text_layer_destroy(s_textlayer_dow);
  text_layer_destroy(s_textlayer_ampm);
  gbitmap_destroy(s_res_image_back);
  fonts_unload_custom_font(s_res_wedgie_regular_45);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_face(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_face(void) {
  window_stack_remove(s_window, true);
}

// custom code

// set texts of layers
void set_texts(char hours[], char minutes[], char battery[], char date[], char dow[], char ampm[] ) {
  text_layer_set_text(s_textlayer_hours, hours);
  text_layer_set_text(s_textlayer_minutes, minutes);
  text_layer_set_text(s_textlayer_battery, battery);
  text_layer_set_text(s_textlayer_date, date);
  text_layer_set_text(s_textlayer_dow, dow);
  text_layer_set_text(s_textlayer_ampm, ampm);
 }

