#include <Servo.h>//the laibrarry of servo otor
Servo motor; //difine servo motor
int tr=10,ec=9;//pins of ultrasonice sensore
int d=0;//variable of distance
int x =0; //the duration of the pulse
void setup() {
  // put your setup code here, to run once:
motor.attach(3);//motor servo pin
pinMode(tr, OUTPUT);
pinMode(ec,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(tr,LOW);//in each toe second it will on and off 
//delay(500);
delayMicroseconds(10);
digitalWrite(tr,HIGH);
//delay(1000);
delayMicroseconds(200);
digitalWrite(tr,LOW);
x=pulseIn(ec,HIGH);
d=x*0.034/2;//determine the distance in cm
Serial.print("Distance");
Serial.println(d);
if (d<300 && d>200){//range of small box
  motor.write(135);
}
else if (d<199 && d>100) {//range of mediam box
  motor.write(90);
}
else if (d<99 && d>0){//range of large box
  motor.write(45);
}
}

