/*

  Name: Ahmed Khan, 652469935
  
  Lab:         Lab 4 - More Complicated Input
  
  Description: 
    A circuit and program that will use a photoresistor and the 16x2 display. The display states the relative amount of 
    light in the room (dark, partially dark, medium, partially light, fully lit.) in the room, or fully lit, or somewhere 
    in between should be displayed based on the value read from the photocell. 
    Ranges of values the photoresistor provides:
      dark:             0-100 
      partially dark: 101-301
      medium:         302-502  
      partially lit:  503-703  
      fully lit:      704+  
               
  Assumptions: 
    I first assumed that the photoresistor would only need two wires, one for 5v and 1 for ground (maybe a resistor),
    but it ended up needing an extra wire after the resistor in order to connect to the A0 analog pin.
    I pretty much figured that I would need to figure out how to use the photoresistor, and then connect the same
    components as lab 3 for the lcd, and just write what the lighting is.
               
  References:  
   http://playground.arduino.cc/Learning/PhotoResistor
   https://learn.adafruit.com/photocells
  
*/

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ldrPin = A0; // the number of the LDR pin

void setup() 
{

  Serial.begin(9600);
  pinMode(ldrPin, INPUT);                // initialize the LDR pin as an input

  lcd.begin(16, 2);                      // tell the system that we are using a 16x2 lcd
  lcd.print("Ahmed Khan-Lab 4");         // print name on the first line
  lcd.setCursor(0, 1);                   // move down to the second row
}

void loop() 
{
  lcd.clear();                          // clear any content that was previously on the lcd
  lcd.print("Ahmed Khan-Lab 4");        // print name on the first line
  lcd.setCursor(0, 1);                  // move down to the second row
  
  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  if (ldrStatus >= 704)                            // fully lit
  {
    Serial.println("fully lit");
    Serial.println(ldrStatus);
    lcd.print("Fully Lit");
  }
  else if (ldrStatus >= 503 && ldrStatus <= 703)   // partially lit
  {
    Serial.println("partially lit");
    Serial.println(ldrStatus);
    lcd.print("Partially Lit");
  }
  else if (ldrStatus >= 302 && ldrStatus <= 502)   // medium
  {
    Serial.println("medium lit");
    Serial.println(ldrStatus);
    lcd.print("Medium");
  }
  else if (ldrStatus >= 160 && ldrStatus <= 301)  // partially dark
  {
    Serial.println("partially dark");
    Serial.println(ldrStatus);
    lcd.print("partially dark");
  }
  else                                            // dark
  {
    Serial.println("dark");
    Serial.println(ldrStatus);
    lcd.print("dark");
  }

  // delay a second before the next reading is done
  delay(1000);
  
} // close loop
