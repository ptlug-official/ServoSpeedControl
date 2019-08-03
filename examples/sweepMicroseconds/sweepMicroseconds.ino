/*
  Sweep Delay
  
  Simulate speed control in a servo (like SG90) using microseconds degree and delay(in microseconds).

    created 2019
    by Emiliano Giusti
  
*/

#include <ServoSpeedControl.h>

ServoSpeedControl myservo;
const byte servoPin1=25;
unsigned int angle=myservo.getMinAngleMicros();

void setup() {
    myservo.attach(servoPin1);  
}

void loop() {
    //Sets the delay in microseconds between the steps
    myservo.setDelayMicros(3000); 
    if ((angle==myservo.getMinAngleMicros()) && (myservo.isInGoal())) {
      angle=myservo.getMaxAngleMicros();
      myservo.setGoalAngleMicros(angle); 
    }
    if ((angle==myservo.getMaxAngleMicros()) && (myservo.isInGoal())) {
      angle=myservo.getMinAngleMicros();
      myservo.setGoalAngleMicros(angle);
    }    
    //Call this method to execute the movement   
    myservo.doStep();

}
