#include <IotPitcher_IoT_Bulb.h>

/*
    Pitcher provides different setter and getter prototypes for different types of data
    - pitcher_get_* function return the type of the data 
    - pitcher_set_* function takes the type of the data
    - pitcher_set_*_to_default function sets the desired data to its default value
    - For strings there is also another function prototype
        pitcher_take_* which takes pointer of the buffer and its size
    
    To see provided functions check 'IotPitcher_IoT_Bulb.h' in library folder
*/

/*
    Get and Take functions
*/


void print_bulb_settings_status(){

    int value = pitcher_get_bulb_settings_status();
    Serial.print("bulb_settings_status value :");
    Serial.println(value);

}

void print_bulb_settings_intensity(){

    double value = pitcher_get_bulb_settings_intensity();
    Serial.print("bulb_settings_intensity value :");
    Serial.println(value);

}

void print_bulb_settings_color(){

    std::string value = pitcher_get_bulb_settings_color();
    Serial.print("bulb_settings_color value :");
    Serial.println(value.c_str());
    //Or we can also use _take function if we have enough buffer
    char buffer[100];
    pitcher_take_bulb_settings_color(buffer,sizeof(buffer));
    Serial.print("bulb_settings_color value :");
    Serial.println(buffer);
}


/*
    Set functions
*/


void set_bulb_settings_status_to_random(){

    int value = 74;
    pitcher_set_bulb_settings_status(value);
    Serial.print("bulb_settings_status set to new value :");
    Serial.println(value);

}

void set_bulb_settings_intensity_to_random(){

    double value = 33 * 0.5;
    pitcher_set_bulb_settings_intensity(value);
    Serial.print("bulb_settings_intensity set to new value :");
    Serial.println(value);

}

void set_bulb_settings_color_to_random(){

    std::string value = "IotPitcher :)";
    pitcher_set_bulb_settings_color(value);
    Serial.print("bulb_settings_color set to new value :");
    Serial.println(value.c_str());
}



void setup(){
    Serial.begin(115200);

    printf("IotPitcher_IoT_Bulb is going to start!\n");
    pitcher_start();

}



void loop(){
    Serial.println("--- Printing all values ---- ");
    
    print_bulb_settings_status();
    print_bulb_settings_intensity();
    print_bulb_settings_color();
    delay(10000);
    Serial.println("--- Setting all values ---- ");
    
    set_bulb_settings_status_to_random();
    
    set_bulb_settings_intensity_to_random();
    
    set_bulb_settings_color_to_random();
    
    
    print_bulb_settings_status();
    
    print_bulb_settings_intensity();
    
    print_bulb_settings_color();
    
    delay(10000);
    Serial.println("--- Setting all values back to default ---- ");
    
    pitcher_set_bulb_settings_status_to_default();
    
    pitcher_set_bulb_settings_intensity_to_default();
    
    pitcher_set_bulb_settings_color_to_default();
    
}