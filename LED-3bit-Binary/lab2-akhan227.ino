// Ahmed Khan, akhan227, 652469935
// CS 362 - Lab 2 - Spring 2018

// When you reach 0 all LED's are off
// When you go beyond 0, all LED's flash every 0.3 seconds
// When you reach 7 all LED's are off
// When you go beyond 7, all LED's flash every 0.3 seconds

// LED PIN NUMBERS
const int MSD = 5;  // left most led, representing 4's place
const int mid = 6;  // middle led, representing 2's place
const int LSD = 7;  // right most led, representing 1's place

// BUTTON PIN NUMBERS
const int incrementButton = 2;  // button for incrementing
const int decrementButton = 3;  // button for decrementing

// binary representation of the digits
int MSDBin = 0;
int midBin = 0;
int LSDBin = 0;

int incState = 0;       // reads value from increment button
int prevIncState = 0;   // stores the last value from increment button

int decState = 0;       // reads value from decrement button
int prevDecState = 0;   // stores the last value from decrement button

int numPresses = 0;     // the number to convert to binary. Range from 0-7

void setup() 
{
  // intialize led pins as outputs
  pinMode(LSD, OUTPUT);
  pinMode(mid, OUTPUT);
  pinMode(MSD, OUTPUT);

  // initialize buttons as inputs
  pinMode(incrementButton, INPUT);
  pinMode(decrementButton, INPUT);
}

void loop() 
{ // open loop
  
  // read in the button inputs
  incState = digitalRead(incrementButton);
  decState = digitalRead(decrementButton);

  // prevents incrementing the # of presses if the user holds down the increment button
  // holding the increment button should only count for 1 press
  if (incState != prevIncState)
  {
    // if the increment button was pressed
    if (incState == HIGH)
      numPresses++;

    // debounce
    delay(100);
  }
  else if (decState != prevDecState)
  {
    // if the decrement button was pressed
    if (decState == HIGH)
      numPresses--;
      
    // debounce
     delay(100);
  }

  // convert number of presses from decimal to binary
  MSDBin = (numPresses / 4) % 2;  // 4's 
  midBin = (numPresses / 2) % 2;  // 2's
  LSDBin = numPresses % 2;        // 1's

  // turn led's on/off depending on their binary representation
  onOffLED(MSD, numPresses, (MSDBin == 1));
  onOffLED(mid, numPresses, (midBin == 1));
  onOffLED(LSD, numPresses, (LSDBin == 1));
  
  // update the previous button values for the next iteration
  prevIncState = incState;
  prevDecState = decState;

} // close loop


void onOffLED(int ledPin, int numPresses, bool turnOn)
{
  // make sure the number of presses is within desired range
  // we can only represent the numbers 0-7 using 3 bit binary notation
  if (numPresses < 0 || numPresses > 7)
  {
    // flash lights to indicate done
    flash();
    flash();
    flash();
  }
  else
  {
    // turn led on
    if (turnOn)
      digitalWrite(ledPin, HIGH);
    // turn led off
    else
      digitalWrite(ledPin, LOW);
  }
}

void flash()
{
  digitalWrite(LSD, HIGH);
  digitalWrite(mid, HIGH);
  digitalWrite(MSD, HIGH);
  
  delay(300);
  
  digitalWrite(LSD, LOW);
  digitalWrite(mid, LOW);
  digitalWrite(MSD, LOW);

  delay(300);
}
