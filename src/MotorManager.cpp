/*
 * MotorManager.cpp
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#include "MotorManager.h"

Motor2Wheel motorBase = Motor2Wheel(new PWM("pwm_test_P9_14.16"), new GPIO(60), new GPIO(51), new GPIO(30), new GPIO(31));

MotorManager::MotorManager(int numWheels) {
	this->numWheels = numWheels;
	motorBase.turnOn();
}

void MotorManager::forward(){
	if(this->numWheels == 2){
		motorBase.forward();
	}
}

void MotorManager::back(){
	if(this->numWheels == 2){
		motorBase.back();
	}
}

void MotorManager::left(){
	if(this->numWheels == 2){
		motorBase.left();
	}
}

void MotorManager::right(){
	if(this->numWheels == 2){
		motorBase.right();
	}
}

MotorManager::~MotorManager() {
	motorBase.turnOff();
}

