//진행 상태 바를 출력하는 LCD

//LCD 라이브러리 삽입
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//회로에 연결된 핀 번호를 사용하여 lcd 객체 인스턴스 생성
LiquidCrystal_I2C lcd(0x27, 16, 2); // RS, EN, D4~D7

const int TEMP = 0; //온도값을 센서에서 읽어올 변수
const int LOW_TEMP=140; //센서에서 읽어들인 최저 온도
const int HIGH_TEMP=170; //센서에서 읽어들인 최고 온도
int val=0; //TEMP값을 매핑할 변수
int gg=0; //Bar를 그리기위해 val값을 매핑한 변수

//그려진 바의 배열
byte bars[8]={
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
  //시리얼 모니터 초기화
  Serial.begin(9600);
  // I2C LCD를 초기화
  lcd.init();
  // I2C LCD의 백라이트를 켬
  lcd.backlight();
  //LCD의 열과 행을 16열 2행으로 설정
  lcd.begin(16, 2);

  //진행 상태 바 만들기
  lcd.createChar(0, bars);
}

void loop()
{
  //TEMP센서에서 읽어들인 조도값을 15~35 사이로 매핑하기
  val = analogRead(TEMP);
  val = map(val, LOW_TEMP, HIGH_TEMP, 15,35);
  // Bar를 만들 때 사용할 변수. val의 값을 1~17로 매핑하여 반복문에 사용
  gg = map(val, 15, 35, 1, 17);
  //1열0행으로 커서를 옮긴 후 온도 출력
  lcd.setCursor(1, 0);
  lcd.print("TEMP: ");
  lcd.print(val);
  Serial.print("현재 온도: ");
  Serial.println(val);
  //매핑된 변수 gg만큼 상태 바를 업데이트 시킵니다.
  for(int i=0; i<gg; i++){
    lcd.setCursor(i, 1); //i열로 커서 이동
    lcd.write(0); //가득찬 상태바
  }
  delay(5000); //5초간 대기
}
