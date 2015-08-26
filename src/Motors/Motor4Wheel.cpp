/*
 * Motor4Wheel.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#include "Motor4Wheel.h"

#include <unistd.h>
#include <iostream>
#include "../Pins/GPIO.h"

/**
 * Creates 4 wheeled robot object
 * @param pwm
 * @param wheelFrontLeft_1
 * @param wheelFrontLeft_2
 * @param wheelFrontRight_1
 * @param wheelFrontRight_2
 * @param wheelBackLeft_1
 * @param wheelBackLeft_2
 * @param wheelBackRight_1
 * @param wheelBackRight_2
 */
Motor4Wheel::Motor4Wheel(PWM *pwm, GPIO *wheelFrontLeft_1, GPIO *wheelFrontLeft_2, GPIO *wheelFrontRight_1, GPIO *wheelFrontRight_2, GPIO *wheelBackLeft_1, GPIO *wheelBackLeft_2, GPIO *wheelBackRight_1, GPIO *wheelBackRight_2):
	Motor(pwm){
	this->pwm = pwm;
	this->wheelFrontLeft_1 = wheelFrontLeft_1;
	this->wheelFrontLeft_2 = wheelFrontLeft_2;
	this->wheelFrontRight_1 = wheelFrontRight_1;
	this->wheelFrontRight_2 = wheelFrontRight_2;
	this->wheelBackLeft_1 = wheelBackLeft_1;
	this->wheelBackLeft_2 = wheelBackLeft_2;
	this->wheelBackRight_1 = wheelBackRight_1;
	this->wheelBackRight_2 = wheelBackRight_2;

}

/**
 * Moves robot forward
 * @return
 */
int Motor4Wheel::forward(){
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::HIGH);
	this->wheelFrontLeft_2->setValue(GPIO::LOW);
	this->wheelFrontRight_1->setValue(GPIO::HIGH);
	this->wheelFrontRight_2->setValue(GPIO::LOW);
	this->wheelBackLeft_1->setValue(GPIO::HIGH);
	this->wheelBackLeft_2->setValue(GPIO::LOW);
	this->wheelBackRight_1->setValue(GPIO::HIGH);
	this->wheelBackRight_2->setValue(GPIO::LOW);
	this->pwm->run();

	usleep(50000);

	this->pwm->stop();
	return 0;
}

/**
 * Robot moves backward
 * @return
 */
int Motor4Wheel::back(){
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::LOW);
	this->wheelFrontLeft_2->setValue(GPIO::HIGH);
	this->wheelFrontRight_1->setValue(GPIO::LOW);
	this->wheelFrontRight_2->setValue(GPIO::HIGH);
	this->wheelBackLeft_1->setValue(GPIO::LOW);
	this->wheelBackLeft_2->setValue(GPIO::HIGH);
	this->wheelBackRight_1->setValue(GPIO::LOW);
	this->wheelBackRight_2->setValue(GPIO::HIGH);
	this->pwm->run();

	usleep(50000);

	this->pwm->stop();
	return 0;
}

/**
 * Has robot turn left
 * @return
 */
int Motor4Wheel::left(){
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::LOW);
	this->wheelFrontLeft_2->setValue(GPIO::HIGH);
	this->wheelFrontRight_1->setValue(GPIO::HIGH);
	this->wheelFrontRight_2->setValue(GPIO::LOW);
	this->wheelBackLeft_1->setValue(GPIO::LOW);
	this->wheelBackLeft_2->setValue(GPIO::HIGH);
	this->wheelBackRight_1->setValue(GPIO::HIGH);
	this->wheelBackRight_2->setValue(GPIO::LOW);
	this->pwm->run();

	usleep(50000);

	this->pwm->stop();
	return 0;
}

/**
 * Has robot turn right
 * @return
 */
int Motor4Wheel::right(){
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::HIGH);
	this->wheelFrontLeft_2->setValue(GPIO::LOW);
	this->wheelFrontRight_1->setValue(GPIO::LOW);
	this->wheelFrontRight_2->setValue(GPIO::HIGH);
	this->wheelBackLeft_1->setValue(GPIO::HIGH);
	this->wheelBackLeft_2->setValue(GPIO::LOW);
	this->wheelBackRight_1->setValue(GPIO::LOW);
	this->wheelBackRight_2->setValue(GPIO::HIGH);
	this->pwm->run();

	usleep(50000);

	this->pwm->stop();
	return 0;
}

Motor4Wheel::~Motor4Wheel() {
	// TODO Auto-generated destructor stub
}

