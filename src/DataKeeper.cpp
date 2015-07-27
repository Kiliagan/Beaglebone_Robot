/*
 * DataKeeper.cpp
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#include "DataKeeper.h"

DataKeeper::DataKeeper() {
	accelAccelX = 0;
	accelAccelY = 0;
	accelAccelZ = 0;
	accelGyroX = 0;
	accelGyroY = 0;
	accelGyroZ = 0;
	accelPitch = 0;
	accelRoll = 0;
	accelYaw = 0;
	gyroAccelX = 0;
	gyroAccelY = 0;
	gyroAccelZ = 0;
	gyroRoll = 0;
	gyroPitch = 0;
	irDistance = 0;
	magX = 0;
	magY = 0;
	magZ = 0;
	angX = 0;
	angY = 0;
	angZ = 0;
	heading = 0;
	headingDeg = 0;
}

void DataKeeper::setIRDistance(float irDistance){
	this->irDistance = irDistance;
}

void DataKeeper::setGyroAccelX(float gyroAccelX){
	this->gyroAccelX = gyroAccelX;
}

void DataKeeper::setGyroAccelY(float gyroAccelY){
	this->gyroAccelY = gyroAccelY;
}

void DataKeeper::setGyroAccelZ(float gyroAccelZ){
	this->gyroAccelZ = gyroAccelZ;
}

void DataKeeper::setGyroRoll(float gyroRoll){
	this->gyroRoll = gyroRoll;
}

void DataKeeper::setGyroPitch(float gyroPitch){
	this->gyroPitch = gyroPitch;
}

void DataKeeper::setAccelAccelX(float accelAccelX){
	this->accelAccelX = accelAccelX;
}

void DataKeeper::setAccelAccelY(float accelAccelY){
	this->accelAccelY = accelAccelY;
}

void DataKeeper::setAccelAccelZ(float accelAccelZ){
	this->accelAccelZ = accelAccelZ;
}

void DataKeeper::setAccelGyroX(float accelGyroX){
	this->accelGyroX = accelGyroX;
}

void DataKeeper::setAccelGyroY(float accelGyroY){
	this->accelGyroY = accelGyroY;
}

void DataKeeper::setAccelGyroZ(float accelGyroZ){
	this->accelGyroZ = accelGyroZ;
}

void DataKeeper::setAccelPitch(float accelPitch){
	this->accelPitch = accelPitch;
}

void DataKeeper::setAccelRoll(float accelRoll){
	this->accelRoll = accelRoll;
}

void DataKeeper::setAccelYaw(float accelYaw){
	this->accelYaw = accelYaw;
}

void DataKeeper::setMagX(float magX){
	this->magX = magX;
}

void DataKeeper::setMagY(float magY){
	this->magY = magY;
}

void DataKeeper::setMagZ(float magZ){
	this->magZ = magZ;
}

void DataKeeper::setAngX(float angX){
	this->angX = angX;
}

void DataKeeper::setAngY(float angY){
	this->angY = angY;
}

void DataKeeper::setAngZ(float angZ){
	this->angZ = angZ;
}

void DataKeeper::setHeading(float heading){
	this->heading = heading;
}

void DataKeeper::setHeadingDeg(float headingDeg){
	this->headingDeg = headingDeg;
}



DataKeeper::~DataKeeper() {

}

