# REMINDME 1.0

A project I developed for my university assignment. An Arduino based IoT design to help you remember of your daily essentials! 


### Concept of the system

RemindMe 1.0 was a 3d printed little box with 5 buttons sticking out of it. On the side it had a sonic sensor to detect distance from objects passing by it. 

The entire system was to be hang by the door with the sensor facing the door, and the buttons facing the room. 

### The idea was this: 
When walking out the room, user would be reminded of theirs daily essentials. When walking pass by the distance sensor, then the system would check if the person "checked off" every button on the systems interface. If not the system start to create disturbing sound to remind the user of their forgetfulness! They would go back, check whether they took their daily essentials or not, then check off the buttons assigned to each item, and would out the door peacfully! 

And obviously if they had already checked off every button they;d be able to walk out right of the back!

### Here is the block diagram to visualize it all:

<img align="center">
![Example Flowchart](/Block_diagram_1.png)
</img>


#### User had to check off every single button in order for the device to "let them pass". If the user only pushed 2 out of 4 buttons, and tried to walk out the room (passing by the sensor) the system would detect, that they hadn't pushed all the buttons. 

Also the system was equipped in a "reset/for all" button, if the user wanted to either reset the device or check all the buttons at once.


##### Sidenote:
The unfortunate simplicity of the desing is due to the limited amount of components available for the project. I was given x amount of components and was sopposed to make something from them. Alse I had limited time... So here is the REMINDME 1.0!!!

