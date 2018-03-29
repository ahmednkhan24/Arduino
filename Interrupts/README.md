## Objective

* Learn how to program with intetrupts.

A program for the arduino that utilizes interrupts. When no button has been pressed my 16x2 display says "Waiting for X seconds", where X will be updated as time goes on.

When the red button is pressed, the display should display “Interrupt received! Press the yellow button to continue”
When the yellow button is pressed, the display goes back to displaying "Waiting for X seconds", and restarts the time at 0 seconds.