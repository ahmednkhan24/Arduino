## Objectives
* Be able to take in user input and have your arduino respond appropriately.

Arduino gets the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. 
Date includes day, month and year
Time includes hour, minutes and seconds

###### Circuit/Program does the following
* prints a prompt on the serial monitor
* gets input of date and time from user
* displays date and time on the 16x2 display 
* keeps accurate time on 16x2 display 
* include error checking for input that doesn't make sense (hours  not in range of 0 to 23, minutes not in range 0 to 59, month not range of 1 to 12, etc).
