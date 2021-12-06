// I2C 온도 센서값을 읽어 LED 막대그래프로 온도 표현 -> [실습 8-2]
// Processing 프로그램으로는 PC 화면에 온도 표시 -> [실습 8-3]

//I2C 라이브러리 삽입
#include <Wire.h>

const int SER=8;   // 시프트 레지스터로 데이터를 입력하는 8번 핀 SER 상수 정의
const int LATCH=9; // LATCH 핀 LATCH 상수 정의
const int CLK=10;  // CLOCK 핀 CLK 상수 정의
int temp_address=72;

// LED 막대그래프에 표시할 온도값(기준) 배열 Val 선언
int vals[8] = {1,3,7,15,31,63,127,255};

void setup()
{
    // 시리얼 통신 시작
    Serial.begin(9600);

    // I2C Wire 객체 시작
    Wire.begin();
    //시프트 레지스터에 연결된 핀들의 입출력 모드를 출력으로 지정
    pinMode(SER, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLK, OUTPUT);
}

void loop()
{
    //I2C 센서의 주소와 통신을 개시하는 명령 전송
    Wire.beginTransmission(temp_address);
    //I2C 센서의 0번 레지스터를 읽겠다는 명령을 쓰기 모드에서 전송
    Wire.write(0);
    //전송 완료
    Wire.endTransmission();

    //지정된 주소의 I2C 센서에서 1바이트값을 읽음
    Wire.requestFrom(temp_address, 1);
    //응답이 올 때까지 대기
    while(Wire.available() == 0);
    //온도를 읽어 변수 c에 저장
    int c = Wire.read();
    //온도에 따른 LED 막대그래프 패턴 설정
    int graph = map(c, 20, 31, 0, 7);
    graph = constrain(graph,0,7);

    digitalWrite(LATCH, LOW); //LATCH에 LOW 입력
    shiftOut(SER, CLK, MSBFIRST, vals[graph]); //데이터 전송
    digitalWrite(LATCH, HIGH); //LATCH에 HIGH 입력

    //섭씨온도를 화씨온도로 변환
    int f=round(c*9.0/5.0 +32.0);
    Serial.print(c);
    Serial.print("C,");
    Serial.print(f);
    Serial.print("F.");

    delay(500);
}
