#include <Arduino.h>
#include <Ethernet.h>
#include "Cmd.h"
#include <SPI.h>
#include <NetEEPROM.h>
#include "IRIGB/IRIGB.h"
#include "Net/Net.h"

#define ESC 27
#define CONFIG_TIMEOUT 3

bool config = false;

IRIGB *irig_boden;
IRIGB *irig_borlange;
Net *net;

void help(int arg_cnt, char **args) {
  Serial.println("Avaliable commands:\n");
  Serial.printf("%-42s%-64s\r\n", "ipset <address> <subnet> <gateway>", "- update ip address, subnet and gateway\n");
  Serial.printf("%-42s%-64s\r\n", "dnsset <address>", "- update dns server address\n");
  Serial.printf("%-42s%-64s\r\n", "ipconfig", "- show information\n");
  Serial.printf("%-42s%-64s\r\n", "irig config", "- configure irig parameters\n");
  Serial.printf("%-42s%-64s\r\n", "irig status", "- prints irig parameters\n");
  Serial.printf("%-42s%-64s\r\n", "exit", "- exit configuration menu\n");
  Serial.printf("%-42s%-64s\r\n", "help, ?", "- show this menu\n");
}

void printIp(byte ip[]) {
  for (int i = 0; i < 4; i++) {
    if (i > 0) {
      Serial.print(".");
    }
    Serial.print(ip[i]);
  }
}

void ipconfig(int arg_cnt, char **args){

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


	Serial.println();
	Serial.println("Arduino IP Configuration\n");
	Serial.println("Ethernet Shield Adapter\n");
	Serial.printf("%-25s%-2s%2X-%2X-%2X-%2X-%2X-%2X\n","\tMAC Address: " , ": ", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	Serial.printf("%-25s%-2s%d.%d.%d.%d\n","\tIPv4 Address: " , ": ", ip[0], ip[1], ip[2], ip[3]);
	Serial.printf("%-25s%-2s%d.%d.%d.%d\n","\tSubnet Mask: " , ": ", subnet[0], subnet[1], subnet[2], subnet[3]);
	Serial.printf("%-25s%-2s%d.%d.%d.%d\n","\tDefault Gateway: " , ": ", gateway[0], gateway[1], gateway[2], gateway[3]);
	Serial.printf("%-25s%-2s%d.%d.%d.%d\n","\tDNS Server: " , ": ", dns[0], dns[1], dns[2], dns[3]);
	Serial.println();

}

void dnsset(int arg_cnt, char **args){

	char *dns_pointer = args[1];
	int cnt = 0;
	byte dns[4];
	for(char *p = strtok(dns_pointer, "."); p != NULL; p = strtok(NULL, "."), ++cnt){
		unsigned int temp = atoi(p);
		if(temp < 256){
			dns[cnt] = (byte)temp;
		} else {
			Serial.println("Wrong DNS address format.");
			return;
		}
	}


	//Need to read all before changing them all together ... (need to change lib-code otherwise :/ )
	byte mac[6];
	byte ip[4];
	byte sub[4];
	byte gw[4];
	NetEeprom.readMac(mac);
	NetEeprom.readIp(ip);
	NetEeprom.readSubnet(sub);
	NetEeprom.readGateway(gw);

	NetEeprom.writeManualConfig(mac, ip, dns, gw, sub);
}

void ipset(int arg_cnt, char **args){

	char *ip_pointer = args[1];
	int cnt = 0;
	byte ip[4];
	for(char *p = strtok(ip_pointer, "."); p != NULL; p = strtok(NULL, "."), ++cnt){
		unsigned int temp = atoi(p);
		if(temp < 256){
			ip[cnt] = (byte)temp;
		} else {
			Serial.println("Wrong IP address format.");
			return;
		}
	}

	char *sub_pointer = args[2];
	int sub_cnt = 0;
	byte sub[4];
	for(char *p = strtok(sub_pointer, "."); p != NULL; p = strtok(NULL, "."), ++sub_cnt){
		unsigned int temp = atoi(p);
		if(temp < 256){
			sub[sub_cnt] = (byte)temp;
		} else {
			Serial.println("Wrong subnet format.");
			return;
		}
	}

	char *gw_pointer = args[3];
	int gw_cnt = 0;
	byte gw[4];
	for(char *p = strtok(gw_pointer, "."); p != NULL; p = strtok(NULL, "."), ++gw_cnt){
		unsigned int temp = atoi(p);
		if(temp < 256){
			gw[gw_cnt] = (byte)temp;
		} else {
			Serial.println("Wrong gateway format.");
			return;
		}
	}

	//Need to read mac and dns ...
	byte mac[6];
	byte dns[4];
	NetEeprom.readMac(mac);
	NetEeprom.readDns(dns);
	NetEeprom.writeManualConfig(mac, ip, dns, gw, sub);
}

void exit_config(int arg_cnt, char **args){
	config = false;
}

void irig(int arg_cnt, char **args){
	const char* config = "config";
	const char* status = "status";
	for (int i=0; i<arg_cnt; i++) {
		if((arg_cnt == 3) &&((!strcmp(args[i],config)) && (strlen(args[i]) == strlen(config)))){
			char *rip_pointer = args[2];
			int rip_cnt = 0;
			byte rip[4];
			for(char *p = strtok(rip_pointer, "."); p != NULL; p = strtok(NULL, "."), ++rip_cnt){
				unsigned int temp = atoi(p);
				if(temp < 256){
					rip[rip_cnt] = (byte)temp;
				} else {
					Serial.println("Wrong remote IP address format.");
					return;
				}
			}

			net->SaveRemoteIP(rip);
			break;
		}
		if((!strcmp(args[i],status)) && (strlen(args[i]) == strlen(status))){
			Serial.println("IRIG Status:");
			Serial.println("Remote address: ");
			byte ip[4];
			net->ReadRemoteIP(ip);
			for(int i = 0; i < 4; i++){
				Serial.print(ip[i]);
				if(!(i == 3)){
					Serial.print(".");
				}
			}
			Serial.println();
			Serial.println("Remote port: ");
			unsigned int port;
			net->RemotePort(&port);
			Serial.printf("%5d\n", port);
			break;
		}
	}
}

void setup() {

	cmdInit(9600);

	cmdAdd("help", help);
	cmdAdd("?", help);
	cmdAdd("ipconfig", ipconfig);
	cmdAdd("ipset", ipset);
	cmdAdd("dnsset", dnsset);
	cmdAdd("irig", irig);
	cmdAdd("exit", exit_config);

	irig_boden = new IRIGB(2);
	irig_borlange = new IRIGB(4);
	net = new Net();

	Serial.println("Press <ENTER> to enter the configuration menu.\n\n");
	Serial.println("Starting IRIG-B listener in...");

	int i;
	for(i = CONFIG_TIMEOUT; i > 0 && !Serial.available(); i--){
		Serial.println(i);
		delay(1000);
	}

	if(i > 0){
		config = true;
		Serial.println("Welcome to Arduino Configuration! \n\n");
		while(config){
			cmdPoll();
		}
	}

	net->Begin();
	Serial.println("IRIG-B Listener started. Press <RESET> on hardware board to interrupt.");
}

void loop() {


	char time_boden[30] = {0};
	char time_borlange[30] = {0};

	irig_boden->ReadTimeFrame(time_boden);
	irig_boden->ReadTimeFrame(time_borlange);




	char frame[30];
	sprintf(frame, "%s%s%s", "BDN;", time_boden , ";");

	char frame2[30];
	sprintf(frame, "%s%s%s", "BDN;", time_borlange, ";");


	net->Send(frame, 5555);
	net->Send(frame2, 5555);
	Serial.println(time_boden);

}



