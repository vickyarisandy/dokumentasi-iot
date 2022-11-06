#include <EEPROM.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

#define EEPROM_SIZE 17

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
   EEPROM.begin(EEPROM_SIZE);
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

  getstate();
}
void loop ()
{
int oldHour = 0;
  
    Serial.println("Enter pin:");
    while (Serial.available() == 0) {}    //wait for data available
    String teststr = Serial.readString();  //read until timeout
    teststr.trim();                        // remove any \r \n whitespace at the end of the String
     if (teststr == "1") {
      //Serial.println("Teras nyala 1 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "2") {
      //Serial.println("Teras mati 1 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati1");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "3") {
      //Serial.println("Teras nyala 2 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala2");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "4") {
      //Serial.println("Teras mati 2 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati2");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "5") {
      //Serial.println("Teras nyala 3 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala3");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "6") {
      //Serial.println("Teras mati 3 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati3");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "7") {
      //Serial.println("Teras nyala 4 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala4");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "8") {
      //Serial.println("Teras mati 4 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati4");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "9") {
      //Serial.println("Teras nyala 5 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala5");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "10") {
      //Serial.println("Teras mati 5 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati5");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "11") {
      //Serial.println("Teras nyala 6 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala6");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "12") {
      //Serial.println("Teras mati 6 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati6");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "13") {
      //Serial.println("Teras nyala 7 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala7");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "14") {
      //Serial.println("Teras mati 7 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati7");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "15") {
      //Serial.println("Teras nyala 8 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala8");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "16") {
      //Serial.println("Teras mati 8 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati8");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "17") {
      //Serial.println("Teras nyala 9 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala9");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "18") {
      //Serial.println("Teras mati 9 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati9");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "19") {
      //Serial.println("Teras nyala 10 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala10");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "20") {
      //Serial.println("Teras mati 10 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati10");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "21") {
      //Serial.println("Teras nyala 11 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala11");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "22") {
      //Serial.println("Teras mati 11 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati11");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "23") {
      //Serial.println("Teras nyala 12 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala12");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "24") {
      //Serial.println("Teras mati 12 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati12");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "25") {
    //   //Serial.println("Teras nyala 13 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala13");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "26") {
    //   //Serial.println("Teras mati 13 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati13");
        //Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "27") {
     //Serial.println("Teras nyala 14 = ");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala14");
        //Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "28") {
     //Serial.println("Teras mati 14 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati14");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "29") {
      //Serial.println("Teras nyala 15 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala15");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "30") {
      //Serial.println("Teras mati 15 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati15");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "31") {
      //Serial.println("Teras nyala 16 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"nyala16");
        Serial.println("data");
        oldHour = newHour;
      }
    } else if (teststr == "32") {
      //Serial.println("Teras mati 16 = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"mati16");
        Serial.println("data");
        oldHour = newHour;
      }
    } else {
      //Serial.println("Peritah salah = diterima(" + teststr + "),");
      DateTime now = rtc.now();
      newHour = now.hour();
      if (oldHour != newHour) {
        save_temperature(teststr,"dibatalkan");
        Serial.println("Batal");
        oldHour = newHour;
      }
    }


  }

