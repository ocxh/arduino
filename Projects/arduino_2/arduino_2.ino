/*
 제목   : 온습도 센서로 실내 온도와 습도 학인하기
 내용   : DHT11 온습도 센서를 사용하여 실내 온도와 습도를 측정하고 I2C_LCD 에 표시해봅니다
 */
 
// DHT11 센서를 쉽게 제어하기 위한 라이브러리를 추가해줍니다.
#include "DHT.h"
// I2C LCD를 쉽게 제어하기 위한 라이브러리를 추가해줍니다.
#include <LiquidCrystal_I2C.h>
 
// 온습도 센서를 디지털 2번 핀에 연결합니다.
#define DHTPIN 2
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
 
// 16X2 크기의 LCD 객체를 생성합니다.
// 만약 LCD 화면이 나오지 않으면 0x3F 대신 0x27를 넣어주세요.
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
 
  // LCD를 초기화 합니다.
  lcd.init();
  // LCD의 백라이트를 켜줍니다.
  lcd.backlight();
}
 
void loop() {
  // 습도와 온도값을 측정하고, 제대로 측정되었는지 확인해줍니다.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
 
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  // 온도와 습도값을 시리얼 모니터에 출력해 줍니다.
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
 
  // LCD에 출력할 습도 메세지를 만듭니다.
  String humi = "Humi : ";
  humi += (String)humidity;
  humi += "%";
 
  // LCD에 출력할 온도 메세지를 만듭니다.
  String temp = "temp : ";
  temp += (String)temperature;
  temp += "C";
 
  // 첫번째 줄, 첫번째 칸부터 "Humi = 000%" 를 출력해 줍니다.
  lcd.setCursor(0, 0);
  lcd.print(humi);
 
  // 두번째 줄, 첫번째 칸부터 "temp = 000C" 를 출력해 줍니다.
  lcd.setCursor(0, 1);
  lcd.print(temp);
 
  delay(1500);
}
