

#include <Servo.h> //this is the labrary for servo motor

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);          //  setup serial
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Servo knob demo by Robojax.com
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print(val);
  Serial.print(" ");                   //to print the value of th potentiometer on serial 
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) note that the result came out from 1023/6
  myservo.write(val);                  //write means your servo will works in reality 

  //her we will set the servo position according to the scaled value
  Serial.print(val); 
  Serial.println();
  delay(200); // waits for the servo to get anither results

}
