/*
 * REFERENCES
 * Melody code and pitches.h code found at: https://www.arduino.cc/en/Tutorial/PlayMelody
 * Time Library Source Code and Documentation found at: https://github.com/PaulStoffregen/Time
 * Serial.available() example found at:  https://www.arduino.cc/en/Serial/Available#.UwYy2PldV8E
 * convert function code found at: https://stackoverflow.com/questions/929103/convert-a-number-range-to-another-range-maintaining-ratio
*/

    //    months  = Serial.parseInt();  
    //    days    = Serial.parseInt();   
    //    years   = Serial.parseInt();   
    //    hours   = Serial.parseInt();    
    //    minutes = Serial.parseInt();   
    //    seconds = Serial.parseInt();  

#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>
#include "pitches.h"

//---------------------------------------------------------------------
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 11, d4 = 5, d5 = 4, d6 = 7, d7 = 6;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//---------------------------------------------------------------------
// time variables
int hr1 = -2;
int hr2 = -2;
int mn1 = -2;
int mn2 = -2;

int days = 15;          
int months = 3;        
int years = 2018;          
int seconds = 0;
int minutes = 0;
int hours = 0;
// boolean used to see whether or not the initial time has been set
bool timeFlag = false;
//---------------------------------------------------------------------
// alarm variables
int alarmHour = 0;
int alarmMin = 0;
int alarmAmPm = 0;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

const int poten = A3;
const int buzzPin = 12;
const int snoozeBtnPin = 2;
const int setAlarmBtnPin = 3;
const int cycleBtnPin = 9;

// max and min values for the analog potentiometer
const int oldMin = 0;
const long int oldMax = 1023;

// variables that change during interrupts
volatile int alarmFlag = 0;
volatile int setFlag = 0;
//---------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(snoozeBtnPin, INPUT);
  pinMode(cycleBtnPin, INPUT);
  pinMode(poten, INPUT);
  attachInterrupt(digitalPinToInterrupt(snoozeBtnPin), alarmInterrupt, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(setAlarmBtnPin), setInterrupt, CHANGE); 
  //Serial.println("Enter valid date & time in this format:\nmm/dd/yyyy hr:mm:ss");
  lcd.print("Waiting");
  lcd.setCursor(0, 1);
  lcd.print("for time");
}

void loop() {
  
  if (Serial.available() > 0){ 
    if (hr1 == -2)
      hr1 = Serial.read();
    else if (hr2 == -2)
      hr2 = Serial.read();
    else if (mn1 == -2)
      mn1 = Serial.read();
    else if (mn2 == -2)
      mn2 = Serial.read();

//    if (!dateErrorCheck(years, months, days, hours, minutes, seconds)){
//      //break;
//    }

    //setTime(hours, minutes, seconds, days, months, years);

    if (hr1 != -2 && hr2 != -2 && mn1 != -2 && mn2 != -2){
      hours = turnToNum(hr1, hr2);
      minutes = turnToNum(mn1, mn2);
      setTime(hours, minutes, seconds, days, months, years);
      timeFlag = true;  
    }
  } 
  
  if (timeFlag){
    // update the time
    time_t curTime = now();
    //printTime(curTime);
    printAlarmStatus();
    
    // check if the button to set an alarm has been clicked
    if (setFlag == 1){
      setAlarm();
      Serial.print("H");
      setFlag = 0;
    }

    // check if the alarm conditons have been met
    if (second(curTime) == 0 && minute(curTime) == alarmMin){
      if (alarmAmPm == 0 && hour(curTime) == alarmHour)
        alarmFlag = 1;
      else if (alarmAmPm == 1 && hour(curTime)- 12 == alarmHour)
        alarmFlag = 1;
    }

    // check if we should sound the alarm
    if (alarmFlag == 1){
      soundAlarm();
    }
      
   
    delay(1000);
  }
}

// interrupt for digital pin 2
// turns off all alarm variables
void alarmInterrupt(){
  alarmFlag = 0;
  alarmHour = 0;
  alarmMin = 0;
  Serial.print("L");
}
// interrupt for digital pin 3
// sets the flag to allow user to enter an alarm
void setInterrupt(){
  setFlag = 1;
}

int turnToNum(int num1, int num2){
  char first = (char)num1;
  char sec = (char)num2;

  String inString = "";
  
  if (first == '0'){
    inString += sec;
  }
  else{
    inString += first;
    inString += sec;  
  }
  return inString.toInt();  
}

void printAlarmStatus(){
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (alarmHour == 0 && alarmMin == 0){
    lcd.print("No active alarm");
  }
  else{
    lcd.print("Active alarm for");
    lcd.setCursor(0, 1);
    lcd.print(alarmHour);
    lcd.print(":");
    if (alarmMin < 10){
      lcd.print("0");
      lcd.print(alarmMin);
    }
    else
      lcd.print(alarmMin);
    lcd.print(" ");
    if (alarmAmPm == 0)
      lcd.print("AM");
    else
      lcd.print("PM");
  }
}

// sets the current alarm variables
void setAlarm(){
  delay(500);
  int val = 0;
  val = waitForClick(1, 12);
  alarmHour = convert(val, 1, 12);
  delay(500);
  val = 0;
  val = waitForClick(0, 59);
  alarmMin = convert(val, 0, 59);
  delay(500);
  val = 0;
  val = waitForClick(-1, -1);
  alarmAmPm = amPm(val);
}

// helper function used by setAlarm()
int waitForClick(int minVal, int maxVal){
  int cur = 0, prev = 0, potenStatus = 0;
  while (1){
    lcd.clear();
    lcd.setCursor(0, 0);
    
    potenStatus = analogRead(poten);

    if (maxVal == -1){
      lcd.setCursor(0, 1);
      if (amPm(potenStatus) == 0)
        lcd.print("AM");
      else
        lcd.print("   PM");
    }
    else if (maxVal == 12){
      lcd.print("HOUR");
      lcd.setCursor(0, 1);
      lcd.print(convert(potenStatus, minVal, maxVal));
    }
    else{
      lcd.print("MINUTE");
      lcd.setCursor(0, 1);
      lcd.print(convert(potenStatus, minVal, maxVal));
    }
    
    cur = digitalRead(cycleBtnPin);
    if (cur != prev){
      if (cur == HIGH){
        return potenStatus;
      }
      delay(100);
    }
    prev = cur;
    delay(100);
  }
}

// converts an integer from an old range of values to a new range of values
int convert(int oldVal, int newMin, long int newMax){
  int newVal = (((oldVal - oldMin) * (newMax - newMin)) / (oldMax - oldMin)) + newMin;
  return newVal;
}

int amPm(int val){
  if (val < 512)
    return 0;
  else
    return 1;
}

// activates the alarm to the active buzzer
void soundAlarm(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    if (alarmFlag == 0)
      return;
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzPin, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzPin);
  }
}

// prints the current time in the serial monitor
void printTime(time_t t){
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Time: ");

  if (hour(t) > 12)
    lcd.print(hour(t) - 12);
  else
    lcd.print(hour(t));
    
  lcd.print(":");
  lcd.print(minute(t));
  lcd.print(" ");

  if (hour(t) < 12)
    lcd.print("AM");
  else
    lcd.print("PM");
  
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(month(t));
  lcd.print("/");
  lcd.print(day(t));
  lcd.print("/");
  lcd.print(year(t));
    
//  Serial.print("Time: ");
//  Serial.print(hour(t));
//  Serial.print(":");
//  Serial.print(minute(t));
//  Serial.print(":");
//  Serial.print(second(t));
//  Serial.print("  Date: ");
//  Serial.print(month(t));
//  Serial.print("/");
//  Serial.print(day(t));
//  Serial.print("/");
//  Serial.println(year(t));
}

/*
 * VALID DAYS IN A MONTH 

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
 */
 
// returns false if any of the given values doesn't satisfy it's personal requirements
// returns true otherwise
bool dateErrorCheck(int years, int months, int days, int hours, int minutes, int seconds){
  if (checkYear(years) == 0)
    return false;
  else if (checkMonth(months) == 0)
    return false;
  else if (checkDay(months, days) == 0)
    return false;
  if (checkHour(hours) == 0)
    return false;
  else if (checkMinSec(minutes) == 0)
    return false;
  else if (checkMinSec(seconds) == 0)
    return false;
  else
    return true;
}

// returns 1 if year is valid, 0 otherwise
int checkYear(int y){
  if (y < 1000 || y > 9999)
    return 0;
  else
    return 1;
}

// returns 1 if month is valid, 0 otherwise
int checkMonth(int m){
  if (m >= 1 && m <= 12)
    return 1;
  else 
    return 0;
} 

// returns 1 if day is valid, 0 otherwise
int checkDay(int m, int d){
    // months that have 31 days 
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
      if (d >= 1 && d <= 31)
        return 1;
    }
    // months that have 30 days
    else if (m == 4 || m == 6 || m == 9 || m== 11){
      if (d >= 1 && d <= 30)
        return 1;
    }
    // months that have 28 days
    else if (m == 2){
      if (d >= 1 && d <= 28)
        return 1;
    }
    else{
      return 0;
    }
}

// returns 1 if hour is valid, 0 otherwise
int checkHour(int h){
  if (h >= 0 && h < 24)
    return 1;
  else
    return 0;
}

// returns 1 if minute/second is valid, 0 otherwise
int checkMinSec(int t){
  if (t >= 0 && t <= 59)
    return 1;
  else
    return 0;
}
