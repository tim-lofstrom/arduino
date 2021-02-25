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
#include "EEPROM.h"

class Net{

public:
	Net();
	void Begin();
	void Send(const char *str, int port);
	void SaveRemoteIP(byte ip[]);
	void ReadRemoteIP(byte ip[]);
	void ReadRemoteIP();
	String Read();
	void RemotePort(unsigned int *port);
	void RemoteClient(byte ip[]);

private:
	EthernetUDP m_socket;
	IPAddress r_ip;
	unsigned int r_port;
	void readEEPROM(byte data[], int offset, int length);
	void writeEEPROM(byte data[], int offset, int length);

};



#endif /* NET_H_ */
