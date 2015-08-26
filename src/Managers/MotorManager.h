/*
 * MotorManager.h
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#ifndef MOTORMANAGER_H_
#define MOTORMANAGER_H_

#include "../Motors/Motor2Wheel.h"
#include "../Motors/Motor4Wheel.h"
#include "DataKeeper.h"

class MotorManager {
private:
	int numWheels;
public:
	MotorManager(int numWheels);

	virtual void forward();
	virtual void back();
	virtual void left();
	virtual void right();

	virtual ~MotorManager();
};

#endif /* MOTORMANAGER_H_ */
