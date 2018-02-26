## Objectives
* Be able to have your aurdino do two unconnected things at the same time, using multiple inputs and outputs.
* Be able to read and write to analog inputs and outputs.

This lab we will be experimenting with multiple inputs and outputs.  

There are two parts:

1) 
	* Using 4 LEDS and a photoresistor.  
	* All 4 LEDs next to each (preferably the same color).  
	* As the amount of light seen by the photoresistor decreases, increase the number of LEDs that are lit.  
		* For example, if the circuit receives no light then all of the LEDs should light up.  
		* As the circuit continues to increase the amount of light, the number of LEDs that light up will decrease.  
		* So when the photoresistor receives half the amount of light, 2 LEDS should be lit up, 
		* and when there is no light, all 4 LEDs should be lit up.

2) In parallel with part 1, we will be using the the passive buzzer and the potentiometer.  
	* Use the potentiometer as an analog input and have the output come from another analog pin.  
	* Control the volume or tone of the buzzer by adjusting the potentiometer.  
	* Make sure to have code to control the output of the buzzer based on the potentiometer.