// FNDArray-CCathode.ino
#include "SevSeg.h"

SevSeg sevseg; //sevseg를 객체로 생성

void setup() {
  // put your setup code here, to run once:
 byte numDigits = 4; 
 byte digitPins[] = {13, 12, 11, 10};  // d1,d2,d3,d4
 byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};   //A,B,C,D,E,F,G,H

  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins); //(캐소드타입, 숫자개수, 변환핀, 각 숫자핀)
  sevseg.setBrightness(90); //밝기
}
void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long timer = millis(); //밀리s단위로 시간을 읽어옴
  static int deciSeconds = 0; //0.1초 단위로 숫자를 카운트하기 위해 사용
 
  if (millis() >= timer) {
    deciSeconds++; // 1000 milliSeconds is equal to 10 deciSecond
    timer += 100; 
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0; //리셋 (10000일시 리셋)
    }
    sevseg.setNumber(deciSeconds, 1); //setnumber로 출력
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}
