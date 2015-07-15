/*
 * MotorManager.cpp
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#include "MotorManager.h"

Motor2Wheel motorBase = Motor2Wheel(new PWM("pwm_test_P9_14.16"), new GPIO(60), new GPIO(51), new GPIO(30), new GPIO(31));

MotorManager::MotorManager() {
	motorBase.turnOn();
}

void MotorManager::driveMotors(DataKeeper &dataKeeper){

	if( dataKeeper.getIRDistance() <= 100){
		motorBase.move('r');
	}
	else{
		motorBase.move('f');
	}

}


MotorManager::~MotorManager() {
	motorBase.turnOff();
}

