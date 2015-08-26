/*
 * Server.cpp
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#include "Server.h"
#include "SocketServer.h"

/**
 * Creates server listening on selected port
 * @param port
 */
Server::Server(int port) {
	this->port=port;
}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

/**
 * Starts the server to listen for connections
 * @param dataKeeper
 */
void Server::startServer(){
	std::cout << "Starting EBB Server Example" << std::endl;
	SocketServer server(port);
	std::cout << "Listening for a connection..." << std::endl;
	server.threadedListen();
	std::cout << "End of EBB Server Example" << std::endl;
}
