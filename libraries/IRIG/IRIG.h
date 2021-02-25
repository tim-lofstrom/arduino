/**
 *  IRIG.h  - Library for reading 1Hz Time Frames from a IRIG-B transmitter.
 *  Created by Tim Löfström, December 01, 2016
 */

#ifndef IRIG_H
#define IRIG_H

#include "Arduino.h"

class IRIG{

  public:
    IRIG(int pin);
    String ReadTimeFrame():


  private:

    /* Digital Pin */
    int _pin;

    /* Variables to store time frame data */
    byte _Seconds;
    byte _Minutes;
    byte _Hours;
    byte _Month;
    byte _Year;

    /* Variables to control reading */
    int _index;
    int _jitter;
    int _timeout;

    /* Reads a single bit from the Digital Pin */
    char ReadBit();
}

#endif
