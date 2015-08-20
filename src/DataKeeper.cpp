/*
 * DataKeeper.cpp
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#include "DataKeeper.h"

/**
 *
 */
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
	irRaw = 0;
	magX = 0;
	magY = 0;
	magZ = 0;
	angX = 0;
	angY = 0;
	angZ = 0;
	heading = 0;
	headingDeg = 0;
	path = "No Path";
	currentX = 0;
	currentY = 0;
	destX = 0;
	destY = 0;
	facing = 0;
}

/**
 *
 * @param irDistance
 */
void DataKeeper::setIRDistance(float irDistance){
	this->irDistance = irDistance;
}

/**
 *
 * @param irRaw
 */
void DataKeeper::setIRRaw(float irRaw){
	this->irRaw = irRaw;
}

/**
 *
 * @param gyroAccelX
 */
void DataKeeper::setGyroAccelX(float gyroAccelX){
	this->gyroAccelX = gyroAccelX;
}

/**
 *
 * @param gyroAccelY
 */
void DataKeeper::setGyroAccelY(float gyroAccelY){
	this->gyroAccelY = gyroAccelY;
}

/**
 *
 * @param gyroAccelZ
 */
void DataKeeper::setGyroAccelZ(float gyroAccelZ){
	this->gyroAccelZ = gyroAccelZ;
}

/**
 *
 * @param gyroRoll
 */
void DataKeeper::setGyroRoll(float gyroRoll){
	this->gyroRoll = gyroRoll;
}

/**
 *
 * @param gyroPitch
 */
void DataKeeper::setGyroPitch(float gyroPitch){
	this->gyroPitch = gyroPitch;
}

/**
 *
 * @param accelAccelX
 */
void DataKeeper::setAccelAccelX(float accelAccelX){
	this->accelAccelX = accelAccelX;
}

/**
 *
 * @param accelAccelY
 */
void DataKeeper::setAccelAccelY(float accelAccelY){
	this->accelAccelY = accelAccelY;
}

/**
 *
 * @param accelAccelZ
 */
void DataKeeper::setAccelAccelZ(float accelAccelZ){
	this->accelAccelZ = accelAccelZ;
}

/**
 *
 * @param accelGyroX
 */
void DataKeeper::setAccelGyroX(float accelGyroX){
	this->accelGyroX = accelGyroX;
}

/**
 *
 * @param accelGyroY
 */
void DataKeeper::setAccelGyroY(float accelGyroY){
	this->accelGyroY = accelGyroY;
}

/**
 *
 * @param accelGyroZ
 */
void DataKeeper::setAccelGyroZ(float accelGyroZ){
	this->accelGyroZ = accelGyroZ;
}

/**
 *
 * @param accelPitch
 */
void DataKeeper::setAccelPitch(float accelPitch){
	this->accelPitch = accelPitch;
}

/**
 *
 * @param accelRoll
 */
void DataKeeper::setAccelRoll(float accelRoll){
	this->accelRoll = accelRoll;
}

/**
 *
 * @param accelYaw
 */
void DataKeeper::setAccelYaw(float accelYaw){
	this->accelYaw = accelYaw;
}

/**
 *
 * @param magX
 */
void DataKeeper::setMagX(float magX){
	this->magX = magX;
}

/**
 *
 * @param magY
 */
void DataKeeper::setMagY(float magY){
	this->magY = magY;
}

/**
 *
 * @param magZ
 */
void DataKeeper::setMagZ(float magZ){
	this->magZ = magZ;
}

/**
 *
 * @param angX
 */
void DataKeeper::setAngX(float angX){
	this->angX = angX;
}

/**
 *
 * @param angY
 */
void DataKeeper::setAngY(float angY){
	this->angY = angY;
}

/**
 *
 * @param angZ
 */
void DataKeeper::setAngZ(float angZ){
	this->angZ = angZ;
}

/**
 *
 * @param heading
 */
void DataKeeper::setHeading(float heading){
	this->heading = heading;
}

/**
 *
 * @param headingDeg
 */
void DataKeeper::setHeadingDeg(float headingDeg){
	this->headingDeg = headingDeg;
}

/**
 *
 * @param path
 */
void DataKeeper::setPath(std::string path){
	this->path = path;
}

/**
 *
 * @param currentX
 */
void DataKeeper::setCurrentX(int currentX){
	this->currentX = currentX;
}

/**
 *
 * @param currentY
 */
void DataKeeper::setCurrentY(int currentY){
	this->currentY = currentY;
}

/**
 *
 * @param destX
 */
void DataKeeper::setDestX(int destX){
	this->destX = destX;
}

/**
 *
 * @param destY
 */
void DataKeeper::setDestY(int destY){
	this->destY = destY;
}

/**
 *
 * @param facing
 */
void DataKeeper::setFacing(int facing){
	this->facing = facing;
}

/**
 *
 */
DataKeeper::~DataKeeper() {

}

