// Ahmed Khan, akhan227, 652469935

int redPin = 13;
int greenPin = 10;
int bluePin = 8;

int timeInSeconds = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(redPin, HIGH);       // turn the red LED on (HIGH is the voltage level)
  delay(timeInSeconds);             // wait for a second
  digitalWrite(redPin, LOW);        // turn the red LED off by making the voltage LOW

  digitalWrite(greenPin, HIGH);     // turn the green LED on (HIGH is the voltage level)
  delay(timeInSeconds);             // wait for a second
  digitalWrite(greenPin, LOW);      // turn the green LED off by making the voltage LOW

  digitalWrite(bluePin, HIGH);      // turn the blue LED on (HIGH is the voltage level)
  delay(timeInSeconds);             // wait for a second
  digitalWrite(bluePin, LOW);       // turn the blue LED off by making the voltage LOW
}
