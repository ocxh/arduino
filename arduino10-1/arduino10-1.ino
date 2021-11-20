// File name: 7segmentLED.ino
int segmentPins[] = {3, 2, A4, A3, A2, 4, 5, A5}; // 7세그먼트 LED(A,B,C,D,E,F,G,H)

byte digits[10][8] = { // Common Anode(+)
  // LED A,B,C,D,E,F,G,H(각 숫자의 따른 7세그먼트 LED 표현 방법)  
  {0, 0, 0, 0, 0, 0, 1, 1}, // “0”(0:LED On,1:LED Off): 
  {1, 0, 0, 1, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0, 1}, // 2
  {0, 0, 0, 0, 1, 1, 0, 1}, // 3
  {1, 0, 0, 1, 1, 0, 0, 1}, // 4
  {0, 1, 0, 0, 1, 0, 0, 1}, // 5
  {0, 1, 0, 0, 0, 0, 0, 1}, // 6
};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++){
    pinMode(segmentPins[i], OUTPUT);
  }
  // 각각의 세그먼트 LED 핀을 출력으로 설정
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i <= 6; i++){
    setSegments(i); // 위에서 나온 숫자를 7세그먼트 LED로 표현한다.
    delay(5000);
  }
}

void setSegments(int n){ // 숫자를 7세그먼트 LED 에 표현 하는 함수
  for(int i = 0; i < 8; i++){ // 연결된 7세그먼트 LED 핀을 각각 세팅 해준다.
    digitalWrite(segmentPins[i], digits[n][i]);   
  } 
}
