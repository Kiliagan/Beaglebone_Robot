/*
 * Client.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#include <iostream>
#include "Client.h"
#include "Networking/SocketClient.h"

//using namespace std;

Client::Client(std::string ip, int port) {
	this->ip=ip;
	this->port=port;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::startClient(){
	std::cout << "Starting EBB Client Example" << std::endl;
	SocketClient sc(ip, port);
	sc.connectToServer();
	std::string message("Hello from the Client");
	std::cout << "Sending [" << message << "]" << std::endl;
	sc.send(message);
	std::string rec = sc.receive(1024);
	std::cout << "Received [" << rec << "]" << std::endl;
	std::cout << "End of EBB Client Example" << std::endl;
}
