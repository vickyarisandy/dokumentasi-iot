#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
File myFile;

RTC_DS3231 rtc;
 
//char daysOfTheWeek[7][12] = {"Minngu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

int newHour = 0;
int oldHour = 0;

void save_temperature(String x, String y) {
  char daysOfTheWeek[7][12] = {"Minngu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
myFile = SD.open("iqra.txt", FILE_WRITE);
myFile.print("Pin "+ x +",");
myFile.print("Status "+ y +",");
DateTime now = rtc.now();
myFile.print(now.year());
myFile.print("/");
myFile.print(now.month());
myFile.print("/");
myFile.print(now.day());
myFile.print(",");
myFile.print(" (");
myFile.print(daysOfTheWeek[now.dayOfTheWeek()]);
myFile.print(") ");
myFile.print(now.hour());
myFile.print(":");
myFile.print(now.minute());
//rtc.getTemperature(); //convert current temperature into registers
myFile.print(",");
myFile.print(rtc.getTemperature());
myFile.print(" C\n");//read registers and save temperature on deg C
myFile.close();
}


void setup ()
{
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
  DateTime now = rtc.now();
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}
void loop ()
{
int oldHour = 0;
  
    Serial.println("Enter pin:");
    while (Serial.available() == 0) {}     //wait for data available
    String teststr = Serial.readString();  //read until timeout
    teststr.trim();
    switch(teststr) {
        case "1" :
            Serial.println("Teras nyala 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"nyala 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "2";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "3";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "4";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "5";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "6";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "7";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "8";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "9";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;
        case "10";
            Serial.println("Teras mati 1 = diterima(" + teststr + "),");
            DateTime now = rtc.now();
            newHour = now.hour();
            if (oldHour != newHour) {
                save_temperature(teststr,"mati 1");
                Serial.println("data");
                oldHour = newHour;
            }
        break;

    }                        // remove any \r \n whitespace at the end of the String
    if (teststr == "1") {
      Serial.println("Teras nyala 1 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "2") {
      Serial.println("Teras mati 1 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "3") {
      Serial.println("Teras nyala 2 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "4") {
      Serial.println("Teras mati 2 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "5") {
      Serial.println("Teras nyala 3 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "6") {
      Serial.println("Teras mati 3 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "7") {
      Serial.println("Teras nyala 4 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "8") {
      Serial.println("Teras mati 4 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "9") {
      Serial.println("Teras nyala 5 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "10") {
      Serial.println("Teras mati 5 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati 1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else {
      Serial.println("Peritah salah = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"dibatalkan");
        Serial.println("Batal");
        oldHour = newHour;
      }
    }
    
}