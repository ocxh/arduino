//I2C 온도 센서값을 출력하는 프로그램

import processing.serial.*;
Serial port;
String temp_c= "";
String temp_f= "";
String data= "";
int index=0;
PFont font;

void setup()
{
    size(400,400);
    // COM9는 아두이노가 연결된 실제 시리얼 포트로 변경
    port=new Serial(this, "COM9", 9600);
    port.bufferUntil('.');
    //폰트 이름은 [그림 8-9]에서 실제로 만든 것으로 변경
    font = loadFont("AgencyFB-Bold-200.vlw");
    textFont(font, 200);
}
void draw()
{
    background(0,0,0);
    fill(46, 209, 2);
    text(temp_c, 70, 175);
    fill(0, 102, 153);
    text(temp_f, 70, 370);
}

void serialEvent(Serial port)
{
    data = port.readStringUntil('.');
    data = data.substring(0, data.length()-1);

    //아두이노에서 전송된 섭씨온도와 화씨온도를 구분하는 ','를 찾아 배열로 처리
    index = data.indexOf(",");
    //섭씨를 저장
    temp_c = data.substring(0, index);
    //화씨를 저장
    temp_f = data.substring(index+1, data.length());
}
