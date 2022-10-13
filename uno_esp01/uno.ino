int testaja = 13;

void setup(){
    pinMode(testaja, OUTPUT);
    Serial.begin(9600);
}

void loop(){

    if(Serial.available() > 0 ){
        int iqra = Serial.read();

        if(iqra == 1){
            digitalWrite(testaja, HIGH);
        }
    }
}