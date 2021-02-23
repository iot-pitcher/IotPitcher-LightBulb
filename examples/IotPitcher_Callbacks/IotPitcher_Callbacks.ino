#include <IotPitcher_IoT_Bulb.h>

/*
    Pitcher provides different types of callbacks
    - When wifi is connected
    - When another device is connected to AP
    - When data is changed

    To see provided functions check 'IotPitcher_IoT_Bulb.h' in library folder
*/

void on_wifi_connect(){
    std::string ssid = pitcher_get_wifi_ssid();
    printf("Connected to '%s'\n",ssid.c_str());
}
void on_wifi_disconnect(){
    std::string ssid = pitcher_get_wifi_ssid();
    printf("WiFi disconnected from '%s'\n",ssid.c_str());
}




void on_set_bulb_settings_status(){
    Serial.println("bulb_settings_status is changed! New value:");

    int value = pitcher_get_bulb_settings_status();
    Serial.println(value);
}

void on_set_bulb_settings_intensity(){
    Serial.println("bulb_settings_intensity is changed! New value:");

    double value = pitcher_get_bulb_settings_intensity();
    Serial.println(value);
}

void on_set_bulb_settings_color(){
    Serial.println("bulb_settings_color is changed! New value:");

    std::string value = pitcher_get_bulb_settings_color();
    Serial.println(value.c_str());
}



void setup(){
    Serial.begin(115200);

    /*
        Set callbacks before pitcher start
    */

    
    pitcher_set_wifi_connect_callback(on_wifi_connect);
    pitcher_set_wifi_disconnect_callback(on_wifi_disconnect);
    

    
    pitcher_set_bulb_settings_status_on_set_callback( on_set_bulb_settings_status );
    pitcher_set_bulb_settings_intensity_on_set_callback( on_set_bulb_settings_intensity );
    pitcher_set_bulb_settings_color_on_set_callback( on_set_bulb_settings_color );


    pitcher_start();
    /*
        Your code ..
    */
}



void loop(){
    /*
        Your code ..
    */
}