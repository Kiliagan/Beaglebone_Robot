/*
 * Motor.h
 *
 *  Created on: 8 Jul 2015
 *      Author: kilian
 */

#ifndef MOTORS_MOTOR_H_
#define MOTORS_MOTOR_H_

#include "../Pins/GPIO.h"
#include "../Pins/PWM.h"

#define DEFAULT_MOTOR_PWM_PERIOD 	2000
#define DEFAULT_MOTOR_SPEED			50.0f

class Motor {

public:
	Motor(PWM *pwm);
	int move(char);
	void turnOn();
	void turnOff();
	virtual ~Motor();
	virtual void setSpeedPercent(float speedPercent);
	virtual float getSpeedPercent() { return this->speedPercent; }
	virtual void setDutyCyclePeriod(unsigned int period_ns);

protected:
	PWM *pwm;
	GPIO *wheelFrontLeft_1;
	GPIO *wheelFrontLeft_2;
	GPIO *wheelFrontRight_1;
	GPIO *wheelFrontRight_2;
	GPIO *wheelBackLeft_1;
	GPIO *wheelBackLeft_2;
	GPIO *wheelBackRight_1;
	GPIO *wheelBackRight_2;
	float speedPercent;

	virtual int forward() = 0;
	virtual int back() = 0;
	virtual int left() = 0;
	virtual int right() = 0;
};

#endif /* MOTORS_MOTOR_H_ */
