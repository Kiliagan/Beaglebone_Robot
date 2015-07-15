/*
 * IR2Y0A21.cpp
 *
 *  Created on: 6 Jul 2015
 *      Author: kilian
 */

#include "IR2Y0A21.h"

#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<cmath>

using namespace std;

#define IR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage4_raw"

/**
 *
 */
IR2Y0A21::IR2Y0A21() {
}

/**
 *
 */
IR2Y0A21::~IR2Y0A21() {
}

/**
 *
 * @return
 */
int IR2Y0A21::readAnalogue(){
	int ain = 0;

	stringstream ss;
	ss << IR_PATH;
	fstream fs;
	fs.open(ss.str().c_str(), fstream::in);
	fs >> ain;
	fs.close();

	return ain;
}

/**
 *
 * @return
 */
float IR2Y0A21::getDistanceRAW(){
	float distance = readAnalogue() * 1.0f;

	return distance;
}

/**
 *
 * @return
 */
float IR2Y0A21::getDistance(){
	float power = -1/0.65;
	float constant = 75636;
	float distance = pow((getDistanceRAW()/constant), power);

	return distance;
}
