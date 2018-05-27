/* 
 *  Edgar Martinez-Ayala, Emart9@uic.edu
 *  U. of Illinois, Chicago
 *  Spring 2018
 */

// include the library code:
#include <LiquidCrystal.h>
#include <TimeLib.h>
#include <Time.h>

// Initialize the library by associating LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Global variables that hold the date and time
int iMonth = 0;
int iDay = 0;
int iYear = 2018;  //preset
int iHour = 0;
int iMin = 0;
int iSecond = 00;  //preset
int inputWorks = 0;
int counter = 0;

int ipastState = 1;           // last value of the increment button
int spastState = 0;           // last value of the set button
int timeState = 0;
int incomingByte;            // a variable to read incoming serial data into

const int ibuttonPin = 6;     // the number of the pushbutton pin
const int sbuttonPin = 7;     // the number of the pushbutton pin
const int ledPin = 8;       // the number of the LED pin


void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16, 2);     
  pinMode(ibuttonPin, INPUT);
  pinMode(sbuttonPin, INPUT);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (inputWorks == 0){
    // check if data in right format
    while(iMonth == 0){
      lcd.clear();
      lcd.println("Enter Month:");
      countClicks();   //counts user input
      if(counter > 0 && counter < 13){  //if Month is correct
        iMonth = counter; 
        counter = 0;
        lcd.clear();
        lcd.println("Month Set");
        lcd.setCursor(0,1);
        lcd.println(iMonth);
        delay(1000);
        break;
      }
      lcd.clear();
      lcd.println("Invalid Month");
      counter = 0;
      delay(1000);
    }
    while(iDay == 0){  
      lcd.clear();
      lcd.println("Enter Day:");
      countClicks();
      if(dayInMonth(counter, iMonth) != 1){  //if Month is correct
        iDay = counter; 
        counter = 0;
        lcd.clear();
        lcd.println("Day Set");
        lcd.setCursor(0,1);
        lcd.println(iDay);
        delay(1000);
        break;
      }
      lcd.clear();
      lcd.println("Invalid Day");
      counter = 0;
      delay(1000); 
    }
    while(iHour == 0){
      lcd.clear();
      lcd.println("Enter Hour:");
      countClicks();
      if(counter > 0 && counter < 24){  //if Month is correct
        iHour = counter; 
        counter = 0;
        lcd.clear();
        lcd.println("Hour Set");
        lcd.setCursor(0,1);
        lcd.println(iHour);
        delay(1000);
        break;
      }
      lcd.clear();
      lcd.println("Invalid Hour");
      counter = 0;
      delay(1000); 
    }
    while(iMin == 0){
      lcd.clear();
      lcd.println("Enter Min:");
      countClicks();
      if(counter > -1 && counter < 60){  //if Month is correct
        iMin = counter;
        counter = 0;
        lcd.clear();
        lcd.println("Min Set");
        lcd.setCursor(0,1);
        lcd.println(iMin);
        delay(1000);
        break;
      }
      lcd.clear();
      lcd.println("Invalid Min");
      counter = 0;
      delay(1000); 
    }

    // Data entered correctly 
    setTime(iHour,iMin,iSecond,iDay,iMonth,iYear);
    inputWorks = 1;
  }

  if (inputWorks == 1){
    time_t cTime = now();
    lcd.clear();            // Clear LCD
    
    // Display Date
    lcd.setCursor(0,0);     // Set to first line
    lcd.print("Date: ");
    lcd.print(month(cTime));
    lcd.print("/");
    lcd.print(day(cTime));
    
    // Display Time
    lcd.setCursor(0, 1);    //Set to second line
    lcd.print("Time: ");    

    if (hour(cTime) <= 12)
      lcd.print(hour(cTime)); 
    else
      lcd.print(hour(cTime) - 12);
    lcd.print(":");
    if(minute(cTime) < 10){
      lcd.print("0");
      lcd.print(minute(cTime));
    }
    else{
      lcd.print(minute(cTime));
    }

    if (hour(cTime) < 12)
      lcd.print(" AM");
    else
      lcd.print(" PM");
    // wait a bit
    delay(1000);
  }

  //insert here 
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }

  if(timeState == 0){
    String hr = convert(iHour);
    String mn = convert(iMin);

    Serial.print(hr[0]);
    Serial.print(hr[1]);
    Serial.print(mn[0]);
    Serial.print(mn[1]);
    
    timeState = 1; 
  }
}

// Adds the number of clicks 
void countClicks(){  
  while(digitalRead(sbuttonPin) == spastState){
    if(digitalRead(ibuttonPin) == ipastState){
      counter++;
      lcd.clear();
      lcd.println("#:");
      lcd.setCursor(0,1);
      lcd.println(counter);
      delay(400);
    }
  }
}

String convert(int val){
  String s = String(val);
  if (val < 10){
    char arr[2];
    char tmp = s[0];
    arr[0] = '0';
    arr[1] = tmp;
    return String(arr);
  }
  else
    return s;
}


// Checks if the date entered is in the entered month
int dayInMonth(int day, int month){
  // Months with 31 days 
  if (month== 1 || month == 3 || month== 5 || month == 7 ||
        month == 8 || month == 10 || month == 12){
          if (day < 1 || day > 31){
            return 1; 
          }
  }
  // Months with 30 days
  else if (month == 4 || month == 6 || month == 9 || month== 11){
    if (day < 1 || day > 30){
      return 1;
    }
  }
  // Month with 28 days
  else if (month == 2){
    if (day < 1 || day > 28)
      return 1;
  }
  // Date entered is in month
  return 0;
}
