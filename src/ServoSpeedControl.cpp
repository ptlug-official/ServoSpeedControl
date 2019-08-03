/*
Copyright (c) 2019 Emiliano Giusti. All right reserved.

*/

#include "ServoSpeedControl.h"
#include "Arduino.h"


void ServoSpeedControl::setMinAngleMicros(unsigned int value){
        if (value<DEFAULT_uS_LOW)
            value=DEFAULT_uS_LOW;
        if (value<maxAngleMicros)
            minAngleMicros=value;
}

unsigned int ServoSpeedControl::getMinAngleMicros(){
        return minAngleMicros;
}

void ServoSpeedControl::setMaxAngleMicros(unsigned int value){
        if (value>DEFAULT_uS_HIGH)
            value=DEFAULT_uS_HIGH;
        if (value>minAngleMicros)
            maxAngleMicros=value;
}

unsigned int ServoSpeedControl::getMaxAngleMicros(){
        return maxAngleMicros;
}

void ServoSpeedControl::setGoalAngleMicros(unsigned int value){
        if ((value>=minAngleMicros)&&(value<=maxAngleMicros))
            goalAngleMicros=value;  
}
  
unsigned int ServoSpeedControl::getGoalAngleMicros(){
        return goalAngleMicros;
}

void ServoSpeedControl::setDelayMicros(unsigned int value){
            delayMicros=value;
}

unsigned int ServoSpeedControl::getDelayMicros(){
        return delayMicros;
}

void ServoSpeedControl::setMinAngle(byte value){
        if (value<0)
            value=0;
        if (value>180) 
            value=180;
        minAngle=value;
        this->setMinAngleMicros(map(value,0,180,DEFAULT_uS_LOW,DEFAULT_uS_HIGH));      
}

byte ServoSpeedControl::getMinAngle(){
        return minAngle;
}

void ServoSpeedControl::setMaxAngle(byte value){
        if (value<0)
            value=0;
        if (value>180) 
            value=180;
        maxAngleMicros=map(value,0,180,DEFAULT_uS_LOW,DEFAULT_uS_HIGH);
        maxAngle=value;
}

byte ServoSpeedControl::getMaxAngle(){
        return maxAngle;
}

void ServoSpeedControl::setGoalAngle(byte value){
        this->setGoalAngleMicros(map(value,0,180,DEFAULT_uS_LOW,DEFAULT_uS_HIGH));
        goalAngle=value;  
}
  
byte ServoSpeedControl::getGoalAngle(){
        return goalAngle;
}

void ServoSpeedControl::setDelay(byte value){           
        delayMicros=(value*1000);
        delay=value;
}

byte ServoSpeedControl::getDelay(){
        return delay;
}

void ServoSpeedControl::setSpeed(byte value){
        if ((value<=10)&&(value>=1)) {
            delayMicros=map(value,1,10,MAX_MICROS_VALUE,MIN_MICROS_VALUE);
            speed=value;
        }
}

byte ServoSpeedControl::getSpeed(){
        return speed;
}

void ServoSpeedControl::doStep() { 
        if (micros()>(oldTime+delayMicros)) { 
            if (goalAngleMicros>oldAngleMicros){
                Servo::writeMicroseconds(oldAngleMicros+1);
                oldAngleMicros++;
            }
            if (goalAngleMicros<oldAngleMicros){
                Servo::writeMicroseconds(oldAngleMicros-1); 
                oldAngleMicros--;
            }
            oldTime=micros();
        }
}

bool ServoSpeedControl::isInGoal() {
        if (goalAngleMicros==oldAngleMicros)
            return true;
        return false;
}

