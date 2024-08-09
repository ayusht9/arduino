#include <Servo.h>          //Servo motor library.
#include <NewPing.h>        //Ultrasonic sensor function library.

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

//sensor pins
#define trig_pin A1
#define echo_pin A2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor; //our servo name


void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(3); //our servo pin

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    digitalWrite(8, 0);
    digitalWrite(9, 128);
    digitalWrite(10, 0);
    digitalWrite(11, 128); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(5, 127);
  digitalWrite(9, 0);
  digitalWrite(10, 127);
  digitalWrite(11, 0);
}

void turnRight(){

  digitalWrite(5, 127);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 127);
  
  delay(500);
  digitalWrite(5, 127);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 127); 

  
}

void turnLeft(){

  digitalWrite(5, 0);
  digitalWrite(9, 128);
  digitalWrite(10, 127);
  digitalWrite(11, 0);

  delay(500);

  digitalWrite(5, 0);
  digitalWrite(9, 127);
  digitalWrite(10, 127);
  digitalWrite(11, 0);
}
