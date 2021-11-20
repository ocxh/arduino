#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

#define MAX_ROW 4 //3차원 배열
#define MAX_NUMBER_STRINGS 5 //2차원 배열
#define MAX_STRING_SIZE 8 //1차원 배열
char testStrings[MAX_ROW][MAX_NUMBER_STRINGS][MAX_STRING_SIZE]; //3차원 배열인 testStrings생성(이곳에 출력할 값을 정의함)

#define PATTERN_CHANGE_TIME 1000
unsigned long timer = millis() - PATTERN_CHANGE_TIME;
byte testRowPos = 0; //반복문에서 3차원 인덱스로 사용
byte testStringsPos = 0; //반복문에서 2차원 인덱스로 사용

void setup() {
  byte numDigits = 4; //
  byte digitPins[] = {2, 3, 4, 5}; // d1,d2,d3,d4
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};  //A,B,C,D,E,F,G,H
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);

  //row0
  strcpy(testStrings[0][0], "0123");
  strcpy(testStrings[0][1], "0.123");
  strcpy(testStrings[0][2], "0.1.23");
  strcpy(testStrings[0][3], "0.1.2.3");
  strcpy(testStrings[0][4], "0.1.2.3.");
  // row1
  strcpy(testStrings[1][0], "4567");
  strcpy(testStrings[1][1], "4.567");
  strcpy(testStrings[1][2], "4.5.67");
  strcpy(testStrings[1][3], "4.5.6.7");
  strcpy(testStrings[1][4], "4.5.6.7.");
  //row2
  strcpy(testStrings[2][0], "89AB");
  strcpy(testStrings[2][1], "8.9AB");
  strcpy(testStrings[2][2], "8.9.AB");
  strcpy(testStrings[2][3], "8.9.A.B");
  strcpy(testStrings[2][4], "8.9.A.B.");
  //row3
  strcpy(testStrings[3][0], "CDEF");
  strcpy(testStrings[3][1], "C.DEF");
  strcpy(testStrings[3][2], "C.D.EF");
  strcpy(testStrings[3][3], "C.D.E.F");
  strcpy(testStrings[3][4], "C.D.E.F.");
}

void loop() {
  if (millis() > (timer + PATTERN_CHANGE_TIME)) {
    sevseg.setChars(testStrings[testRowPos][testStringsPos]); //출력 부분(sevseg.setChars 함수 사용)
    testStringsPos++;
    if (testStringsPos >= MAX_NUMBER_STRINGS){
      testRowPos ++;
      if (testRowPos >= MAX_ROW) testRowPos = 0;
      testStringsPos = 0;
    }
    timer = millis();
  }

  sevseg.refreshDisplay(); // Must run repeatedly
}
