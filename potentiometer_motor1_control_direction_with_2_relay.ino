
int sensorValue = 0;//this is for potentiometer
int potvalue = 125;//a value for potentiometer depending on it is resistration which is half 255 komh

void setup()
{
  pinMode(A0, INPUT);//define the potentiometer as input
  pinMode(4, OUTPUT);//difine the pin in relay 1 for right direction
  pinMode(5, OUTPUT);//difine the pin in relay 2 for left direction
}

void loop()
{
  sensorValue = analogRead(A0);//her it will takes the value from A0 pin 
  Serial.print(sensorValue);//it show you the value from A0 to let you know if less or more than 125
  if (sensorValue == potvalue)//her if the value equal 125 poth relay pin will be open
  {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
 else
  {
  	if (sensorValue < potvalue) //but if the value less than 125 the motor will be in right direction
  	{
    	digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  	}
  	else ////els mean  if it is  more than 125 the motor will be in left direction
  	{
    	digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
  	}
  }
}
  
