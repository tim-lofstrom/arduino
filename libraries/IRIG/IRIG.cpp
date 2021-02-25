/**
 *  IRIG.cpp  - Library for reading 1Hz Time Frames from a IRIG-B transmitter.
 *  Created by Tim Löfström, December 01, 2016
 */

#include "Arduino.h"
#include "IRIG.h"

IRIG::IRIG(int pin){
  pinMode(pin, INPUT);
  _pin = pin;
  _jitter = 200;
  _timeout = 250000;
}


String IRIG::ReadTimeFrame(){

  String frame "TEMP";
  return frame;
}


char IRIG::ReadBit(){

  int pulse = pulseIn(_pin, HIGH, _timeout);
  
  //2ms is zero

  //5ms is one

  //8ms is reference pointer

  Serial.println("test");
}

