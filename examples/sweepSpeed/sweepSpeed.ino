/*
  Sweep Speed
  
  Simulate speed control in a servo (like SG90) using angle degree and speed.

    created 2019
    by Emiliano Giusti
  
*/

#include <ServoSpeedControl.h>

ServoSpeedControl myservo;
const byte servoPin1=25;
byte angle=0;

void setup() {
    myservo.attach(servoPin1);  
}

void loop() {
    //You can use from 1 to 10 - You can tune the speed changing MAX_MICROS_VALUE and MIN_MICROS_VALUE in ServoSpeedControl.h 
    myservo.setSpeed(1); 
    if ((angle==0) && (myservo.isInGoal())) {
      angle=180; 
      myservo.setGoalAngle(angle); 
    }
    if ((angle==180) && (myservo.isInGoal())) {
      angle=0;
      myservo.setGoalAngle(angle);  
    }    
    //Call this method to execute the movement   
    myservo.doStep();

}
