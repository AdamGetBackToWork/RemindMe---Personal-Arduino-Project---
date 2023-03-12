# REMINDME 1.0

A project I developed for my university assignment. An Arduino based IoT design to help you remember of your daily essentials! 


## Concept of the system

**RemindMe 1.0** was an Arduino based system. It was a 3d printed little box with 5 buttons sticking out of it. On the side it had a sonic sensor to detect distance from objects passing by it. 

The entire system was to be hang by the door with the sensor facing the door, and the buttons facing the room. 

## The idea was this: 
When walking out the room, user would be reminded of theirs daily essentials. When walking pass by the distance sensor, then the system would check if the person "checked off" every button on the systems interface. If not the system start to create disturbing sound to remind the user of their forgetfulness! They would go back, check whether they took their daily essentials or not, then check off the buttons assigned to each item, and would out the door peacfully! 

And obviously if they had already checked off every button they;d be able to walk out right of the back!

### Here is the block diagram to visualize it all:
  
<p align="center">
  <img src="/Block_diagram_1.png">
</p>

### Buttons
User had to check off every single button in order for the device to "let them pass". If the user only pushed 2 out of 4 buttons, and tried to walk out the room (passing by the sensor) the system would detect, that they hadn't pushed all the buttons. 

Also the system was equipped in a "reset/for all" button, if the user wanted to either reset the device or check all the buttons at once.


## Sidenote:
The unfortunate simplicity of the desing is due to the limited amount of components available for the project. I was given x amount of components and was sopposed to make something from them. Alse I had limited time... So here is the REMINDME 1.0!!!

## Biggest challanges and what I've learned:

- Programming in objective C/C++ 
> Although I knew C++ before, applying it to a more "embedded style" project was a bit challenging at times
> 
> The objective C parts also gave me a bit of a hard time, but in addition to the projects required syntax elements I've learnd C!
- Designing a working system
> I know it sounds easy... but troubleshooting both electronic design (Arduino based) and the code itself and making it work at all times can get challenging! 

