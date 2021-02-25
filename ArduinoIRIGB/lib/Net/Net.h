/*
 * Net.h
 *
 *  Created on: Dec 13, 2016
 *      Author: tilo
 */

#ifndef NET_H_
#define NET_H_

#include "Arduino.h"
#include <Ethernet.h>
#include <EthernetUdp.h>
#include "NetEEPROM.h"

class Net{

public:
	Net();
	void Send(const char *str);
	String Read();

private:

	EthernetUDP m_socket;
	IPAddress r_ip;
	unsigned int r_port;

};



#endif /* NET_H_ */
