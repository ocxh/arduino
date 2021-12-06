#include <Wire.h>

int temp_address=72;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(temp_address); //I2C센서주소와 통신 개시하는 요청 전송
  Wire.write(0); //I2C센서의 요청을 읽겠다는 명령(0) 전송
  Wire.endTransmission(); //전송 완료(0값 전송 종료)
  
  //지정된 주소의 I2C 센서, 즉 온도 센서에서 읽기 모드로 1바이트 온도값 읽음
  Wire.requestFrom(temp_address, 1);
  //응답이 올 때까지 대기
  while(Wire.available() == 0);
  //온도 레지스터 값을 읽어와 변수 c에 저장
  int c = Wire.read();

  //섭씨를 화씨로 변환
  int f=round(c*9.0/5.0 +32.0);

  //시리얼 포트로 섭씨온도와 화씨온도 출력
  Serial.print(c);
  Serial.print("C");
  Serial.print(f);
  Serial.println("F");

  delay(500);

}
