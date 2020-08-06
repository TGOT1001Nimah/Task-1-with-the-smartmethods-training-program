
int left =8; //this is connected with npn 
int right =7;//the same like before but with the other npn

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
   // Wait for 1000 millisecond(s)
 
  digitalWrite(7, LOW);//the right directhon will off
  digitalWrite(8, HIGH);//the left direction on
  delay(2000); // Wait for 2000 millisecond
  digitalWrite(8, LOW);//then the right direction on 
  digitalWrite(7, HIGH);//left direction of
  delay(2000);//
  
  
}
