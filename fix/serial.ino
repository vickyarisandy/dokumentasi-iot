#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
 
char daysOfTheWeek[7][12] = {"Minngu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  #ifndef ESP8266
    while (!Serial); // wait for serial port to connect. Needed for native USB
  #endif

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

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Enter data:");
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == "1") {
    Serial.print("Teras nyala 1 = diterima(" + teststr + "),");
  } else if (teststr == "2") {
    Serial.print("Teras mati 1 = diterima(" + teststr + "),");
  } else if (teststr == "3") {
    Serial.print("Lampu nyala 2 = diterima(" + teststr + "),");
  } else if (teststr == "4") {
    Serial.print("Teras mati 2 = diterima(" + teststr + "),");
  } else if (teststr == "5") {
    Serial.print("Lampu nyala 3 = diterima(" + teststr + "),");
  } else if (teststr == "6") {
    Serial.print("Teras mati 3 = diterima(" + teststr + "),");
  } else if (teststr == "7") {
    Serial.print("Lampu nyala 4 = diterima(" + teststr + "),");
  } else if (teststr == "8") {
    Serial.print("Teras mati 4 = diterima(" + teststr + "),");
  } else if (teststr == "9") {
    Serial.print("Lampu nyala 5 = diterima(" + teststr + "),");
  } else if (teststr == "10") {
    Serial.print("Teras mati 5 = diterima(" + teststr + ")," );
  } else if (teststr == "11") {
    Serial.print("Lampu nyala 6 = diterima(" + teststr + "),");
  } else if (teststr == "12") {
    Serial.print("Teras mati 6 = diterima(" + teststr + "),");
  } else if (teststr == "13") {
    Serial.print("Lampu nyala 7 = diterima(" + teststr + "),");
  } else if (teststr == "14") {
    Serial.print("Teras mati 7 = diterima(" + teststr + "),");
  } else if (teststr == "15") {
    Serial.print("Lampu nyala 8 = diterima(" + teststr + "),");
  } else if (teststr == "16") {
    Serial.print("Teras mati 8 = diterima(" + teststr + "),");
  } else if (teststr == "17") {
    Serial.print("Lampu nyala 9 = diterima(" + teststr + "),");
  } else if (teststr == "18") {
    Serial.print("Teras mati 9 = diterima(" + teststr + "),");
  } else if (teststr == "19") {
    Serial.print("Lampu nyala 10 = diterima(" + teststr + "),");
  } else if (teststr == "20") {
    Serial.print("Teras mati 10 = diterima(" + teststr + "),");
  } else if (teststr == "21") {
    Serial.print("Lampu nyala 11 = diterima(" + teststr + "),");
  } else if (teststr == "22") {
    Serial.print("Teras mati 11 = diterima(" + teststr + "),");
  } else if (teststr == "23") {
    Serial.print("Lampu nyala 12 = diterima(" + teststr + "),");
  } else if (teststr == "24") {
    Serial.print("Teras mati 12 = diterima(" + teststr + "),");
  } else if (teststr == "25") {
    Serial.print("Lampu nyala 13 = diterima(" + teststr + "),");
  } else if (teststr == "26") {
    Serial.print("Teras mati 13 = diterima(" + teststr + "),");
  } else if (teststr == "27") {
    Serial.print("Lampu nyala 14 = diterima(" + teststr + "),");
  } else if (teststr == "28") {
    Serial.print("Teras mati 14 = diterima(" + teststr + "),");
  } else if (teststr == "29") {
    Serial.print("Lampu nyala 15 = diterima(" + teststr + "),");
  } else if (teststr == "30") {
    Serial.print("Teras mati 15 = diterima(" + teststr + "),");
  } else if (teststr == "31") {
    Serial.print("Lampu nyala 16 = diterima(" + teststr + "),");
  } else if (teststr == "32") {
    Serial.print("Teras mati 16 = diterima(" + teststr + "),");
  } else if (teststr == "00") {
    Serial.print("Lampu nyala semua = diterima(" + teststr + "),");
  } else if (teststr == "99") {
    Serial.print("Teras mati semua = diterima(" + teststr + "),");
  } else {
    Serial.print("Peritah salah = diterima(" + teststr + "),");
  }
      DateTime now = rtc.now();

    Serial.print( now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.print("\t");

    Serial.print("Jam Suhu: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
  delay(1000);

}