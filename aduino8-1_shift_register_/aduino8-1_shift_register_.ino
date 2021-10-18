const int SER=8;   // 시프트 레지스터로 데이터를 입력하는 8번 핀 SER 상수 정의
const int LATCH=9; // LATCH 핀 LATCH 상수 정의
const int CLK=10;  // CLOCK 핀 CLK 상수 정의

void setup()
{
    //시프트 레지스터에 연결된 각 핀의 입출력 모드를 출력으로 지정
    pinMode(SER, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLK, OUTPUT);

    digitalWrite(LATCH, LOW);   // LATCH에 LOW를 입력, 시프트 레지스터가 출력 동작 안 함
    // 비트값 1010101010 전송(맨 상위 비트 1를 먼저 전송) 
    shiftOut(SER, CLK, MSBFIRST, B10101010);
    // LATCH에 HIGH 입력: 시프트 레지스터가 출력 동작-즉, 홀수 LED들이 점등 
    digitalWrite(LATCH, HIGH); 
}

void loop()
{
    //loop문에서는 아무런 작업도 하지 않음
}
