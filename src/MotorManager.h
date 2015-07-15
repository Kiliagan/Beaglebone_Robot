/*
 * MotorManager.h
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#ifndef MOTORMANAGER_H_
#define MOTORMANAGER_H_

#include "Motors/Motor2Wheel.h"
#include "Motors/Motor4Wheel.h"
#include "DataKeeper.h"

class MotorManager {
public:
	MotorManager();
	virtual void driveMotors(DataKeeper &dataKeeper);
	virtual ~MotorManager();
};

#endif /* MOTORMANAGER_H_ */
