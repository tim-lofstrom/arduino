/*
 * Net.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: tilo
 */

#include "Net.h"

Net::Net(){
	ReadRemoteIP();
}

void Net::Begin(){
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

	r_port = 5555;
	m_socket.begin(r_port);
	Serial.println("Net Initialized.");
}

void Net::Send(const char *data, int port){
	m_socket.beginPacket(r_ip, port);
	m_socket.write(data);
	m_socket.endPacket();
}

String Net::Read(){
	String data = "";

	return data;
}

void Net::RemotePort(unsigned int *port){
	port = &r_port;
}

void Net::RemoteClient(byte temp_ip[]){

	for(int i = 0; i < 4; i++){
		temp_ip[i] = r_ip[i];
	}
}

void Net::SaveRemoteIP(byte ip[]){
	writeEEPROM(ip, 25, 4);
	Serial.println(ip[1]);
}

void Net::ReadRemoteIP(){
	byte temp_ip[4];
	readEEPROM(temp_ip, 25, 4);
	r_ip = IPAddress(temp_ip[0], temp_ip[1], temp_ip[2], temp_ip[3]);
}

void Net::ReadRemoteIP(byte temp_ip[]){
	readEEPROM(temp_ip, 25, 4);
	r_ip = IPAddress(temp_ip[0], temp_ip[1], temp_ip[2], temp_ip[3]);
}

void Net::readEEPROM(byte data[], int offset, int length) {
  for (int i = 0; i < length; i++) {
    data[i] = EEPROM.read(offset + i);
  }
}

void Net::writeEEPROM(byte data[], int offset, int length) {
  for (int i = 0; i < length; i++) {
    EEPROM.write(offset + i, data[i]);
  }
}
