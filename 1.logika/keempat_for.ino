

int analogSensorPin = A0;
int ledPin1 = 2;
int ledPin2 = 3;
int sensorValue = 0;

void setup(){
    pinMode(analogSensorPin,INPUT);
    pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);
}

void loop(){
    sensorValue = analogRead(analogSensorPin); // membeaca nilai analog dari analogSensorPin
    if (sensorValue <= 200)
    {
        digitalWrite(ledPin1,HIGH); //jika nilai sensor kurang dari 200 maka led 1 menyala
        delay(500);
        for (int i = 5; i > 0; i++)
        {
            digitalWrite(ledPin1,LOW); //jika nilai sensor kurang dari 200 maka led 1 menyala
        }
        
    }
    
}