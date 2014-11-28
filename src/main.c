#include <pebble.h>
#include <ctype.h>  
#include "face.h"
  
char buffer_hours[] = "00";
char buffer_minutes[] = "00"; 
char buffer_battery[]="100%";
char buffer_date[]="DEC 31";
char buffer_dow[]="WED";
char buffer_ampm[]="AM";
  
void tick_handler(struct tm *tick_time, TimeUnits units_changed)
{
  
    if (!clock_is_24h_style()) {
    
        if( tick_time->tm_hour > 11 ) {   // YG Jun-25-2014: 0..11 - am 12..23 - pm
            strcpy(buffer_ampm, "PM" );
            if( tick_time->tm_hour > 12 ) tick_time->tm_hour -= 12;
        } else {
            strcpy(buffer_ampm, "AM" );
            if( tick_time->tm_hour == 0 ) tick_time->tm_hour = 12;
        }        
 
    } else {
       strcpy(buffer_ampm, "  " );
    }
 
    strftime(buffer_hours, sizeof("00"), "%H", tick_time);
    strftime(buffer_minutes, sizeof("00"), "%M", tick_time);
    snprintf(buffer_battery, sizeof("100%"), "%d%%", battery_state_service_peek().charge_percent);
    strftime(buffer_date, sizeof("DEC 31"), "%b %d", tick_time);
    buffer_date[1] = toupper((unsigned char)buffer_date[1]);
    buffer_date[2] = toupper((unsigned char)buffer_date[2]);
    strftime(buffer_dow, sizeof("WED"), "%a", tick_time);
    buffer_dow[1] = toupper((unsigned char)buffer_dow[1]);
    buffer_dow[2] = toupper((unsigned char)buffer_dow[2]);
    set_texts(buffer_hours, buffer_minutes, buffer_battery, buffer_date, buffer_dow, buffer_ampm);
  
    
   
}  

  

int main() {
  show_face();
  tick_timer_service_subscribe(MINUTE_UNIT, (TickHandler) tick_handler);
  bluetooth_connection_service_subscribe(display_bt_layer);
  app_event_loop();
  bluetooth_connection_service_unsubscribe();
  tick_timer_service_unsubscribe(); 
  return 0;
}