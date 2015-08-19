/*
 * RoamingBot.h
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#ifndef ROAMINGBOT_H_
#define ROAMINGBOT_H_

#include "SensorManager.h"
#include "DataKeeper.h"
#include "MotorManager.h"
#include "AStar.h"
#include "Client.h"

class RoamingBot {
private:
	int UP;
	int RIGHT;
	int DOWN;
	int LEFT;
public:
	RoamingBot();
	virtual void start(DataKeeper &dataKeeper, int wheels);
	virtual void direction(DataKeeper &dataKeeper, SensorManager &sensorManager, MotorManager &motorManager, int dir);
	virtual ~RoamingBot();
};

#endif /* ROAMINGBOT_H_ */
