#include <IotPitcher_IoT_Bulb.h>
/*
    This example shows how to use default IotPitcher functions
    To see other provided functions check 'IotPitcher_IoT_Bulb.h' in library folder
*/

void read_pitcher_version(){
    printf("Pitcher version %s\n",pitcher_get_version());
}

void read_wifi_ssid_and_password(){
    std::string ssid = pitcher_get_wifi_ssid();
    std::string password = pitcher_get_wifi_password();

    printf("Current SSID : %s, Password : %s\n",ssid.c_str(), password.c_str());
}

void read_wifi_ap_ssid_and_password(){
    std::string ssid = pitcher_get_wifi_ap_ssid();
    std::string password = pitcher_get_wifi_ap_password();

    printf("Current Access Point SSID : %s, Password : %s\n",ssid.c_str(), password.c_str());
}

void set_everything_to_default(){
    //Pitcher factory reset function sets everything to its default value!
    pitcher_factory_reset();
}

void setup(){
    Serial.begin(115200);

    printf("IotPitcher_IoT_Bulb is going to start!\n");
    /*
        Pitcher needs to initialize its environment before everything, so this must be called before the program
    */
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