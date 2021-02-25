/*
 * Net.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: tilo
 */

#include "Net.h"

Net::Net(){

//	NetEeprom.begin();
	byte ip[4];
	NetEeprom.readIp(ip);

	byte subnet[4];
	NetEeprom.readSubnet(subnet);

	byte gateway[4];
	NetEeprom.readGateway(gateway);

	byte mac[6];
	NetEeprom.readMac(mac);

	byte dns[4];
	NetEeprom.readDns(dns);

	Ethernet.begin(mac, ip, dns, gateway, subnet);


	r_ip = IPAddress(10, 8, 1, 241);
	r_port = 5555;
	m_socket.begin(r_port);

	Serial.println("Net Initialized.");

}

void Net::Send(const char *data){
	m_socket.beginPacket(r_ip, r_port);
	m_socket.write(data);
	m_socket.endPacket();
}

String Net::Read(){
	String data = "";

	return data;
}

