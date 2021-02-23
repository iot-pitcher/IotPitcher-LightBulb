#include <IotPitcher_IoT_Bulb.h>

/*
    pitcher_printf is a thread safe function that gives outputs directly to the log console on the AP screen Advanced page
    It has the same function format as ANSI-C printf, just change your printf functions to pitcher_printf
*/

void logtask1(void * arg){
    for(;;){
        pitcher_printf("This is logtask1, sending hello!\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

void logtask2(void * arg){
    for(;;){
        pitcher_printf("Random values read via native esp function : %u\n",esp_random());
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}


void setup(){
    Serial.begin(115200);

    printf("IotPitcher_IoT_Bulb is going to start!\n");
    pitcher_start();

    /*
        Two tasks uses 'pitcher_printf' simultaneously 
    */
    xTaskCreate(logtask1,"task1",32*100,NULL,configMAX_PRIORITIES,NULL);
    xTaskCreate(logtask2,"task2",32*100,NULL,configMAX_PRIORITIES,NULL);
}


int count = 0;

void loop(){
    pitcher_printf("Counter value : %d\n",count);
    ++count;
	delay(1000);
}