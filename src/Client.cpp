/*
 * Client.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#include <iostream>
#include <sstream>
#include "Client.h"
#include "Networking/SocketClient.h"

Client::Client(std::string ip, int port) {
	this->ip=ip;
	this->port=port;
}

Client::~Client() {
}

void Client::startClient(DataKeeper &dataKeeper){

	std::cout << "Starting EBB Client Example" << std::endl;
	SocketClient sc(ip, port);
	sc.connectToServer();
	std::string message("00 00 52 40");
	std::cout << "Sending [" << message << "]" << std::endl;
	sc.send(message);
	std::string rec = sc.receive(1024);
	dataKeeper.setPath(rec);
	std::cout << "Received [" << rec << "]" << std::endl;
	std::cout << "End of EBB Client Example" << std::endl;

}
