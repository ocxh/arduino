//하드웨어 및 타이머 인터럽트를 사용하여 사운드 제어하기

//TimerOne 라이브러리 삽입
#include <TimerOne.h>

//버튼 핀 연결
const int BUTTON_INT= 0; //0번 핀(Uno 보드는 2번 핀)을 사용하는 인터럽트 버튼 상수 정의
const int SPEAKER=12; //12번 핀을 사용하는 스피커 상수 정의

//음계 설정
#define NOTE_C 65
#define NOTE_D 73
#define NOTE_E 82
#define NOTE_F 87
#define NOTE_G 98
#define NOTE_A 110
#define NOTE_B 123

//인터럽트 내에서 값이 변경될 휘발성 변수 선언
volatile int key= NOTE_C;
volatile int octave_multiplier=1;
void setup()
{
    //시리얼 통신 시작
    Serial.begin(9600);

    pinMode(SPEAKER, OUTPUT);
    //BUTTON_INT 핀에서 RISING EDGE를 감지하면 인터럽트가 발생하도록 설정
    attachInterrupt(BUTTON_INT, changeKey, RISING);

    //타이머 인터럽트 설정
    Timer1.initialize(500000); //0.5초로 타이머 설정
    Timer1.attachInterrupt(changePitch); //타이머 인터럽트가 발생하면 changePitch() 호출 실행
}

void changeKey()
{
    octave_multiplier=1;
    if(key == NOTE_C)
        key=NOTE_D;
    else if(key == NOTE_D)
        key=NOTE_E;
    else if(key == NOTE_E)
        key=NOTE_F;
    else if(key == NOTE_F)
        key=NOTE_G;
    else if(key == NOTE_G)
        key=NOTE_A;
    else if(key == NOTE_A)
        key=NOTE_B;
    else if(key == NOTE_B)
        key=NOTE_C;
}

//타이머 인터럽트 발생시 실행
void changePitch()
{
    octave_multiplier = octave_multiplier*2;
    if(octave_multiplier>16) octave_multiplier= 1;
    tone(SPEAKER, key*octave_multiplier);
}

void loop()
{
    Serial.print("Key: ");
    Serial.print(key);
    Serial.print(" Multiplier: ");
    Serial.print(octave_multiplier);
    Serial.print(" Frequency: ");
    Serial.println(key*octave_multiplier);
    delay(100);
}
