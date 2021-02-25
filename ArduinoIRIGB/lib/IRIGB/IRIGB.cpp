/*
 * IRIGB.CPP	- Library for reading 1Hz Time Frames from a IRIG-B transmitter.
 *
 *  Created on: Dec 1, 2016
 *      Author: Tim Löfström
 */

#include "IRIGB.h"

IRIGB::IRIGB(int pin){
	pinMode(pin, INPUT);
	_pin = pin;
	_jitter = 200;		//ns
	_timeout = (unsigned)250000;	//µs
	_PrevDays = 0;
	_PrevYear = 0;
	Reset();
}

void IRIGB::Reset(){
	_Seconds = 0;
	_Minutes = 0;
	_Hours = 0;
	_Days = 0;
	_Year = 0;
}

String IRIGB::ReadTimeFrame(){

	byte daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	byte bitstream[79];

	/* Set time to 0 */
	Reset();

	//Wait for reference (two references are the beginning of the frame).
	bool status = WaitForReference();

	if(status == -1){
		return "frame_error reference";
	}

	//Read Seconds (7 bits)
	for(int i = 0; i < 8; i++){
		bitstream[i] = ReadBit();
	}
	_Seconds 	= bitstream[0] + bitstream[1] * 2 + bitstream[2] * 4 + bitstream[3] * 8 + bitstream[5] * 10 + bitstream[6] * 20 + bitstream[7] * 40;

	if(ReadBit() != 2){
		return "frame_error seconds";
	}

	//Read Minutes (8 bits)
	for(int i = 9; i < 18; i++){
		bitstream[i] = ReadBit();
	}

	if(ReadBit() != 2){
		return "frame_error minutes";
	}

	_Minutes = bitstream[9] + bitstream[10] * 2 + bitstream[11] * 4 + bitstream[12] * 8 + bitstream[14] * 10 + bitstream[15] * 20 + bitstream[16] * 40;

	//Read Hours (8 bits)
	for(int i = 19; i < 28; i++){
		bitstream[i] = ReadBit();
	}

	_Hours = bitstream[19] + bitstream[20] * 2 + bitstream[21] * 4 + bitstream[22] * 8 + bitstream[24] * 10 + bitstream[25] * 20;

	if(ReadBit() != 2){
		return "frame_error hours";
	}

	//Read first part of Days (8 bits)
	for(int i = 29; i < 38; i++){
		bitstream[i] = ReadBit();
	}

	if(ReadBit() != 2){
		return "frame_error days part 1";
	}

	//Read second part of Days (2 bits + 6 empty)
	for(int i = 39; i < 48; i++){
		bitstream[i] = ReadBit();
	}

	if(ReadBit() != 2){
		return "frame_error days part 2";
	}

	_Days = bitstream[29] + bitstream[30] * 2 + bitstream[31] * 4 + bitstream[32] * 8 + bitstream[34] * 10 + bitstream[35] * 20 + bitstream[36] * 40 + bitstream[37] * 80 + bitstream[39] * 100 + bitstream[40] * 200;

	//Read Years (8 bits)
	for(int i = 49; i < 58; i++){
		bitstream[i] = ReadBit();
	}

	if(ReadBit() != 2){
		return "frame_error years";
	}

	_Year = 2000 + bitstream[49] + bitstream[50] * 2 + bitstream[51] * 4 + bitstream[52] * 8 + bitstream[54] * 10 + bitstream[55] * 20 + bitstream[56] * 40 + bitstream[57] * 80;


	// If Year changed since last time, check if the new year is a leapyear.
	if(_Year != _PrevYear){

		_PrevYear = _Year;

		//Check Leap Year
		if (_Year % 4  == 0){
			if (_Year % 100 != 0){
				daysInMonth[1] = 29;
			} else if (_Year % 400 == 0){
				daysInMonth[1] = 29;
			} else {
				daysInMonth[1] = 28;
			}
		}
	}

	//If Days have changed since last time, check the new days of month and which month it is.
	if((_Days != _PrevDays)){

		_PrevDays = _Days;

		unsigned int tempDays = _Days;

		//Parse Days and Months
		int i = 0;
		while(tempDays > daysInMonth[i]){
			tempDays -= daysInMonth[i];
			i++;
		}
		_Month = i + 1;
		_Day = tempDays;
	}

	char frame[79];
	sprintf(frame, "%04d-%02d-%02d %02d:%02d:%02d", _Year, _Month, _Day, _Hours, _Minutes, _Seconds);
	return frame;
}


/**
 * Reads a frame from the defined digital input
 *
 * @returns bit char,
 * 					0 LOW
 * 					1 HIGH
 * 					2 REFERENCE
 *
 */
int IRIGB::ReadBit(){

	_duration = pulseInLong(_pin, HIGH, _timeout);

	//0ms must be some error
	if(_duration == 0){
		return -1;
	}
	//2ms is zero
	if(_duration <= (2000 + _jitter)){
		return 0;
	}
	//5ms is one
	if(_duration <= (5000 + _jitter)){
		return 1;
	}
	//8ms is reference (if none of above, it must have been a reference)
	return 2;
}

/**
 * Waits until a 8ms HIGH is read twice.
 */
bool IRIGB::WaitForReference(){

	int bit = -1;
	int prevbit = -1;
	while(1){
		bit = ReadBit();
		if(prevbit && (prevbit == 2) && (bit == 2)){
			return true;
		}
		if(bit == -1){
			return false;
		}
		prevbit = bit;
	}
}



