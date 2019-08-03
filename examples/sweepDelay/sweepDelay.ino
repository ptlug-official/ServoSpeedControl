/*
  Sweep Delay
  
  Simulate speed control in a servo (like SG90) using angle degree and delay(in milliseconds).

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
    //Sets the delay in millisecond between the steps
    myservo.setDelay(3); 
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
