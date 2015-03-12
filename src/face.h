#pragma once
#include <pebble.h>

void show_face(void);
void hide_face(void);

// custom code
void set_texts(char hours[], char minutes[], char battery[], char date[], char dow[], char ampm[]);
void display_bt_layer(bool connected);
