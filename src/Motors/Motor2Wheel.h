/*
 * Motor2Wheel.h
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#ifndef MOTORS_MOTOR2WHEEL_H_
#define MOTORS_MOTOR2WHEEL_H_

#include "Motor.h"

class Motor2Wheel:public Motor {
public:
	Motor2Wheel(PWM *pwm, GPIO *wheelFrontLeft_1, GPIO *wheelFrontLeft_2, GPIO *wheelFrontRight_1, GPIO *wheelFrontRight_2);
	virtual ~Motor2Wheel();

	virtual int forward();
	virtual int back();
	virtual int left();
	virtual int right();
};

#endif /* MOTORS_MOTOR2WHEEL_H_ */
