## Objective

* Be able to convert analog sensor input to digital information.
* Use photoresistors

Design incorporates the light sensitive resistor photocell and display relevant information about the photocell value onto the 16x2 display.
A circuit and program that will use a photoresistor and the 16x2 display. The display states the relative amount of light in the room (dark, partially dark, medium, partially light, fully lit.) in the room, or fully lit, or somewhere in between should be displayed based on the value read from the photocell. This involves me determining the range of values the photoresistor provides and then making reasonable ranges for the values being considered.

###### LIGHT RANGES


| Light           | Range    |
| -------------   | -------- |
| dark            | 0-100    |
| partially dark  | 101-301  |
| medium          | 302-502  |
| partially lit   | 503-703  |
| fully lit       | 704+     |