 
int in2Pin = 9;       // Define pins used for L293D,these pins its input pins 
int in1Pin = 10;
int enable1Pin = 11;
 
int dir = 0;  // Define variables for motor direction 
int spd = 0; //Difine variables for motor, and it's for speed
 
void setup()
{
  pinMode(in2Pin, OUTPUT);  //Define pin modes all of them are out put 
  pinMode(in1Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}
 
void loop() {
  int potInput = analogRead(A0);  // Read potentiometer value which is bu it we controll the speed and dirwction 
  spd = map(abs(potInput - 512), 0, 512, 0, 255); // Calculate motor speed, pot travel from midpoint(512) so the poth sid will be 255
  if (potInput > 512) // Compare to potentiometer midpoint to get motor direction
    dir = 0;
  else
    dir = 1;
  driveMotor(); //Call function to drive motor at calculated speed and direction
}
 
void driveMotor() // this is the function of direction in L239D pins
{
  if (dir)
  {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else
  {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  analogWrite(enable1Pin, spd);
}
