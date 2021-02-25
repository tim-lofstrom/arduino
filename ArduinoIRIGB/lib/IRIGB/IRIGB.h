/*
 * IRIGB.h		- Library for reading 1Hz Time Frames from a IRIG-B transmitter.
 *
 *  Created on: Dec 1, 2016
 *      Author: Tim L�fstr�m
 */

#ifndef IRIGB_H_
#define IRIGB_H_

#include "Arduino.h"

class IRIGB{

public:
	IRIGB(int pin);
	String ReadTimeFrame();

private:

	/* Digital Pin */
	int _pin;

	/* Variables to store time frame data */
	byte _Seconds;
	byte _Minutes;
	byte _Hours;
	byte _Month;
	byte _Day;
	unsigned int _Year;
	unsigned int _Days;

	unsigned int _PrevYear;
	unsigned int _PrevDays;

	byte _counter;              //reiceved bit counter[max 84+5 INDEX]
	byte _bitstream[89];     //array where input bitstream is stHoursd [max 84 + 5 INDEX]

	/* Variables to control reading */
	unsigned int _jitter;
	unsigned int _timeout;
	unsigned int _duration;

	/* Reads a single bit from the Digital Pin */
	int ReadBit();

	/* Waits until a reference bit is returned */
	bool WaitForReference();

	/* Resets the timevariables */
	void Reset();
};

#endif /* IRIGB_H_ */
