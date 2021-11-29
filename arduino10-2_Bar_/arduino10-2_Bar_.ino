//진행 상태 바를 출력하는 LCD

//LCD 라이브러리 삽입
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//회로에 연결된 핀 번호를 사용하여 lcd 객체 인스턴스 생성
LiquidCrystal_I2C lcd(0x27, 16, 2); // RS, EN, D4~D7

//진행 상태 바를 나타내는 바이트 배열 선언
byte p20[8]={
    B10000,
    B10000, 
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
};
byte p40[8]={
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
};
byte p60[8]={
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
    B11100,
};
byte p80[8]={
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
};
byte p100[8]={
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
};
void setup()
{
        // I2C LCD를 초기화
    lcd.init();
    // I2C LCD의 백라이트를 켬
    lcd.backlight();
    //LCD의 열과 행을 16열 2행으로 설정
    lcd.begin(16, 2);
    //LCD에 문자열 출력
    lcd.print("Cho's Display");

    //진행 상태 바 만들기
    lcd.createChar(0, p20);
    lcd.createChar(1, p40);
    lcd.createChar(2, p60);
    lcd.createChar(3, p80);
    lcd.createChar(4, p100);
}

void loop()
{
    //커서를 0열 1행으로 이동
    lcd.setCursor(0,1);
    //진행 상태 바가 끝에 다다르면 공백 16개로 LCD 내용을 지움
    lcd.print("                ");

    //1행에 진행 상태 바를 만들려고 16문자만큼 반복
    for(int i=0; i<16; i++)
    {
         //각 문자마다 다섯 번 반복하여 진행 상태 바를 만듦
         for(int j=0; j<5; j++)
        {
            lcd.setCursor(i, 1); //1행의 i열로 커서 이동
            lcd.write(j); //상태 바 업데이트:20%,40%...100%
            delay(100); //0.1초간 대기
        }
    }
}
