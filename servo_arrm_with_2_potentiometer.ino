
//forward way for arms dippending on the angulars
#include <Servo.h> //this is  a servo library

//for servo 1
Servo servo1; 
const int servo1PotPin =A0;//this is th potentiometer which by it will give an angular q1
const int servo1Pin = 3;// Must use PWM enabled pin
int q1;//the angular of potentiometarin pin A0

// servo 1 settings END

//for servo 2 
Servo servo2; 
const int servo2PotPin =A1;//this is th potentiometer which by it will give an angular q2
const int servo2Pin = 5;// Must use PWM enabled pin
int q2;//the angular of potentiometarin pin A1
//servo 1 settings END
int L1 = 30;//it is a hypothetical number for the length of the first arm
int L2 = 15;//it is a hypothetical number for the length of the second arm
float x,y;//these tow point location in a coordinate system which takes from equation down 
void setup() {
   Serial.begin(9600); //the page can show you the X and Y value with angulars 
  servo1.attach(servo1Pin); //difine the servo1
  servo2.attach(servo2Pin);  //difine the servo2 
}

void loop() {
  
  q1 = analogRead(servo1PotPin); //the angular came from the potentiometer pin
 
  x = L1 * cos(q1) +L2 * cos(q1 + q2);//equation for X 
  Serial.print(x);//will print the value in the page 
  Serial.println(" =x ");//printed in diffrent line each time
  q1 = map(q1, 0, 1023, 0, 180);//1023 it's for potintiometer equivalent to servo andular 180
  Serial.print(q1);//printed on page 
  Serial.println(" ");
  servo1.write(q1);//appleing it on servo
  //the same thing for q2 and equation y 
  q2 = analogRead(servo2PotPin);
  Serial.print(q2);
  Serial.println("  ");
  y = L1 * sin(q1) +L2 * sin (q1 + q2);
  Serial.print(y);
  Serial.println("=y  ");
  q2 = map(q2, 0, 1023, 0, 180);
  Serial.print(q2);
  Serial.println("  ");
  servo2.write(q2);
  //in each value wait for 5 second
  delay(500);
  
}// loop end

