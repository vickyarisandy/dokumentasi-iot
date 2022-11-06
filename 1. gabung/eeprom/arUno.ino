#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"
File myFile;

RTC_DS3231 rtc;
 
//char daysOfTheWeek[7][12] = {"Minngu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

int newHour = 0;
// int oldHour = 0;




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
myFile.print(':");
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
    while (Serial.available() == 0) {}    //wait for data available
    String teststr = Serial.readString();  //read until timeout
    teststr.trim();                        // remove any \r \n whitespace at the end of the String
     if (teststr == "1") {
      //Serial.println("Teras nyala 1 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala1");
      
    } else if (teststr == "2") {
      //Serial.println("Teras mati 1 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati1");
      
    } else if (teststr == "3") {
      //Serial.println("Teras nyala 2 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala2");
      
    } else if (teststr == "4") {
      //Serial.println("Teras mati 2 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati2");
      
    } else if (teststr == "5") {
      //Serial.println("Teras nyala 3 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala3");
      
    } else if (teststr == "6") {
      //Serial.println("Teras mati 3 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati3");
      
    } else if (teststr == "7") {
      //Serial.println("Teras nyala 4 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala4");
      
    } else if (teststr == "8") {
      //Serial.println("Teras mati 4 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati4");
      
    } else if (teststr == "9") {
      //Serial.println("Teras nyala 5 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala5");
      
    } else if (teststr == "10") {
      //Serial.println("Teras mati 5 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati5");
      
    } else if (teststr == "11") {
      //Serial.println("Teras nyala 6 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala6");
      
    } else if (teststr == "12") {
      //Serial.println("Teras mati 6 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati6");
      
    } else if (teststr == "13") {
      //Serial.println("Teras nyala 7 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala7");
      
    } else if (teststr == "14") {
      //Serial.println("Teras mati 7 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati7");
      
    } else if (teststr == "15") {
      //Serial.println("Teras nyala 8 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala8");
      
    } else if (teststr == "16") {
      //Serial.println("Teras mati 8 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati8");
      
    } else if (teststr == "17") {
      //Serial.println("Teras nyala 9 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala9");
      
    } else if (teststr == "18") {
      //Serial.println("Teras mati 9 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati9");
      
    } else if (teststr == "19") {
      //Serial.println("Teras nyala 10 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala10");
      
    } else if (teststr == "20") {
      //Serial.println("Teras mati 10 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati10");
      
    } else if (teststr == "21") {
      //Serial.println("Teras nyala 11 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala11");
      
    } else if (teststr == "22") {
      //Serial.println("Teras mati 11 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati11");
      
    } else if (teststr == "23") {
      //Serial.println("Teras nyala 12 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala12");
      
    } else if (teststr == "24") {
      //Serial.println("Teras mati 12 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati12");
      
    } else if (teststr == "25") {
    //   //Serial.println("Teras nyala 13 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala13");
      
    } else if (teststr == "26") {
    //   //Serial.println("Teras mati 13 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati13");
      
    } else if (teststr == "27") {
     //Serial.println("Teras nyala 14 = ");
        save_temperature(teststr,"nyala14");
      
    } else if (teststr == "28") {
     //Serial.println("Teras mati 14 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati14");
      
    } else if (teststr == "29") {
      //Serial.println("Teras nyala 15 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala15");
      
    } else if (teststr == "30") {
      //Serial.println("Teras mati 15 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati15");
      
    } else if (teststr == "31") {
      //Serial.println("Teras nyala 16 = diterima(" + teststr + "),");
        save_temperature(teststr,"nyala16");
      
    } else if (teststr == "32") {
      //Serial.println("Teras mati 16 = diterima(" + teststr + "),");
        save_temperature(teststr,"mati16");
      
    } else {
      //Serial.println("Peritah salah = diterima(" + teststr + "),");
        save_temperature(teststr1,"dibatalkan");
      
    }

    switch(teststr){
        
        case '1':
                save_temperature(teststr,"nyala1");
        break;
        case '2':
                save_temperature(teststr,"mati1");
        break;
        case '3':
                save_temperature(teststr,"nyala2");
        break;
        case '4':
                save_temperature(teststr,"mati2");
        break;
        case '5':
                save_temperature(teststr,"nyala3");
        break;
        case '6':
                save_temperature(teststr,"mati3");
        break;
        case '7':
                save_temperature(teststr,"nyala4");
        break;
        case '8':
                save_temperature(teststr,"mati4");
        break;
        case '9':
                save_temperature(teststr,"nyala5");
        break;
        case '10':
                save_temperature(teststr,"mati5");
        break;
        case '11':
                save_temperature(teststr,"nyala6");
        break;
        case '12':
                save_temperature(teststr,"mati6");
        break;
        case '13':
                save_temperature(teststr,"nyala7");
        break;
        case '14':
                save_temperature(teststr,"mati7");
        break;
        case '15':
                save_temperature(teststr,"nyala8");
        break;
        case '16':
                save_temperature(teststr,"mati8");
        break;
        case '17':
                save_temperature(teststr,"nyala9");
        break;
        case '18':
                save_temperature(teststr,"mati9");
        break;
        case '19':
                save_temperature(teststr,"nyala10");
        break;
        case '20':
                save_temperature(teststr,"mati10");
        break;
        case '21':
                save_temperature(teststr,"nyala11");
        break;
        case '22':
                save_temperature(teststr,"mati11");
        break;
        case '23':
                save_temperature(teststr,"nyala12");
        break;
        case '24':
                save_temperature(teststr,"mati12");
        break;
        case '25':
                save_temperature(teststr,"nyala13");
        break;
        case '26':
                save_temperature(teststr,"mati13");
        break;
        case '27':
                save_temperature(teststr,"nyala14");
        break;
        case '28':
                save_temperature(teststr,"mati14");
        break;
        case '29':
                save_temperature(teststr,"nyala15");
        break;
        case '30':
                save_temperature(teststr,"mati15");
        break;
        case '31':
                save_temperature(teststr,"nyala16");
        break;
        case '32':
                save_temperature(teststr,"mati16");
        break;

    }


  }

