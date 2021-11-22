#include <SoftwareSerial.h>

int ledPin = 3;

SoftwareSerial BTSerial(4, 5);   

void setup() {  
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (BTSerial.available()){
    char data = BTSerial.read();
    Serial.println(data);
    
    if(data == 'a'){
      digitalWrite(ledPin, HIGH);
    }
    else if(data == 'b'){
      digitalWrite(ledPin, LOW);
    }
  }
}
