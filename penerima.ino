void setup(){
    Serial.begin(9600);

}

void loop(){
    String data ="";
    while (Serial.available()>0)
    {
        data += char(Serial.read());
    }
    data.trim(); //buang spasi data
    Serial.println(data);
    delay(500);

}