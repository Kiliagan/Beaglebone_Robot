/*
 * PWM.cpp
 *
 *  Created on: 9 Jul 2015
 *      Author: kilian
 *
 *  Based on PWM and util by Derek Molloy
 */

#include "PWM.h"

#include <cstdlib>
#include "util.h"

using namespace std;

/**
 * Creates object to control a PWM pin
 * @param pinName
 */
PWM::PWM(string pinName) {
	this->name = pinName;
	this->path = PWM_PATH + this->name + "/";
	this->analogFrequency = 100000;
	this->analogMax = 3.3;
}

/**
 * Set the cycle period for the PWM
 * @param period_ns
 * @return
 */
int PWM::setPeriod(unsigned int period_ns){
	return write(this->path, PWM_PERIOD, period_ns);
}

/**
 * returns the cycle period
 * @return
 */
unsigned int PWM::getPeriod(){
	return atoi(read(this->path, PWM_PERIOD).c_str());
}

/**
 * converts the period to a frequency
 * @param period_ns
 * @return
 */
float PWM::period_nsToFrequency(unsigned int period_ns){
	float period_s = (float)period_ns/1000000000;
	return 1.0f/period_s;
}

/**
 * converts frequency to a period
 * @param frequency_hz
 * @return
 */
unsigned int PWM::frequencyToPeriod_ns(float frequency_hz){
	float period_s = 1.0f/frequency_hz;
	return (unsigned int)(period_s*1000000000);
}

/**
 * sets frequency
 * @param frequency_hz
 * @return
 */
int PWM::setFrequency(float frequency_hz){
	return this->setPeriod(this->frequencyToPeriod_ns(frequency_hz));
}

/**
 * returns a frequency
 * @return
 */
float PWM::getFrequency(){
	return this->period_nsToFrequency(this->getPeriod());
}

/**
 * sets the duty cycle
 * @param duty_ns
 * @return
 */
int PWM::setDutyCycle(unsigned int duty_ns){
	return write(this->path, PWM_DUTY, duty_ns);
}

/**
 * sets the duty cycle based on speed percentagy
 * @param percentage
 * @return
 */
int PWM::setDutyCycle(float percentage){
	if ((percentage>100.0f)||(percentage<0.0f)) return -1;
	unsigned int period_ns = this->getPeriod();
	float duty_ns = period_ns * (percentage/100.0f);
	this->setDutyCycle((unsigned int) duty_ns );
	return 0;
}

/**
 * returns the duty cycle
 * @return
 */
unsigned int PWM::getDutyCycle(){
	return atoi(read(this->path, PWM_DUTY).c_str());
}

/**
 * gets duty cylce on percentage
 * @return
 */
float PWM::getDutyCyclePercent(){
	unsigned int period_ns = this->getPeriod();
	unsigned int duty_ns = this->getDutyCycle();
	return 100.0f * (float)duty_ns/(float)period_ns;
}

/**
 * sets the pins polarity
 * @param polarity
 * @return
 */
int PWM::setPolarity(PWM::POLARITY polarity){
	return write(this->path, PWM_POLARITY, polarity);
}

/**
 * reverse the polarity
 */
void PWM::invertPolarity(){
	if (this->getPolarity()==PWM::ACTIVE_LOW) this->setPolarity(PWM::ACTIVE_HIGH);
	else this->setPolarity(PWM::ACTIVE_LOW);
}

/**
 * returns the pins polarity
 * @return
 */
PWM::POLARITY PWM::getPolarity(){
	if (atoi(read(this->path, PWM_POLARITY).c_str())==0) return PWM::ACTIVE_LOW;
	else return PWM::ACTIVE_HIGH;
}

/**
 * sets make signal out
 * @param analogMax
 * @return
 */
int PWM::calibrateAnalogMax(float analogMax){ //must be between 3.2 and 3.4
	if((analogMax<3.2f) || (analogMax>3.4f)) return -1;
	else this->analogMax = analogMax;
	return 0;
}

/**
 * writes analogue data to the pin
 * @param voltage
 * @return
 */
int PWM::analogWrite(float voltage){
	if ((voltage<0.0f)||(voltage>3.3f)) return -1;
	this->setFrequency(this->analogFrequency);
	this->setPolarity(PWM::ACTIVE_LOW);
	this->setDutyCycle((100.0f*voltage)/this->analogMax);
	return this->run();
}

/**
 * turns on pin
 * @return
 */
int PWM::run(){
	return write(this->path, PWM_RUN, 1);
}

/**
 * checks if pin is on
 * @return
 */
bool PWM::isRunning(){
	string running = read(this->path, PWM_RUN);
	return (running=="1");
}

/**
 * turns off the pin
 * @return
 */
int PWM::stop(){
	return write(this->path, PWM_RUN, 0);
}

/**
 *
 */
PWM::~PWM() {
	// TODO Auto-generated destructor stub
}

