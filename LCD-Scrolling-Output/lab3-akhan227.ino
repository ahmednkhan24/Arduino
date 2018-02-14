// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);           // tell the system that we are using a 16x2 lcd
  lcd.print("Ahmed Khan");    // print name on the first line
  lcd.setCursor(0, 1);        // move down to the second row
}

String quote = "Artificial intelligence is no match for natural stupidity. - Unknown";


void loop() 
{
  lcd.setCursor(0, 1);    // stay on the second line

  for (int i = 0; i < quote.length() - 16; i++)
  {
    lcd.setCursor(0, 1);   
    
    // loop for scrolling through message 
    for (int j = i; j < i + 16;  j++)
    {
      lcd.print(quote[j]);
    }
    delay(400);
  }  
}
