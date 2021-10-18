//장애물의 거리를 감지하는 막대그래프 만들기

const int SER=8; //시프트 레지스터로 데이터를 입력하는 8번 핀 SER 상수 정의
const int LATCH=9; //LATCH 핀 LATCH 상수 정의
const int CLK=10; //CLOCK 핀 CLK 상수 정의
const int DIST=0; //아날로그 입력 0번 핀에 연결된 IR 센서의 장애물 거리값

//거리값에 따른 LED 패턴을 저장한 vals 배열 정의
int vals[9]={0,1,3,7,15,31,63,127,255};

//IR 센서의 장애물 거리 최댓값
int maxVal=500;

//IR 센서의 장애물 거리 최솟값
int minVal=0;

void setup()
{
    //시프트 레지스터에 연결된 핀들의 입출력 모드를 출력으로 지정
    pinMode(SER, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLK, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int distance=analogRead(DIST); //IR 센서에서 장애물 거리값을 읽음
    distance = map(distance, minVal, maxVal, 0, 8);
    distance = constrain(distance,0,8); //거리값 범위 조정
    digitalWrite(LATCH, LOW); //LATCH에 LOW 입력
    shiftOut(SER, CLK, MSBFIRST, vals[distance]); //거리값에 맞는 데이터 전송
    digitalWrite(LATCH, HIGH); //LATCH에 HIGH 입력 : 거리에 따라 LED 켜짐
    Serial.println(vals[distance]);
    delay(10);   // 장애물을 감지하는 시간 간격 지정
}
