# Smart Home

This code is for smart home based in Atmega32.
## Installation
To use it you must download an IDE to burn the code in your kit.
I also included "Prouteus" file for simulation if you want to try it before using your kit.
## Description 
The System consists of 4 main components: 
1- Lcd Display: to display orders that you give to system and statues of system 
2- Key Pad: to control your system through it 
3- Sensor: Temperature sensor
4- Actuator: Servo Motors (for the cooler and the heater)
# What does system provide 
1- System is secured by a password that is set at first use of the system.
This password will be used to access your home.
This password can be changed later if you want.
2- System also Provides Temperature based on the reading of the sensor he will open the cooler, the heater or do nothing if the temp is fine 
3- System also enables you to open lights, close it, change it if you have many light bulbs in your home.
4- System has built-in watch to informs you what time is now. 
# Features I want to enhance my system by in the future
1- Control of full devices of any home 
2- connect it with a mobile app.
# Challenges that faced me 
In this system I used a timer to Show Time. This timer interrupts when it overflows.
when it overflows number of times the time it took equals 1 second.
The problem was that the timer interrupts faster than the Lcd Responses that made a problem at display when timer is activated.
### How I solved it?
I was using timer 0 which overflows every 256 tick time which equals 256 micro second.
Instead I used Timer 1 which overflows every 65536 tick time which equals 6.5 milli second that is enough time for the Lcd to response any order.
