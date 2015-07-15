/*
 * Motor.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#include "Motor.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include "../Pins/GPIO.h"
#include "../Pins/PWM.h"

using namespace std;

/**
 *
 * @param pwm
 */
Motor::Motor(PWM *pwm) {
	this->pwm = pwm;
	this->wheelFrontLeft_1 = 0;
	this->wheelFrontLeft_2 = 0;
	this->wheelFrontRight_1 = 0;
	this->wheelFrontRight_2 = 0;
	this->wheelBackLeft_1 = 0;
	this->wheelBackLeft_2 = 0;
	this->wheelBackRight_1 = 0;
	this->wheelBackRight_2 = 0;
	this->pwm->setPolarity(PWM::ACTIVE_LOW);
	this->setDutyCyclePeriod(DEFAULT_MOTOR_PWM_PERIOD);
	this->setSpeedPercent(0);
}

/**
 *
 * @param direction
 * @return
 */
int Motor::move(char direction){
		if(direction == 'f'){ //f for forward.
			this->forward();
			return 0;
		}
		else if(direction == 'b'){ //b for back
			this->back();
			return 0;
		}
		else if(direction == 'l'){ //l for left
			this->left();
			return 0;
		}
		else if(direction == 'r'){ //r for right
			this->right();
			return 0;
		}
		return 1;
	
}
	
/**
 *
 */
void Motor::turnOn(){
      //Export PINS:
    	 this->pwm->run();
    	 this->wheelFrontLeft_1->exportGPIO();
    	 this->wheelFrontLeft_2->exportGPIO();
    	 this->wheelFrontRight_1->exportGPIO();
    	 this->wheelFrontRight_2->exportGPIO();
    	 if(wheelBackLeft_1 != 0 && wheelBackRight_1 != 0 && wheelBackLeft_2 != 0 && wheelBackRight_2 != 0){
    	 	this->wheelBackLeft_1->exportGPIO();
    	 	this->wheelBackLeft_2->exportGPIO();
    	 	this->wheelBackRight_1->exportGPIO();
    	 	this->wheelBackRight_2->exportGPIO();
    	  }
    	 
     //Set PINS to Outputs:
    	 this->wheelFrontLeft_1->setDirection(GPIO::OUTPUT);
    	 this->wheelFrontLeft_2->setDirection(GPIO::OUTPUT);
    	 this->wheelFrontRight_1->setDirection(GPIO::OUTPUT);
    	 this->wheelFrontRight_2->setDirection(GPIO::OUTPUT);
    	 if(wheelBackLeft_1 != 0 && wheelBackRight_1 != 0 && wheelBackLeft_2 != 0 && wheelBackRight_2 != 0){
    	 	this->wheelBackLeft_1->setDirection(GPIO::OUTPUT);
    	 	this->wheelBackLeft_2->setDirection(GPIO::OUTPUT);
    	 	this->wheelBackRight_1->setDirection(GPIO::OUTPUT);
    	 	this->wheelBackRight_2->setDirection(GPIO::OUTPUT);
    	 }
}

/**
 *
 */
void Motor::turnOff(){
    	//UNEXPORT PINS
    	this->pwm->stop();
    	this->wheelFrontLeft_1->unexportGPIO();
    	this->wheelFrontLeft_2->unexportGPIO();
    	this->wheelFrontRight_1->unexportGPIO();
    	this->wheelFrontRight_2->unexportGPIO();
    	if(wheelBackLeft_1 != 0 && wheelBackRight_1 != 0 && wheelBackLeft_2 != 0 && wheelBackRight_2 != 0){
    	 	this->wheelBackLeft_1->unexportGPIO();
    	 	this->wheelBackLeft_2->unexportGPIO();
    	 	this->wheelBackRight_1->unexportGPIO();
    	 	this->wheelBackRight_2->unexportGPIO();
    	}
}
     
void Motor::setSpeedPercent(float speedPercentage){
	this->pwm->setDutyCycle(speedPercentage);
	this->speedPercent = speedPercentage;
}

void Motor::setDutyCyclePeriod(unsigned int period_ns){
	this->pwm->setPeriod(period_ns);
}

/**
 *
 */
Motor::~Motor() {
	
}

