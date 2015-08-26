/*
 * MotorManager.cpp
 *
 *  Created on: 13 Jul 2015
 *      Author: kilian
 */

#include "MotorManager.h"

Motor2Wheel motorBase = Motor2Wheel(new PWM("pwm_test_P9_14.16"), new GPIO(60), new GPIO(51), new GPIO(30), new GPIO(31));

/**
 * Creates object knowing the wheels on the robot.
 * Either 2 or 4.
 * Code currently only allows for 2 wheel robots
 * @param numWheels
 */
MotorManager::MotorManager(int numWheels) {
	this->numWheels = numWheels;
	motorBase.turnOn();
}

/**
 * Tells the robot to move forward
 */
void MotorManager::forward(){
	if(this->numWheels == 2){
		motorBase.forward();
	}
}

/**
 * Tells robot to reverse
 */
void MotorManager::back(){
	if(this->numWheels == 2){
		motorBase.back();
	}
}

/**
 * Tells the robot to turn left
 */
void MotorManager::left(){
	if(this->numWheels == 2){
		motorBase.left();
	}
}

/**
 * Tells robot to turn right
 */
void MotorManager::right(){
	if(this->numWheels == 2){
		motorBase.right();
	}
}

MotorManager::~MotorManager() {
	motorBase.turnOff();
}

