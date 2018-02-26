/*
  Name: Ahmed Khan, 652469935
  
  Lab:  Lab 5 - Multiple Inputs and Outputs
  
  Description: 
    This lab we will be experimenting with multiple inputs and outputs.  
    There are two parts:
    1) 
      * Using 4 LEDS and a photoresistor.  
      * All 4 LEDs next to each (preferably the same color).  
      * As the amount of light seen by the photoresistor decreases, increase the number of LEDs that are lit.  
        * For example, if your circuit receives no light then all of the LEDs should light up.  
        * As you continue to increase the amount of light, the number of LEDs that light up will decrease.  
        * So when the photoresistor receives half the amount of light, 2 LEDS should be lit up, 
        * and when there is no light, all 4 LEDs should be lit up.
    
    2) In parallel with part 1, we will be using the the passive buzzer and the potentiometer.  
      * Use the potentiometer as an analog input and have the output come from another analog pin.  
      * Control the volume or tone of the buzzer by adjusting the potentiometer.  
      * Make sure to have code to control the output of the buzzer based on the potentiometer.

 
    Ranges of values the photoresistor provides:

    1 LED:   0-187
    2 LED: 188-375
    3 LED: 376-563
    4 LED: 564+
               
  Assumptions: 
               
  References:  
   https://www.arduino.cc/en/Reference/AnalogWrite
   https://www.arduino.cc/en/Reference/Map
   https://www.arduino.cc/en/Reference/AnalogRead
  
*/




// pin numbers for the 4 led's
const int led1 = 5;
const int led2 = 6;
const int led3 = 7;
const int led4 = 8;

// the number of the LDR pin
const int ldrPin = A0; 

void setup() 
{
  Serial.begin(9600);

  // initialize the LDR pin as an input
  pinMode(ldrPin, INPUT);

  // intialize led pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}

void loop() 
{
  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value
  Serial.println(ldrStatus);

  // turn all LED's off
  allOff();

  // check to see what led's to turn on
  if (ldrStatus >= 564)
  {
    oneOn();
  }
  else if (ldrStatus >= 376 && ldrStatus <= 563)
  {
    twoOn();
  }
  else if (ldrStatus >= 188 && ldrStatus <= 375)
  {
    threeOn();
  }
  else
  {
    allOn();
  }
  
  

  delay(1000);
}

void allOff()
{
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
void allOn()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}
void threeOn()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}
void twoOn()
{
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
}
void oneOn()
{
  digitalWrite(led1, HIGH);
}

