// 제목: 8x8 도트매트릭스 제어하기
// 내용: 8x8 매트릭스의 각 Led를 제어한다

#include "LedControl.h"

// DIN:12번핀, CLK: 10번핀, CS:11번핀에 연결
// LedControl(int DIN, int CLK, int CS, int Device);
LedControl lc = LedControl(12, 10, 11, 1);

// X자 모양의 이미지 배열 생성
byte a[8] = { B00110000, B01001000, B01000100, B00100010, 
      B00100010, B01000100, B01001000, B00110000};
byte no = B00000000;
void setup()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}
void loop()
{
   for (int row=0; row < 8; row++) {
      // 행을 내려가면서 배열에 맞게 Led를 켠다
      lc.setRow(0, row, a[row]);
      delay(10);
   }
   delay(1000);
   for (int row=0; row < 8; row++) {
   // 행을 내려가면서 배열에 맞게 Led를 켠다
     lc.setRow(0, row, no);
   }
   delay(1000);
}
