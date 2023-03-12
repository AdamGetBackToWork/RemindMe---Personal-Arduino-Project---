```c++
```c

//Attributing pins on the board

const int trigPin = 2;
const int echoPin = 4;
const int buzzerPin = 6;
const int buttonPin1 = 7;
const int buttonPin2 = 8;
const int buttonPin3 = 9;
const int buttonPin4 = 10;
const int buttonPinG = 12;


//Initializing the variables

long duration;
int distance;
int safetyDistance;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonStateG = 0;

//Creating an array of five integers

int state_memory[5];


//Creating state system for the programme, inside the loop we'll be switching between them

enum States {
  WAIT, 
  buzzer_ON, 
  buzzer_OFF, 
  HUMAN_ACTION, 
  HUMAN_ACTION_G,
  zero_ing,
};
//Setting default state

enum States Program_State = WAIT;


//Attributing I/O for each pin, also setting default value for the buzzer as HIGH - this particular buzzer sets off when on LOW 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPinG, INPUT);
  digitalWrite(buzzerPin, HIGH);
  Serial.begin(9600); 
}

//Opening the loop - the heart of this programme, it will execute non-stop

void loop() {

switch (Program_State) {
  
  case WAIT:
    //First state - the sensor is waiting for someone to get near it
    
    //Settings for the sonic sensor

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Calculating duration of the sonic wave to the distacne it traveled
    
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    safetyDistance = distance;

    //Initializing button states as "read-offs" from button pins

    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);
    buttonStateG = digitalRead(buttonPinG);

    //Conditions for state changes, you can either walk near the sensor to then go into buzzer_ON, or start pushing the buttons to skip the buzzer setting off

    if (safetyDistance <= 40) {
    
      Program_State = buzzer_ON;

    } else if (buttonState1 == 1 || buttonState2 == 1 || buttonState3 == 1 || buttonState4 == 1 ) {

      Program_State = HUMAN_ACTION;

    } else if (buttonStateG == 1) {
      
      Program_State = HUMAN_ACTION_G;

    } else {
      
      Program_State = WAIT;
    }

    break;

  case buzzer_ON:
    //Second state - setting off the buzzer for 3 seconds by changing the buzzerPin output to LOW, immidietly after doing so, change the state to buzzer_OFF

    digitalWrite(buzzerPin, LOW);
    delay (4000);

    Program_State = buzzer_OFF;

    break;
      
  case buzzer_OFF:
    //Third state - setting the buzzer state back to HIGH - turning it off

    digitalWrite(buzzerPin, HIGH);

    Program_State = WAIT;

    break;

  case HUMAN_ACTION:
    //Fourth state  - waiting for human action, to be able to walk past the sensor without making it make sound, either by clicking all single buttons (button?) or one general button (buttonG)

    //Settings for the sonic sensor

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Calculating duration of the sonic wave to the distacne it traveled

    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    safetyDistance = distance;

    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    buttonState4 = digitalRead(buttonPin4);

    //When a button state changes, this will save its changed state to the "state_memory" array

    if (buttonState1 == 1) state_memory[0] = 1;
    if (buttonState2 == 1) state_memory[1] = 1;
    if (buttonState3 == 1) state_memory[2] = 1;
    if (buttonState4 == 1) state_memory[3] = 1; 

    //Condition to end the "HUMAN_ACTION" state and move forward

    if (safetyDistance <= 40) {
      
      Program_State = buzzer_ON;

    } else if (state_memory[0] == 1 && state_memory[1] == 1 && state_memory[2] == 1 && state_memory[3] == 1) {
      
       Program_State = zero_ing;

    }
    break;

  case HUMAN_ACTION_G:

   buttonStateG = digitalRead(buttonPinG);

   if (buttonStateG == 1) state_memory[4] = 1; 

    if (state_memory[4] == 1) Program_State = zero_ing;

  case zero_ing:

    //Makes every "state_memory" a 0, changes the state back to "WAIT" and allows us to walk out off the room for 5 seconds without setting off the buzzer

    for (int i = 0; i<5; i++) state_memory[i] = 0;  

    Program_State = WAIT;

    delay (20000);

    // to change the delay to at least 30000 mills ////////////////////////////////////////////////////////////
    break;
}

//Showing in the serial monitor both states of the distance and the state of the loop, to keep an eye if the programme is working properly
//delay(1000);

Serial.print("Distance: ");
Serial.println(distance);
Serial.print("Program_State: ");
Serial.println(Program_State);

}

//Adam Szajgin, PW WEITI, REZYSPOL
```
