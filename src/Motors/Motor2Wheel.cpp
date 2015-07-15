/*
 * Motor2Wheel.cpp
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#include "Motor2Wheel.h"

#include <unistd.h>
#include <iostream>
#include "../Pins/GPIO.h"

/**
 *
 * @param pwm
 * @param wheelFrontLeft_1
 * @param wheelFrontLeft_2
 * @param wheelFrontRight_1
 * @param wheelFrontRight_2
 */
Motor2Wheel::Motor2Wheel(PWM *pwm, GPIO *wheelFrontLeft_1,
		GPIO *wheelFrontLeft_2, GPIO *wheelFrontRight_1, GPIO *wheelFrontRight_2) :
		Motor(pwm) {
	this->pwm = pwm;
	this->wheelFrontLeft_1 = wheelFrontLeft_1;
	this->wheelFrontLeft_2 = wheelFrontLeft_2;
	this->wheelFrontRight_1 = wheelFrontRight_1;
	this->wheelFrontRight_2 = wheelFrontRight_2;

}

/**
 *
 * @return
 */
int Motor2Wheel::forward() {
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::HIGH);
	this->wheelFrontLeft_2->setValue(GPIO::LOW);
	this->wheelFrontRight_1->setValue(GPIO::HIGH);
	this->wheelFrontRight_2->setValue(GPIO::LOW);
	this->pwm->run();

	usleep(500000);

	//switch wheels off.
	this->pwm->stop();
	return 0;
}

/**
 *
 * @return
 */
int Motor2Wheel::back() {
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::LOW);
	this->wheelFrontLeft_2->setValue(GPIO::HIGH);
	this->wheelFrontRight_1->setValue(GPIO::LOW);
	this->wheelFrontRight_2->setValue(GPIO::HIGH);
	this->pwm->run();

	usleep(500000);

	//switch wheels off.
	this->pwm->stop();
	return 0;
}

/**
 *
 * @return
 */
int Motor2Wheel::left() {
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::LOW);
	this->wheelFrontLeft_2->setValue(GPIO::HIGH);
	this->wheelFrontRight_1->setValue(GPIO::HIGH);
	this->wheelFrontRight_2->setValue(GPIO::LOW);
	this->pwm->run();

	usleep(500000);

	//switch wheels off.
	this->pwm->stop();
	return 0;
}

/**
 *
 * @return
 */
int Motor2Wheel::right() {
	//turn wheels on.
	this->wheelFrontLeft_1->setValue(GPIO::HIGH);
	this->wheelFrontLeft_2->setValue(GPIO::LOW);
	this->wheelFrontRight_1->setValue(GPIO::LOW);
	this->wheelFrontRight_2->setValue(GPIO::HIGH);
	this->pwm->run();

	usleep(500000);

	//switch wheels off.
	this->pwm->stop();
	return 0;
}

/**
 *
 */
Motor2Wheel::~Motor2Wheel() {
	// TODO Auto-generated destructor stub
}

