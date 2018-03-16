/*
  Name: Ahmed Khan, 652469935
  Lab:         Lab 7 - Arduino to Arduino Communication
  Description: Be able to have two arduinos communicate with eachother.
                * connect two arduino's via a hardwired serial connection (no usb cable) (digital pins 0 and 1)
                * connect a button and an external LED to each device
                * pressing the button on one arduino should cause the other arduino's LED to change state (on to off, or off to on)
                * Button press on one arduino should toggle the state of the LED on the other (on/off) and not keep the LED lit while being pressed
               
  Assumptions: I initially assumed that sending/receiving data to/from another arduino would need a different library and set of functions,
               but it was all done using the regular Serial functions.

  References:  https://www.arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
               https://www.arduino.cc/en/Serial/Available#.UwYy2PldV8E
               https://www.arduino.cc/reference/en/language/functions/communication/serial/#.UwYyzfldV8E               
*/

// pin number for this arduino's LED
const int ledPin = 2;    

// pin number for this arduino's Button
const int buttonPin = 4;  

// variable to read incoming serial data from the other arduino
int incomingByte;              

int prevBtnState = 0;       // used for toggling button presses
int btnState  = 0;          // variables for reading the pushbutton status

int ledState = 0;           // variable to keep track of whether the other led is on or not

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);    //initialize the LED pin as an output
  pinMode(buttonPin, INPUT);  //initialize the pushbutton pin as an output
}

void loop() 
{
  // receiving input from other arduino
  if (Serial.available() > 0) 
  {
    toggleThis();
  }
  
  btnState = digitalRead(buttonPin);  // read the state of the pushbutton value

  if (btnState != prevBtnState)
  {
    // if the increment button was pressed
    if (btnState == HIGH)
    {
      toggleOther();
    }

    // debounce
    delay(100);
  }

  prevBtnState = btnState;
}


// function reads data from the other arduino, and turns led on/off
void toggleThis()
{
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') 
    {
      digitalWrite(ledPin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') 
    {
      digitalWrite(ledPin, LOW);
    }
}


// function sends data to the other arduino
void toggleOther()
{
  // turn led on
  if (ledState == 0)
  {
    ledState = 1;
    Serial.println("H");
  }
  
  // turn led off
  else
  {
    ledState = 0;
    Serial.println("L");
  }
}
