/*
t * Motor4Wheel.h
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#ifndef MOTORS_MOTOR4WHEEL_H_
#define MOTORS_MOTOR4WHEEL_H_

#include "Motor.h"

class Motor4Wheel:public Motor {
public:
	Motor4Wheel(PWM *pwm, GPIO *wheelFrontLeft_1, GPIO *wheelFrontLeft_2, GPIO *wheelFrontRight_1, GPIO *wheelFrontRight_2, GPIO *wheelBackLeft_1, GPIO *wheelBackLeft_2, GPIO *wheelBackRight_1, GPIO *wheelBackRight_2);
	virtual ~Motor4Wheel();

	virtual int forward();
	virtual int back();
	virtual int left();
	virtual int right();
};

#endif /* MOTORS_MOTOR4WHEEL_H_ */
