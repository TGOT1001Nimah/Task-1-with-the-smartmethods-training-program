#include <Stepper.h>
int spr = 20;//stepper steps
int D=0;
int x=0;
int c1= 10;//control one
int c2= 11;//control tow
Stepper stepper(spr, 3, 4, 8, 9);

void setup() {
  // put your setup code here, to run once:
stepper.setSpeed(60);//set the speed of the motor to 60 RPMs
}

void loop() {
  // put your main code here, to run repeatedly:
stepper.step(5);//right direction
delay(5000);
stepper.step(-5);//to left direction
delay(5000);
}
