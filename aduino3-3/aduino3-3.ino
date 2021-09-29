const int GLED = 9; //초록led: 9번핀
const int RLED = 10; //빨강led: 10번핀
const int YLED = 11; //노랑led: 11번핀
const int LIGHT = 0; //포토레지스터는 아날로그 입력 0번핀 사용
const int MIN_LIGHT = 200; //최저 조도값
const int MAX_LIGHT = 900; //최대 조도값

int val = 0; //포토레지스터가 읽은 조도값
float voltage = 0; //전압 레벨

void setup() {
  // pinmode로 3개의 led를 output으로 설정
  pinMode(GLED, OUTPUT); 
  pinMode(RLED, OUTPUT);
  pinMode(YLED, OUTPUT);

  //시리얼 통신 사용함수
  Serial.begin(9600);
}

void loop() {
  
  val = analogRead(LIGHT); //포토레지스터에서 조도값 읽기
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); //조도값을 매핑
  val = constrain(val, 0, 255); //조도값을 0~255 사이로 제한
  //조도값에 따른 led들의 밝기 변화
  analogWrite(GLED, val); 
  analogWrite(RLED, val);
  analogWrite(YLED, val);

  voltage = val*5.0/1024.0; //조도값을 통한 전압 레벨 구하기
  //시리얼 프린터로 조도값과 전압 레벨을 출력
  Serial.println("val:");
  Serial.println(val);
  Serial.println("voltage:");
  Serial.println(voltage);
  delay(1000);
}
