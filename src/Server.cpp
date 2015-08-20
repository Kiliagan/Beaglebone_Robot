/*
 * Server.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#include "Server.h"
#include "Networking/SocketServer.h"

/**
 *
 * @param port
 */
Server::Server(int port) {
	this->port=port;
}

/**
 *
 */
Server::~Server() {
	// TODO Auto-generated destructor stub
}

/**
 *
 * @param dataKeeper
 */
void Server::startServer(){
	std::cout << "Starting EBB Server Example" << std::endl;
	SocketServer server(port);
	std::cout << "Listening for a connection..." << std::endl;
	server.threadedListen();
	std::cout << "End of EBB Server Example" << std::endl;
}
