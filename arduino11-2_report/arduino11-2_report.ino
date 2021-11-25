#include <SoftwareSerial.h>

int Rled = 9;
int Yled = 8;
int Gled = 7;

SoftwareSerial BTSerial(4, 5);   

void setup() {  
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(Rled, OUTPUT);
  pinMode(Yled, OUTPUT);
  pinMode(Gled, OUTPUT);
}

void loop() {
  if (BTSerial.available()){
    char data = BTSerial.read();
    Serial.println(data);
    
    if(data == 'r'){
      digitalWrite(Rled, HIGH);
      digitalWrite(Yled, LOW);
      digitalWrite(Gled, LOW);
    }
    else if(data == 'y'){
      digitalWrite(Rled, LOW);
      digitalWrite(Yled, HIGH);
      digitalWrite(Gled, LOW);
    }
    else if(data == 'g'){
      digitalWrite(Rled, LOW);
      digitalWrite(Yled, LOW);
      digitalWrite(Gled, HIGH);
    }
  }
  if (Serial.available()){
    BTSerial.write(Serial.read());
  }
}
