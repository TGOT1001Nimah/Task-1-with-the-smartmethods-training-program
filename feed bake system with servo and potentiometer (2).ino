#include <Servo.h>
Servo motor;//this is the difine of servo object
int x,y; //variables use it in voide loop (x)from the potintiometer 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
motor.attach(6);//servo pin
pinMode(A0, INPUT);//potintiometer analoge pin

}

void loop() {
  // put your main code here, to run repeatedly:
x = analogRead(A0);//the values came from potintiometer
y =map(x, 0, 1023, 0, 180);//her y will take it value from the rotation of servo 

  Serial.println(y);//this will show us line of y value in plotter
  Serial.print("");  
  Serial.println(x);//other line in plotter but if we delleted you will see y line only
  //the tow lines will be duple an thike becuse the servo will copy the potintiometer moves so they will be the same
  delay(500);
  motor.write(y);//to make your servo move depending of the movment of potentiometer
}

