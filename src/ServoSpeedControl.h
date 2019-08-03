/* Software License:

  ServoSpeedControl library
  Copyright (C) 2019  Emiliano Giusti

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Author: Emiliano Giusti 
 */
#ifndef Servo_Speed_Control_h
#define Servo_Speed_Control_h

#include <Arduino.h>

#if defined(ARDUINO_ARCH_AVR)
#include <Servo.h>
#define DEFAULT_uS_LOW  MIN_PULSE_WIDTH
#define DEFAULT_uS_HIGH MAX_PULSE_WIDTH
#endif
#if defined(ARDUINO_ARCH_ESP32)
#include <ESP32Servo.h>
#endif

#define MIN_MICROS_VALUE 200
#define MAX_MICROS_VALUE 10000

class ServoSpeedControl  : public Servo {

private:
    unsigned long oldTime=0;
    unsigned int minAngleMicros=DEFAULT_uS_LOW;
    unsigned int maxAngleMicros=DEFAULT_uS_HIGH;
    unsigned int goalAngleMicros=((minAngleMicros+maxAngleMicros)/2);
    unsigned int oldAngleMicros=goalAngleMicros;
    unsigned int delayMicros=MAX_MICROS_VALUE;
    byte minAngle=0;
    byte maxAngle=180;
    byte goalAngle=90;
    byte delay=0;
    byte speed=0;

public:
    void setMinAngleMicros(unsigned int value);
    unsigned int getMinAngleMicros();
    void setMaxAngleMicros(unsigned int value);
    unsigned int getMaxAngleMicros();
    void setGoalAngleMicros(unsigned int angle);
    unsigned int getGoalAngleMicros();
    void setDelayMicros(unsigned int delay);
    unsigned int getDelayMicros();
    void setMinAngle(byte value);
    byte getMinAngle();
    void setMaxAngle(byte value);
    byte getMaxAngle();
    void setGoalAngle(byte value);
    byte getGoalAngle();
    void setDelay(byte value);
    byte getDelay();
    void setSpeed(byte value);
    byte getSpeed();
    void doStep();
    bool isInGoal();
};
#endif
