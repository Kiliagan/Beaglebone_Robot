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

/**
 *
 * @param ip
 * @param port
 */
Client::Client(std::string ip, int port) {
	this->ip=ip;
	this->port=port;
}

/**
 *
 */
Client::~Client() {
}

/**
 *
 * @param dataKeeper
 * @param option
 */
void Client::startClient(DataKeeper &dataKeeper, int option){

	std::cout << "Starting EBB Client Example" << std::endl;
	SocketClient sc(ip, port);
	sc.connectToServer();
	//std::string message("00 00 52 30");
	std::stringstream ss;
	if(option==1){
		ss << option << " ";
		if(dataKeeper.getCurrentX() < 10){ ss << "0";}
		ss << dataKeeper.getCurrentX() << " ";
		if(dataKeeper.getCurrentY() < 10){ ss << "0";}
		ss << dataKeeper.getCurrentY() << " ";
		if(dataKeeper.getDestX() < 10){ ss << "0";}
		ss << dataKeeper.getDestX() << " ";
		if(dataKeeper.getDestY() < 10){ ss << "0";}
		ss << dataKeeper.getDestY();
	}else if(option==2){
		ss << option << " ";
		if(dataKeeper.getCurrentX() < 10){ ss << "0";}
		ss << dataKeeper.getCurrentX() << " ";
		if(dataKeeper.getCurrentY() < 10){ ss << "0";}
		ss << dataKeeper.getCurrentY() << " ";
		ss << dataKeeper.getFacing();
	}
	std::string message = ss.str();
	std::cout << "Sending [" << message << "]" << std::endl;
	sc.send(message);
	std::string rec = sc.receive(1024);
	dataKeeper.setPath(rec);
	std::cout << "Received [" << rec << "]" << std::endl;
	std::cout << "End of EBB Client Example" << std::endl;

}
