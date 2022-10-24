//#include  ? (SofwareSerial)

SofwareSerial sim(8,7); //TX,RX

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
        if (pesan=="ON\r")
        {
            digitalWrite(relay,HIGH);
            eksekusi(1);
            Serial.println("Relay nyala");
        }


        if (pesan=="OFF\r")
        {
            digitalWrite(relay,LOW);
            eksekusi(0);
            Serial.println("Relay mati");
        }
        
    }
    
    
}

void eksekusi(bool tipe){
    sim.println("AT+CMGF=1");
    sim.println("AT+CMGF=\"+6289xxxxxxx\"\r");
    delay(1000);
    if (tipe=1){
        /* code */
        sim.println("relay on");
    }else{
        sim.println("relay off");
    }
    delay(100);
    sim.prinln((char)26);
    
}