## Objective

* Learn how to create a circuit that sends input from a connected component to the Arduino.
* Get practice with slightly more complicated Arduino programming.
* Refresh memory on binary conversion.

Use two switches and three LEDs for this circuit. One switch will increment a 3-bit count, and the other switch should decrement the 3-bit count. 
The 3-bit count will be displayed on the three LEDs in binary (a 1 is LED on).  

Code keeps track of the number of button presses and algorithmically converts that number to a binary output.  Code does NOT just implements a giant lookup table to translate to binary.

Lights increment (or decrement) by one each time the switch is pressed. If we continually depress the switch, the lights should not run up (or down) to 7 (or 0) (i.e. it should only change the value once per button press).