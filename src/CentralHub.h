/*
 * CentralHub.h
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#ifndef CENTRALHUB_H_
#define CENTRALHUB_H_

#include "DataKeeper.h"
#include "AStar.h"
#include "Server.h"

class CentralHub {
public:
	CentralHub();
	virtual void start();
	virtual ~CentralHub();
};

#endif /* CENTRALHUB_H_ */
