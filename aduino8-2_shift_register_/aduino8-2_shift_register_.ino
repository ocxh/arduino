const int SER=8;
const int LATCH=9;
const int CLK=10;
int seq[14]={1,2,4,8,16,32,64,128,64,32,16,8,4,2};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
    for(int i=0; i<14; i++)
    {
        digitalWrite(LATCH, LOW); //LATCH에 LOW 입력
        shiftOut(SER, CLK, MSBFIRST, seq[i]); //seq[] 배열의 인덱스(i)값 전송
        digitalWrite(LATCH, HIGH); //LATCH에 HIGH 입력
        delay(100); //LED 조명 효과 속도 조절
    }

}
