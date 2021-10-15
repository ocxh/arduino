import processing.serial.*;
PImage img;
Serial port;

void setup(){
 size(640, 256);
 img = loadImage("hsv.jpg");
 port = new Serial(this, "COM3", 9600);
}

void draw(){
 background(0);
 image(img, 0, 0);
}

void mousePressed(){
 color c = get(mouseX, mouseY);
 
 int r = int(map(red(c), 0, 255, 0, 100));
 int g = int(map(green(c), 0, 255, 0, 100));
 int b = int(map(green(c), 0, 255, 0, 100));
 
 String colors = r+","+g+","+b+"\n";
 print(colors);
 port.write(colors);
}
