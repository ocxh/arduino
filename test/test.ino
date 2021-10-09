const int MOTOR = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(MOTOR, 0);
  
}
