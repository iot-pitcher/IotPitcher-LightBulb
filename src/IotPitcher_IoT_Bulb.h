#ifndef PITCHER_H
#define PITCHER_H


#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <FS.h>


bool pitcher_start(bool wait_wifi_to_connect = true);
void pitcher_set_wifi_auto_connect(bool status);
void pitcher_factory_reset();
const char * pitcher_get_version();
int pitcher_printf(const char * format, ... );


bool pitcher_wifi_disconnect();
bool pitcher_wifi_is_connected();
void pitcher_wifi_disable_power_save_mode();
void pitcher_wifi_enable_min_power_save_mode();
void pitcher_wifi_enable_max_power_save_mode();

void pitcher_set_wifi_connect_callback( void (*connect_callback_function_ptr)(void) );
void pitcher_set_wifi_disconnect_callback( void (*disconnect_callback_function_ptr)(void) );


void pitcher_set_wifi_ap_connect_callback( void (*connect_callback_function_ptr)(void) );
void pitcher_set_wifi_ap_disconnect_callback( void (*disconnect_callback_function_ptr)(void) );


std::string pitcher_get_wifi_ssid();
bool pitcher_take_wifi_ssid(char * data, size_t len);
bool pitcher_set_wifi_ssid(const std::string &data);
bool pitcher_set_wifi_ssid_to_default();

std::string pitcher_get_wifi_password();
bool pitcher_take_wifi_password(char * data, size_t len);
bool pitcher_set_wifi_password(const std::string &data);
bool pitcher_set_wifi_password_to_default();

std::string pitcher_get_wifi_ap_ssid();
bool pitcher_take_wifi_ap_ssid(char * data, size_t len);



std::string pitcher_get_wifi_ap_password();
bool pitcher_take_wifi_ap_password(char * data, size_t len);

/*
    User defined section declaretions
*/



int pitcher_get_bulb_settings_status();
bool pitcher_set_bulb_settings_status(int data);
bool pitcher_set_bulb_settings_status_to_default();
void pitcher_set_bulb_settings_status_on_set_callback( void (*onset_callback_function_ptr)(void));


double pitcher_get_bulb_settings_intensity();
bool pitcher_set_bulb_settings_intensity(double data);
bool pitcher_set_bulb_settings_intensity_to_default();
void pitcher_set_bulb_settings_intensity_on_set_callback( void (*onset_callback_function_ptr)(void));

bool pitcher_take_bulb_settings_color(char * data, size_t len);
std::string pitcher_get_bulb_settings_color();
bool pitcher_set_bulb_settings_color(const std::string & data);
bool pitcher_set_bulb_settings_color_to_default();
void pitcher_set_bulb_settings_color_on_set_callback( void (*onset_callback_function_ptr)(void));
 

#endif