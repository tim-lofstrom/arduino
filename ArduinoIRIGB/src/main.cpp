#include <Arduino.h>
#include <SPI.h>
#include "IRIGB/IRIGB.h"
#include "Net/Net.h"

IRIGB *irig_boden;
IRIGB *irig_borlange;
Net *net;


void setup() {

	Serial.begin(9600);

	irig_boden = new IRIGB(2);
	irig_borlange = new IRIGB(4);

	net = new Net();

}

void loop() {


	String time_boden = "BDN;" + irig_boden->ReadTimeFrame() + ";";
	String time_borlange = "BLG;" + irig_borlange->ReadTimeFrame() + ";";

	Serial.println("BDN: " + time_boden);
	Serial.println("BLG: " + time_borlange);

	char frame[25];
	time_boden.toCharArray(frame, 25);

	char frame2[25];
	time_borlange.toCharArray(frame2, 25);

	net->Send(frame);
	net->Send(frame2);

}




