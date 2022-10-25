#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <ds3231.h>

struct ts t; 


const int SIG = 2;// SIG pin  
// const int SIG = 0;// SIG pin analog read voltage output  
const int EN = 7;// Enable pin 
//const int controlPin[4] = {3, 4, 5, 6}; // 4 pins used  for binary output
const int controlPin[4] = {3, 4, 9, 10};
int loopDelay = 1000;// delay in loop

const int muxTable[16][4] = {
  // s0, s1, s2, s3     channel
    {0,  0,  0,  0}, // 0 relay
    {1,  0,  0,  0}, // 1 relay
    {0,  1,  0,  0}, // 2 relay
    {1,  1,  0,  0}, // 3
    {0,  0,  1,  0}, // 4
    {1,  0,  1,  0}, // 5
    {0,  1,  1,  0}, // 6
    {1,  1,  1,  0}, // 7
    {0,  0,  0,  1}, // 8
    {1,  0,  0,  1}, // 9
    {0,  1,  0,  1}, // 10
    {1,  1,  0,  1}, // 11
    {0,  0,  1,  1}, // 12
    {1,  0,  1,  1}, // 13
    {0,  1,  1,  1}, // 14
    {1,  1,  1,  1}  // 15
};

Adafruit_BMP280 bmp; // I2C

void setup() {
   for(int i=0; i<4; i++)
  {
    pinMode(controlPin[i], OUTPUT);// set pin as output
    digitalWrite(controlPin[i], HIGH); // set initial state as HIGH     

  }
  

    pinMode(SIG, OUTPUT);// set SIG pin as output
    digitalWrite(SIG, LOW); // set SIG sends what should be the output
                            // for low trigger relay it should be LOW
                            // for HIGH trigger high it should be HIGH 

    pinMode(EN, OUTPUT);// set EN pin as output
    digitalWrite(EN, LOW); // set EN in (enable pin) Low to activate the chip   


  Serial.begin(9600);

   Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  t.hour=12; 
  t.min=30;
  t.sec=0;
  t.mday=25;
  t.mon=10;
  t.year=2022;
 
  DS3231_set(t);

  
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76))
  {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop()
{

DS3231_get(&t);
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
 
  delay(1000);
  
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    Serial.println();
    delay(2000);

      for(int i=0; i<16; i++)
  {

    channelControl(i);
        Serial.print(readMux(i));

//readMux(i);
  delay(loopDelay);// wait for loopDelay ms
  }

  //channelControl(7);// this will turn on only relay 12
 Serial.println("===============");

}


void channelControl(int relayChannel)
{
    // Robojax 16ch relay with multiplexer 20181201
    digitalWrite(controlPin[0], muxTable[relayChannel][0]);
    digitalWrite(controlPin[1], muxTable[relayChannel][1]);
    digitalWrite(controlPin[2], muxTable[relayChannel][2]);
    digitalWrite(controlPin[3], muxTable[relayChannel][3]);
  
       Serial.print(relayChannel);
       Serial.print (": ");
       Serial.print(muxTable[relayChannel][3]);
       Serial.print(muxTable[relayChannel][2]);
       Serial.print(muxTable[relayChannel][1]);
       Serial.println(muxTable[relayChannel][0]); 
   // Robojax 16ch relay with multiplexer 20181201 
}//channelControl end


float readMux(int channel){
  int controlPin[] = {3, 4, 9, 10};

  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop through the 4 sig
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = digitalRead(SIG);

  //return the value
  float voltage = (val * 5.0) / 1024.0;
  return voltage;
}