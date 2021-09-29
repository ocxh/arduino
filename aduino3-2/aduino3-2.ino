const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int TEMP = 0;

const int LOWER_BOUND = 139;
const int UPPER_BOUND = 147;

int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(TEMP);
  if (val < LOWER_BOUND){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }else if(val > UPPER_BOUND){
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }else{
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}
