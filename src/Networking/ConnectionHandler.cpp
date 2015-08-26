/*
 * ConnectionHandler.cpp
 *
 *  Created on: 10 Aug 2015
 *      Author: root
 */
/*
 * ConnectionHandler.cpp  Created on: 18 Jul 2014
 * Copyright (c) 2014 Derek Molloy (www.derekmolloy.ie)
 * Made available for the book "Exploring BeagleBone"
 * See: www.exploringbeaglebone.com
 * Licensed under the EUPL V.1.1
 *
 * This Software is provided to You under the terms of the European
 * Union Public License (the "EUPL") version 1.1 as published by the
 * European Union. Any use of this Software, other than as authorized
 * under this License is strictly prohibited (to the extent such use
 * is covered by a right of the copyright holder of this Software).
 *
 * This Software is provided under the License on an "AS IS" basis and
 * without warranties of any kind concerning the Software, including
 * without limitation merchantability, fitness for a particular purpose,
 * absence of defects or errors, accuracy, and non-infringement of
 * intellectual property rights other than copyright. This disclaimer
 * of warranty is an essential part of the License and a condition for
 * the grant of any rights to this Software.
 *
 * For more details, see http://www.derekmolloy.ie/
 */

#include "ConnectionHandler.h"

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>

#include "SocketServer.h"

using namespace std;

/**
 * Creates the connection handler to deal with clients
 * @param parent
 * @param client
 * @param clientSocketfd
 */
ConnectionHandler::ConnectionHandler(SocketServer *parent, sockaddr_in *client, int clientSocketfd) {
	this->parent = parent;
	this->client = client;
	this->clientSocketfd = clientSocketfd;
	this->running = true;
}

/**
 * destroys connection handler
 */
ConnectionHandler::~ConnectionHandler() {
	delete this->client;
	cout << "Destroyed a Connection Handler" << endl;
}

/**
 * Starts up the thread
 * @param dataKeeper
 * @return
 */
int ConnectionHandler::start(){
	//cout << "Starting the Connection Handler thread" << endl;
	return (pthread_create(&(this->thread), NULL, threadHelper, this)==0);
}

/**
 * pauses thread
 */
void ConnectionHandler::wait(){
	(void) pthread_join(this->thread, NULL);
}

/**
 * sends a message back to client
 * @param message
 * @return
 */
int ConnectionHandler::send(std::string message){
	const char *writeBuffer = message.data();
	int length = message.length();
    int n = write(this->clientSocketfd, writeBuffer, length);
    if (n < 0){
       perror("Connection Handler: error writing to server socket.");
       return 1;
    }
    return 0;
}

/**
 * reads in data from client
 * @param size
 * @return
 */
string ConnectionHandler::receive(int size=1024){
    char readBuffer[size];
    bzero(readBuffer, size);
    int n = read(this->clientSocketfd, readBuffer, sizeof(readBuffer));
    if (n < 0){
       perror("Connection Handler: error reading from server socket.");
    }
    return string(readBuffer);
}

/**
 * The loop that is run by the server to deal with the clients.
 * reads in string from the server and sends back the path generated
 */
void ConnectionHandler::threadLoop(){
    //cout << "*** Created a Connection Handler threaded Function" << endl;
	DataKeeper dataKeeper = DataKeeper();
    while(this->running){
       string rec = this->receive(1024);
       cout << "Received from the client [" << rec << "]" << endl;
       int x, option;
       istringstream(rec.substr(0,1)) >> option;
       if(option==1){
    	   istringstream(rec.substr(2,2)) >> x;
    	   dataKeeper.setCurrentX(x);
    	   istringstream(rec.substr(5,2)) >> x;
    	   dataKeeper.setCurrentY(x);
    	   istringstream(rec.substr(8,2)) >> x;
    	   dataKeeper.setDestX(x);
    	   istringstream(rec.substr(11,2)) >> x;
    	   dataKeeper.setDestY(x);
       }else if(option==2){
    	   istringstream(rec.substr(2,2)) >> x;
    	   dataKeeper.setCurrentX(x);
    	   istringstream(rec.substr(5,2)) >> x;
    	   dataKeeper.setCurrentY(x);
    	   istringstream(rec.substr(8,1)) >> x;
    	   switch(x){
    	   case 0: pathPlanner.newObstacle(dataKeeper.getCurrentX()+1, dataKeeper.getCurrentY());break;
    	   case 1: pathPlanner.newObstacle(dataKeeper.getCurrentX(), dataKeeper.getCurrentY()-1);break;
    	   case 2: pathPlanner.newObstacle(dataKeeper.getCurrentX()-1, dataKeeper.getCurrentY());break;
    	   case 3: pathPlanner.newObstacle(dataKeeper.getCurrentX(), dataKeeper.getCurrentY()+1);break;
    	   }
       }
       usleep(2000000);
       pathPlanner.main(dataKeeper);
       string message(dataKeeper.getPath());
       cout << "Sending back [" << message << "]" << endl;
       cout << "  but going asleep for 5 seconds first...." << endl;
       usleep(5000000);
       this->send(message);
       this->running = false;
	}
    //cout << "*** End of the Connection Handler Function" << endl;
    this->parent->notifyHandlerDeath(this);
}
