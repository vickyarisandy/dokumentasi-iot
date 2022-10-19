int pushButton1 = A0;
int pushButton2 = A1;
int pushButton3 = A2;
int pushButton4 = A3;
int pushButton5 = A4;

int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;

int val = 0;

void setup(){
    pinMode(pushButton1,INPUT);
    pinMode(pushButton2,INPUT);
    pinMode(pushButton3,INPUT);
    pinMode(pushButton4,INPUT);
    pinMode(pushButton5,INPUT);
    pinMode(ledPin1,OUTPUT);
    pinMode(ledPin2,OUTPUT);
    pinMode(ledPin3,OUTPUT);
    pinMode(ledPin4,OUTPUT);
    pinMode(ledPin5,OUTPUT);
}

void loop(){
    if (pushButton1 == HIGH){
        val = 1;
    } else if (pushButton2 == HIGH){
        val = 2;
    } else if (pushButton3 == HIGH){
        val = 3;
    }else if (pushButton4 == HIGH){
        val = 4;
    }else if (pushButton5 == HIGH){
        val = 5;
    }else {
        val = 0;
    }

    switch (val)
    {
    case 0:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        break;
    
    case 1:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        break;
    
    case 2:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        break;
    
    case 3:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        break;
    
    case 4:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,LOW);
        break;
    
    case 5:
    /* constant-expression */:
        /* code */
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,HIGH);
        break;
    
    
    }
    
    
}


