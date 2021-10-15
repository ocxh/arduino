const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(10);
  
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void loop() {
  if(Serial.available() >0){
    int val1 = Serial.parseInt();
    int val2 = Serial.parseInt();
    int val3 = Serial.parseInt();

    while(Serial.available()){
      Serial.read();
    }

    int val1c = constrain(val1,0,100);
    int val2c = constrain(val2,0,100);
    int val3c = constrain(val3,0,100);

    int rval = map(val1c, 0, 100, 255, 0);
    int gval = map(val2c, 0, 100, 255, 0);
    int bval = map(val3c, 0, 100, 255, 0);

    analogWrite(RED, rval);
    analogWrite(GREEN,gval);
    analogWrite(BLUE,bval);

    Serial.println("RED: "+String(val1c)+"%");
    Serial.println("GREEN: "+String(val2c)+"%");
    Serial.println("BLUE: "+String(val3c)+"%");
  }

}
