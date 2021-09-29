const int LED = 9;

void setup() {
  // put your setup code here, to run once:
   pinMode(LED, OUTPUT);
   
}

void loop() {
  // put your main code here, to run repeatedly:
     // turn the LED on (HIGH is the voltage level)
                      // wait for a second
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);      
}
