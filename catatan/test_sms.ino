#include <SoftwareSerial.h>

SoftwareSerial sim800(2,3)  //tx ,rx
//
void setup(){
    sim800.begin(9600);
    Serial.begin(9600);
    Serial.println("Mulai...");
    delay(5000);
    Serial.println("AT");
    serialcom();
    Serial.println("AT+CMGF=1");
    serialcom();
    Serial.println("AT+CMGI=2,2,0,0,0");
    serialcom();
    // Serial.println();
}

void loop(){
serialcom();
}

void serilacom(){
    delay(1000);
    while(Serial.available()){
        sim800.write(Serial.read());
    }
    while(sim800.available()){
        Serial.write(sim800.read());
    }
}

