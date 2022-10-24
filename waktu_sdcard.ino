#include <Wire.h>
#include <DS3231.h>
#include <SPI.h>
#include <SD.h>

DS3231 rtc(SDA, SCL);
File fileku;

void setup(){
    Serial.begin(9600);// set komunikasi baut di serial monitor
    Serial.println("header aja");
    delay(3000);// 3 detik

    rtc.begin();

    // set jam dan tanggal
    // rtc.setDate(24, 10, 2022);
    // rtc.setTime(12, 14, 00);
    // rtc.setDOW(3);

    Serial.println("set up SD card");
    delay(1000);

    if(!SD.begin(4)){
    Serial.println("Gagal baca sd card");
    return;
    }
    Serial.println("header aja");
    delay(1000);

}

void loop(){

    fileku = SD.open("datalogger.txt", FILE_WRITE);
    if (fileku){
        Serial.print("Tampil serial monitor ddan catat");
        Serial.print(",");
        fileku.print("Tampil serial monitor ddan catat");
        Serial.println(",");
        fileku.close();
    }else{
        Serial.println("tidak terbaca sd card pada loop");
    }
    delay(2000);
    

}