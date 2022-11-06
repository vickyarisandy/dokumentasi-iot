#include <SoftwareSerial.h>// ? (SoftwareSerial)

SoftwareSerial sim(8,7); //TX,RX

int relay = 12;
String pesan;

void setup(){
    Serial.begin(9600);
    pinMode(relay,OUTPUT);
    sim.begin(9600);
    delay(100);
    sim.println("AT");
    sim.println("AT+CMGF=1");
    sim.println("AT+CNMI=1,2,0,0,0");
}

void loop(){
    if (Serial.available()){
        sim.write(Serial.read());
    }
    if (sim.available())
    {
        pesan = sim.readStringUntil('\n');
        Serial.print(pesan);
        if (pesan=="nyala\r")
        {
            digitalWrite(relay,HIGH);
            eksekusi(1);
            Serial.println("Relay nyala");
        }


        if (pesan=="mati\r")
        {
            digitalWrite(relay,LOW);
            eksekusi(0);
            Serial.println("Relay mati");
        }
        
    }
    
    
}

void eksekusi(bool tipe){
    sim.println("AT+CMGF=1");
    sim.println("AT+CMGF=\"+62895802005600\"\r");
    delay(1000);
    if (tipe=1){
        /* code */
        sim.println("Siap, sudah Nyala");
    }else{
        sim.println("Wokeh, sudah Dimatikan");
    }
    delay(100);
    sim.prinln((char)26);
    
}