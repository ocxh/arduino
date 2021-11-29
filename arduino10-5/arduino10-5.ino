#include <LiquidCrystal_I2C.h>



 // LCD를 쉽게 제어하기 위한 라이브러리를 추가합니다.

#include <Wire.h>

// I2C 주소는 LCD에 맞게 수정
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // I2C LCD를 초기화
   lcd.init();
  // I2C LCD의 백라이트를 켬
  lcd.backlight();
}

void loop() { 
  // random 함수를 사용하여 0~2까지의 숫자 중 임의적으로 생성
  int value = random(0, 3);
// 랜덤 값이 0이라면
  if (value == 0) {
    lcd.setCursor(0,0); // 0번째 줄 0번째 셀에 위치
    lcd.print("  KocoaFab.cc  ");       
  }
  // 랜덤 값이 1이라면 
  else if (value == 1) {
    lcd.setCursor(0,1); // 1번째 줄 0번째 셀에 위치
    lcd.print("  Hello World!!  ");     
  }
  // 랜덤 값이 2이라면 
  else if (value == 2) {
    lcd.setCursor(0,0); // // 0번째 줄 0번째 셀에 위치 
    lcd.print("  Kangnam U. ");
    lcd.setCursor(0,1); // 1번째 줄 0번째 셀에 위치
    lcd.print(" Div. of Science ");
  }
  // 1초간 대기합니다.
  delay(1000);
  // LCD의 모든 내용을 삭제
  lcd.clear();
}
