/*
  Name: Ahmed Khan, 652469935
  Lab:         Lab 6 - Communication
  Description: gets the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. 
               displays date and time on the 16x2 display
               keeps accurate time on 16x2 display 
  Assumptions: I initially assumed that reading from the serial monitor would be like C++ and there would be no need for a
               a buffer, but there is. Also using a peek() function for strings came in handy.

                MONTH     MONTH #     DAYS IN MONTH  
                January     1              31       
                February    2              28
                March       3              31
                April       4              30
                May         5              31
                June        6              30
                July        7              31
                August      8              31
                September   9              30
                October     10             31
                November    11             30
                December    12             31

  References:  https://github.com/PaulStoffregen/Time
               https://www.arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
               https://www.arduino.cc/en/Serial/Available#.UwYy2PldV8E
               https://www.arduino.cc/reference/en/language/functions/communication/serial/#.UwYyzfldV8E        
*/

#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int timeDisplay = 0;
int days = 0;          
int months = 0;        
int years = 0;          
int seconds = 0;
int minutes = 0;
int hours = 0;
bool flag = false;

void setup() 
{
  lcd.begin(16, 2);     // tell the system that we are using a 16x2 lcd
  Serial.begin(9600);
  Serial.println("Enter valid date & time in this format:\nmm/dd/yyyy hr:mm:ss");

}

void loop() 
{ // open
  
  while (Serial.available() > 0)
  { // open while loop

    // parse the user input
    months  = Serial.parseInt();  
    days    = Serial.parseInt();   
    years   = Serial.parseInt();   
    hours   = Serial.parseInt();    
    minutes = Serial.parseInt();   
    seconds = Serial.parseInt();   

    // error check input date
    if (checkYear(years) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Year");
      break;
    }
    else if (checkMonth(months) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Month");
      break;
    }
    else if (checkDay(months, days) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Year");
      break;
    }
    
    // error check input time
    if (checkHour(hours) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Hours");
      break;
    }
    else if (checkMinSec(minutes) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Minutes");
      break;
    }
    else if (checkMinSec(seconds) == 0)
    {
      lcd.clear();
      lcd.print("Invalid Seconds");
      break;
    }
    
    // date and time are valid
    setTime(hours,minutes,seconds,days,months,years);
    flag = true;  
    
  } // close while loop

  // start timer, print to LCD
  if (flag == true)
  {
    time_t t = now();
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Time: ");
    lcd.print(hour(t));
    lcd.print(":");
    lcd.print(minute(t));
    lcd.print(":");
    lcd.print(second(t));

    lcd.setCursor(0, 1);
    
    lcd.print("Date: ");
    lcd.print(month(t));
    lcd.print("/");
    lcd.print(day(t));
    lcd.print("/");
    lcd.print(year(t));
    
    delay(1000);
  }
} // close


// returns 1 if year is valid, 0 otherwise
int checkYear(int y)
{
  if (y < 1000 || y > 9999)
    return 0;
  else
    return 1;
}

// returns 1 if month is valid, 0 otherwise
int checkMonth(int m)
{
  if (m >= 1 && m <= 12)
    return 1;
  else 
    return 0;
} 

// returns 1 if day is valid, 0 otherwise
int checkDay(int m, int d)
{
    // months that have 31 days 
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
      if (d >= 1 && d <= 31)
        return 1;
    }
    // months that have 30 days
    else if (m == 4 || m == 6 || m == 9 || m== 11)
    {
      if (d >= 1 && d <= 30)
        return 1;
    }
    // months that have 28 days
    else if (m == 2)
    {
      if (d >= 1 && d <= 28)
        return 1;
    }
    else
    {
      return 0;
    }
}

// returns 1 if hour is valid, 0 otherwise
int checkHour(int h)
{
  if (h >= 0 && h < 24)
    return 1;
  else
    return 0;
}

// returns 1 if minute/second is valid, 0 otherwise
int checkMinSec(int t)
{
  if (t >= 0 && t <= 59)
    return 1;
  else
    return 0;
}
