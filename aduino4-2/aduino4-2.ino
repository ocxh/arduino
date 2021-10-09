const int MOTOR = 9;
const int POT = 1;
int val = 0;

void setup() {
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(POT);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(MOTOR, val);
  delay(10);
  Serial.println(val);
}
