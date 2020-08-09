
#include <Servo.h> //this is  a servo library


//for servo 1
Servo servo1; 

const int servo1Pin = 3;// Must use PWM enabled pin

//for servo 2 
Servo servo2; 

const int servo2Pin = 5;// Must use PWM enabled pin
const int L1 = 10;//it is a hypothetical number for the length of the first arm
const int L2 = 15;//it is a hypothetical number for the length of the second arm
int x,y;//these tow point location in a coordinate system which takes from equation down 
const int Q = 20;
float q2,q1;//variables depending on x and y values 
double Q1,Q2,m;//variables depending on x and y values which they are the angulars to make both of the servo move
#include<Key.h>//keypad laibrarry
#include<Keypad.h>//keypad laibrarry
const byte ROWS = 4;//difin that it have 4 rows
const byte COLS = 4;//difin ut have 4 clos
byte rowPins[] ={6,7,8,9}; //pins 
byte colPins[] ={A5,A4,A3,A2};//pins
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins , colPins , ROWS ,COLS); //difine your keypad 

void setup(){
  Serial.begin(9600);
  pinMode(13,1);
    servo1.attach(servo1Pin); //difine the servo1
  servo2.attach(servo2Pin);  //difine the servo2 

}
void loop(){
  label1:
     while (x ==0){x=customKeypad.getKey();}{  //while you add a number from keypad
    Serial.print(x);
    Serial.println(" = x ");}
    while (y ==0){y=customKeypad.getKey();}{ //while you add a number from keypad
    Serial.print(y);
    Serial.println("  = y ");}
       m=(pow(x,2)+pow(y,2)-pow(L1,2)-pow(L2,2))/(2*L1*L2);//sulving equatione by useing your constant and chosing values
      q2 =(1/cos(m));
      Q2 = q2*180/PI;
      Serial.print(Q2);
      Serial.println(" = Q2 ");
     
      Q1=Q-Q2;
      Serial.print(Q1);
      Serial.println(" = Q1 ");
     servo1.write(Q1);//after valus result the both servo will move by the Q1 and Q2 values
      servo2.write(Q2);
     delay(500); //wait a 5 second
       x = 0;//her it will return to be 0 for x and y to bake again with new chossing values
     y = 0;
     delay (2000);
   
       goto label1;
    }
    


