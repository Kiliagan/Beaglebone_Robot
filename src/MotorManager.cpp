/*
 * MotorManager.cpp
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#include "MotorManager.h"
#include <iostream>

Motor2Wheel motorBase = Motor2Wheel(new PWM("pwm_test_P9_14.16"), new GPIO(60), new GPIO(51), new GPIO(30), new GPIO(31));

MotorManager::MotorManager() {
	motorBase.turnOn();
}

int MotorManager::turn(char direction,DataKeeper &dataKeeper, SensorManager &sensorManager){

	float curAngle = dataKeeper.getHeadingDeg();
	float finAngle;

	if(direction == 'r'){
		finAngle = curAngle - 90;
	}
	else if(direction == 'l'){
		finAngle = curAngle + 90;
	}
	else{
		return -1;
	}

	if(finAngle > 360){ finAngle -= 360;}
	else if(finAngle < 0){ finAngle += 360;}

	//motorBase.startPWM();

	while(curAngle < (finAngle - 2) && curAngle > (finAngle + 2)){
		motorBase.move(direction);
		sensorManager.readSensors(dataKeeper);
		curAngle = dataKeeper.getHeadingDeg();
		std::cout << curAngle << std::endl;
	}

	//motorBase.stopPWM();

	return 0;
}

void MotorManager::driveMotors(DataKeeper &dataKeeper, SensorManager &sensorManager){

	sensorManager.readSensors(dataKeeper);

	if( dataKeeper.getIRDistance() <= 100){
		this->turn('l',dataKeeper, sensorManager);
		//motorBase.left();
	}
	else{
		motorBase.move('f');
	}

}


MotorManager::~MotorManager() {
	motorBase.turnOff();
}

