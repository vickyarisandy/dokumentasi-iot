void setup(){
    Serial.begin(9600);

}

void loop(){
    //baca analog A0
    int ldr = analogRead(0);
    Serial.println(ldr); // kirim numeber
    Serial.println("hello word"); //kirim string
    delay(500);
}