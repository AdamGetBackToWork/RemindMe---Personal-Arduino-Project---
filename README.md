# REMINDME 1.0

A project I developed for my university assignment. An Arduino based IoT design to help you remember of your daily essentials! 


## System concept

**RemindMe 1.0** was an Arduino based system. It was a 3d printed little box with 5 buttons sticking out of it. On the side it had a sonic sensor to detect distance from objects passing by it. 

The entire system was to be hang by the door with the sensor facing the door, and the buttons facing the room. 

## The idea was this: 
Upon exiting the room, the individual would receive a subtle reminder regarding their daily necessities. Upon traversing past the distance sensor, the system would ascertain whether all the buttons on the interface have been properly marked by the user. Should any omission be detected, the system would initiate a sequence of attention-grabbing sounds, prompting the user to address their momentary lapse. Subsequently, the user would retrace their steps, verify the presence of their daily essentials, meticulously mark each corresponding button, and then proceed to depart serenely. Naturally, if every button has been previously acknowledged, they would be at liberty to exit without any hindrance.

### Here is the block diagram to visualize it all:
  
<p align="center">
  <img src="/Block_diagram_1.png">
</p>

### Buttons
User had to check off every single button in order for the device to "let them pass". If the user only pushed 2 out of 4 buttons, and tried to walk out the room (passing by the sensor) the system would detect, that they hadn't pushed all the buttons. 

Also the system was equipped in a "reset/for all" button, if the user wanted to either reset the device or check all the buttons at once.

### Schematic diagram of the circuit:

<p align="center">
  <img src="/RemindMe - circuit diagram.jpg">
</p>

## Sidenote:
The unfortunate simplicity of the desing is due to the limited amount of components available for the project. I was given x amount of components and was sopposed to make something from them. Alse I had limited time... So here is the REMINDME 1.0!!!

## Biggest challanges and what I've learned:

- Programming in objective C/C++ 
> Although I've known C++ for a while now, applying it to a more "embedded style" project was a bit challenging at times, as in my case, using it before was limited to a "theoretical" purposes only 
> 
> The objective C parts also gave me a bit of a hard time, but in addition to the projects required syntax elements I've learnd C!
- Designing a working system
> I know it sounds easy... but troubleshooting both electronic design (Arduino based) and the code itself and making it work at all times can get tough! 

