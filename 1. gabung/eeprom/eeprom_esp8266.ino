
#include <EEPROM.h>
//#include <WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" 

const int SIG = 2;// SIG pin  
const int EN = 7;// Enable pin 
const int controlPin[4] = {3, 4, 5, 6}; // 4 pins used  for binary output


const int muxTable[16][4] = {
  // s0, s1, s2, s3     channel
    {0,  0,  0,  0}, // 0
    {1,  0,  0,  0}, // 1
    {0,  1,  0,  0}, // 2
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

int relay1[4] = {0,  0,  0,  0};


#define EEPROM_SIZE 17


#ifndef STASSID
#define STASSID "GConnect v0.1 :)"
#define STAPSK  "12345678"
#endif

ESP8266WebServer server(80);
//int relay 1 = 13, relay 2 = 14, relay 3 = 27, relay 4 = 26;
int relay1 = channelControl(1);
//  relay2 = 14, relay3 = 27, relay4 = 26;
// int relay5 = 25, relay6 = 33, relay7 = 32, relay8 = 23;
// int relay9 = 2, relay10 = 17, relay11 = 16, relay12 = 4;
// int relay13 = 15, relay14 = 5, relay15 = 18, relay16 = 19; 

// int state1 = HIGH, state2 = HIGH, state3 = HIGH, state4 = HIGH;
// int state5 = HIGH, state6 = HIGH, state7 = HIGH, state8 = HIGH;
// int state9 = HIGH, state10 = HIGH, state11 = HIGH, state12 = HIGH;
// int state13 = HIGH, state14 = HIGH, state15 = HIGH, state16 = HIGH;

const char* ApSsid = STASSID;
const char* ApPassword = STAPSK;

void handleRoot() {
    String s = MAIN_page; //Read HTML contents
    server.send(200, "text/html", s); //Send web page
}
void handlestate1() {
    handleRoot();
    state1 = !state1;
    digitalWrite(relay1, state1);
    EEPROM.write(1, state1);
    EEPROM.commit();
  }
void handlestate2() {
    handleRoot();
    state2 = !state2;
    digitalWrite(relay2, state2);
    EEPROM.write(2, state2);
    EEPROM.commit();
  }
void handlestate3() {
    handleRoot();
    state3 = !state3;
    digitalWrite(relay3, state3);
    EEPROM.write(3, state3);
    EEPROM.commit();
  }
void handlestate4() {
    handleRoot();
    state4 = !state4;
    digitalWrite(relay4, state4);
    EEPROM.write(4, state4);
    EEPROM.commit();
  }
void handlestate5() {
    handleRoot();
    state5 = !state5;
    digitalWrite(relay5, state5);
    EEPROM.write(5, state5);
    EEPROM.commit();
  }
void handlestate6() {
    handleRoot();
    state6 = !state6;
    digitalWrite(relay6, state6);
    EEPROM.write(6, state6);
    EEPROM.commit();
  }
void handlestate7() {
    handleRoot();
    state7 = !state7;
    digitalWrite(relay7, state7);
    EEPROM.write(7, state7);
    EEPROM.commit();
  }
void handlestate8() {
    handleRoot();
    state8 = !state8;
    digitalWrite(relay8, state8);
    EEPROM.write(8, state8);
    EEPROM.commit();
  }

void handlestate9() {
    handleRoot();
    state9 = !state9;
    digitalWrite(relay9, state9);
    EEPROM.write(9, state9);
    EEPROM.commit();
  }

  void handlestate10() {
    handleRoot();
    state10 = !state10;
    digitalWrite(relay10, state10);
    EEPROM.write(10, state10);
    EEPROM.commit();
  }

 void handlestate11() {
    handleRoot();
    state11 = !state11;
    digitalWrite(relay11, state11);
    EEPROM.write(11, state11);
    EEPROM.commit();
  }

   void handlestate12() {
    handleRoot();
    state12 = !state12;
    digitalWrite(relay12, state12);
    EEPROM.write(12, state12);
    EEPROM.commit();
  }

   void handlestate13() {
    handleRoot();
    state13 = !state13;
    digitalWrite(relay13, state13);
    EEPROM.write(13, state13);
    EEPROM.commit();
  }

   void handlestate14() {
    handleRoot();
    state14 = !state14;
    digitalWrite(relay14, state14);
    EEPROM.write(14, state14);
    EEPROM.commit();
  }

   void handlestate15() {
    handleRoot();
    state15 = !state15;
    digitalWrite(relay15, state15);
    EEPROM.write(15, state15);
    EEPROM.commit();
  }

   void handlestate16() {
    handleRoot();
    state16 = !state16;
    digitalWrite(relay16, state16);
    EEPROM.write(16, state16);
    EEPROM.commit();
  }


  
void handleallon() {
    handleRoot();
    state1 = LOW, state2 = LOW, state3 = LOW, state4 = LOW;
    state5 = LOW, state6 = LOW, state7 = LOW, state8 = LOW;
    state9 = LOW, state10 = LOW, state11 = LOW, state12 = LOW;
    state13 = LOW, state14 = LOW, state15 = LOW, state16 = LOW;
    setrelaystate();
    EEPROM.write(1, state1);
    EEPROM.write(2, state2);
    EEPROM.write(3, state3);
    EEPROM.write(4, state4);
    EEPROM.write(5, state5);
    EEPROM.write(6, state6);
    EEPROM.write(7, state7);
    EEPROM.write(8, state8);
    EEPROM.write(9, state9);
    EEPROM.write(10, state10);
    EEPROM.write(11, state11);
    EEPROM.write(12, state12);
    EEPROM.write(13, state13);
    EEPROM.write(14, state14);
    EEPROM.write(15, state15);
    EEPROM.write(16, state16);
    EEPROM.commit();
  }
void handlealloff() {
    handleRoot();
    state1 = HIGH, state2 = HIGH, state3 = HIGH, state4 = HIGH;
    state5 = HIGH, state6 = HIGH, state7 = HIGH, state8 = HIGH;
     state9 = HIGH, state10 = HIGH, state11 = HIGH, state12 = HIGH;
    state13 = HIGH, state14 = HIGH, state15 = HIGH, state16 = HIGH;
    setrelaystate();
    EEPROM.write(1, state1);
    EEPROM.write(2, state2);
    EEPROM.write(3, state3);
    EEPROM.write(4, state4);
    EEPROM.write(5, state5);
    EEPROM.write(6, state6);
    EEPROM.write(7, state7);
    EEPROM.write(8, state8);
    EEPROM.write(9, state9);
    EEPROM.write(10, state10);
    EEPROM.write(11, state11);
    EEPROM.write(12, state12);
    EEPROM.write(13, state13);
    EEPROM.write(14, state14);
    EEPROM.write(15, state15);
    EEPROM.write(16, state16);
    EEPROM.commit();
  }
void handlestate() {
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += state1;
  content += "</analog><analog>";
  content += state2;
  content += "</analog><analog>";
  content += state3;
  content += "</analog><analog>";
  content += state4;
  content += "</analog><analog>";
  content += state5;
  content += "</analog><analog>";
  content += state6;
  content += "</analog><analog>";
  content += state7;
  content += "</analog><analog>";
  content += state8;
  content += "</analog><analog>";
  content += state9;
  content += "</analog><analog>";
  content += state10; 
  content += "</analog><analog>";
  content += state11;
  content += "</analog><analog>";
  content += state12;
  content += "</analog><analog>";
  content += state13;
  content += "</analog><analog>";
  content += state14;
  content += "</analog><analog>";
  content += state15;
  content += "</analog><analog>";
  content += state16;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); //Send web page
}
void setup() {
  EEPROM.begin(EEPROM_SIZE);
  WiFi.begin(ApSsid, ApPassword);  //default IP: http://192.168.4.1
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(relay9, OUTPUT);
  pinMode(relay10, OUTPUT);
  pinMode(relay11, OUTPUT);
  pinMode(relay12, OUTPUT);
  pinMode(relay13, OUTPUT);
  pinMode(relay14, OUTPUT);
  pinMode(relay15, OUTPUT);
  pinMode(relay16, OUTPUT);
  server.on("/", handleRoot); 
  server.on("/LED1", handlestate1); 
  server.on("/LED2", handlestate2);  
  server.on("/LED3", handlestate3); 
  server.on("/LED4", handlestate4);  
  server.on("/LED5", handlestate5); 
  server.on("/LED6", handlestate6);  
  server.on("/LED7", handlestate7); 
  server.on("/LED8", handlestate8);
  server.on("/LED9", handlestate9);
  server.on("/LED10", handlestate10);
  server.on("/LED11", handlestate11);
  server.on("/LED12", handlestate12);
  server.on("/LED13", handlestate13);
  server.on("/LED14", handlestate14);
  server.on("/LED15", handlestate15);
  server.on("/LED16", handlestate16);  
  server.on("/allon", handleallon);
  server.on("/alloff", handlealloff);
  server.on("/redstate", handlestate); 
  server.begin();
  getstate();
}
void loop() {
  server.handleClient();
}
void setrelaystate() { 
    digitalWrite(relay1, state1);
    digitalWrite(relay2, state2);
    digitalWrite(relay3, state3);
    digitalWrite(relay4, state4);
    digitalWrite(relay5, state5);
    digitalWrite(relay6, state6);
    digitalWrite(relay7, state7);
    digitalWrite(relay8, state8);
    digitalWrite(relay9, state9);
    digitalWrite(relay10, state10);
    digitalWrite(relay11, state11);
    digitalWrite(relay12, state12);
    digitalWrite(relay13, state13);
    digitalWrite(relay14, state14);
    digitalWrite(relay15, state15);
    digitalWrite(relay16, state16);
}
void getstate() { 
    state1 = EEPROM.read(1);
    state2 = EEPROM.read(2);
    state3 = EEPROM.read(3);
    state4 = EEPROM.read(4);
    state5 = EEPROM.read(5);
    state6 = EEPROM.read(6);
    state7 = EEPROM.read(7);
    state8 = EEPROM.read(8);
    state9 = EEPROM.read(9);
    state10 = EEPROM.read(10);
    state11 = EEPROM.read(11);
    state12 = EEPROM.read(12);
    state13 = EEPROM.read(13);
    state14 = EEPROM.read(14);
    state15 = EEPROM.read(15);
    state16 = EEPROM.read(16);
    setrelaystate();
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
