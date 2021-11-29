//아두이노에서 타이머 인터럽트 사용하기

#include <TimerOne.h>
const int LED=13;

void setup()
{
    pinMode(LED, OUTPUT);
    Timer1.initialize(1000000); //타이머를 1000000초(1초)로 설정
    Timer1.attachInterrupt(blinky); //타이머 인터럽트가 발생할 때마다 blinky() 호출
}

void loop()
{
    //공란이나 원하는 코드 입력
}

//타이머 인터럽트시 실행
void blinky()
{
    digitalWrite(LED, !digitalRead(LED)); //LED 켜짐 상태 바꿈
}
