/*
  Name: Ahmed Khan, 652469935
  Lab:         Lab 8 - Interrupts
  Description: A program for the arduino that utilizes interrupts. 
               * When no button has been pressed my 16x2 display says "Waiting for X seconds", where X will be updated as time goes on.
               * When the red button is pressed, the display should display “Interrupt received! Press the yellow button to continue”
               * When the yellow button is pressed, the display goes back to displaying "Waiting for X seconds", and restarts the time at 0 seconds.
               
  Assumptions: I initially assumed that interrupts need to be called like regular functions, but they're actually given to the 'attachInterrupt' function
                and are automatically called when the interrupt condition has been met.

  References: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
              https://www.arduino.cc/reference/en/language/functions/time/millis/
              https://www.youtube.com/watch?v=9VZUb5cMrV0
      
*/

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 7, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

volatile int interruptFlag = 0;
volatile int seconds = 0;

// red button: interrupt button - press to interrupt the timer
// yellow button: reset button - press to reset the timer
const int redBtn = 3;
const int yelBtn = 2;

void setup()
{
  lcd.begin(16, 2);
  
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(yelBtn, INPUT_PULLUP); 

  attachInterrupt(digitalPinToInterrupt(redBtn), INTERRUPT, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(yelBtn), RESET, CHANGE);
}

void loop()
{
  if (interruptFlag == 0)
    wait();
  else
    received();
}

// display how many seconds the arduino has been waiting for
void wait()
{
  interruptFlag = 0;
  lcd.setCursor(0, 0);
  lcd.print("Waiting for: ");
  lcd.setCursor(0, 1);
  lcd.print(seconds);
  lcd.print(" seconds");

  seconds++;

  delay(1000);
  lcd.clear();
}

// called when the interrupt process is still active
void received()
{
  lcd.setCursor(0, 0);
  lcd.print("InteruptReceived");
  lcd.setCursor(0, 1);
  lcd.print("Press yellow btn");
  delay(100);
  lcd.clear();
}

// called when the red button is pressed
void INTERRUPT()
{
  interruptFlag = 1;
}

// called when the yellow button is pressed
void RESET()
{
  if (interruptFlag == 1)
  {
    seconds = 0;
    interruptFlag = 0;
  }
}
