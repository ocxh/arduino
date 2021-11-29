//인터럽트 제어를 적용하여 버튼의 변화를 처리하는 프로그램

//버튼 핀 연결
const int BUTTON_INT= 0; //0번 인터럽트(Uno 보드는 2번 핀)을 사용
const int RED=11; //11번 핀을 사용하는 빨간색 LED 상수 정의
const int GREEN=10; //10번 핀을 사용하는 초록색 LED 상수 정의
const int BLUE=9; //9번 핀을 사용하는 파란색 LED 상수 정의

//인터럽트 내부에서 값을 변경할 수 있도록 휘발성 변수 선언
volatile int selectedLED=RED;

void setup()
{
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    //RISING 에지를 감지할 수 있도록 BUTTON_INT 핀 신호를 인터럽트로 설정
    attachInterrupt(BUTTON_INT, swap, RISING);
}
void swap()
{
    //현재 켜진 LED를 끔
    analogWrite(selectedLED, 0);
    //새로운 LED 선택
    if(selectedLED == GREEN)
        selectedLED=RED;
    else if(selectedLED == RED)
        selectedLED=BLUE;
    else if(selectedLED == BLUE)
        selectedLED=GREEN;
}

void loop()
{
    for(int i=0; i<256; i++)
    {
        analogWrite(selectedLED, i);
        delay(10);
    }
    for(int i=255; i>=0; i--)
    {
        analogWrite(selectedLED, i);
        delay(10);
    }
}
