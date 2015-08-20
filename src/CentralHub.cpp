/*
 * CentralHub.cpp
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#include "CentralHub.h"

/**
 *
 */
CentralHub::CentralHub() {
	// TODO Auto-generated constructor stub

}

/**
 *
 */
CentralHub::~CentralHub() {
	// TODO Auto-generated destructor stub
}

/**
 *
 * @param dataKeeper
 */
void CentralHub::start(){
	AStar pathPlanner = AStar();
	Server server = Server(5050);

	server.startServer();
}
