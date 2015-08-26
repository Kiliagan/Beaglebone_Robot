/*
 * DataKeeper.cpp
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#include "DataKeeper.h"

/**
 * Sets up all sensor data with an starting value of 0
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
	ip = "No IP";
	currentX = 0;
	currentY = 0;
	destX = 0;
	destY = 0;
	facing = 0;
}

/**
 * Reads in mm distance from sensor
 * @param irDistance
 */
void DataKeeper::setIRDistance(float irDistance){
	this->irDistance = irDistance;
}

/**
 * Reads in raw data from sensor
 * @param irRaw
 */
void DataKeeper::setIRRaw(float irRaw){
	this->irRaw = irRaw;
}

/**
 * reads in X value from the ADXL345
 * @param gyroAccelX
 */
void DataKeeper::setGyroAccelX(float gyroAccelX){
	this->gyroAccelX = gyroAccelX;
}

/**
 * reads in Y value from the ADXL345
 * @param gyroAccelY
 */
void DataKeeper::setGyroAccelY(float gyroAccelY){
	this->gyroAccelY = gyroAccelY;
}

/**
 * reads in Z value from the ADXL345
 * @param gyroAccelZ
 */
void DataKeeper::setGyroAccelZ(float gyroAccelZ){
	this->gyroAccelZ = gyroAccelZ;
}

/**
 * reads in Roll value from the ADXL345
 * @param gyroRoll
 */
void DataKeeper::setGyroRoll(float gyroRoll){
	this->gyroRoll = gyroRoll;
}

/**
 * reads in Pitch value from the ADXL345
 * @param gyroPitch
 */
void DataKeeper::setGyroPitch(float gyroPitch){
	this->gyroPitch = gyroPitch;
}

/**
 * reads in X value from the MPU6050
 * @param accelAccelX
 */
void DataKeeper::setAccelAccelX(float accelAccelX){
	this->accelAccelX = accelAccelX;
}

/**
 * reads in Y value from the MPU6050
 * @param accelAccelY
 */
void DataKeeper::setAccelAccelY(float accelAccelY){
	this->accelAccelY = accelAccelY;
}

/**
 * reads in Z value from the MPU6050
 * @param accelAccelZ
 */
void DataKeeper::setAccelAccelZ(float accelAccelZ){
	this->accelAccelZ = accelAccelZ;
}

/**
 * reads in X value from the MPU6050
 * @param accelGyroX
 */
void DataKeeper::setAccelGyroX(float accelGyroX){
	this->accelGyroX = accelGyroX;
}

/**
 * reads in Y value from the MPU6050
 * @param accelGyroY
 */
void DataKeeper::setAccelGyroY(float accelGyroY){
	this->accelGyroY = accelGyroY;
}

/**
 * reads in Z value from the MPU6050
 * @param accelGyroZ
 */
void DataKeeper::setAccelGyroZ(float accelGyroZ){
	this->accelGyroZ = accelGyroZ;
}

/**
 * reads in Pitch value from the MPU6050
 * @param accelPitch
 */
void DataKeeper::setAccelPitch(float accelPitch){
	this->accelPitch = accelPitch;
}

/**
 * reads in Roll value from the MPU6050
 * @param accelRoll
 */
void DataKeeper::setAccelRoll(float accelRoll){
	this->accelRoll = accelRoll;
}

/**
 * reads in Yaw value from the MPU6050
 * @param accelYaw
 */
void DataKeeper::setAccelYaw(float accelYaw){
	this->accelYaw = accelYaw;
}

/**
 * reads in X value from the HMC5883L
 * @param magX
 */
void DataKeeper::setMagX(float magX){
	this->magX = magX;
}

/**
 * reads in Y value from the HMC5883L
 * @param magY
 */
void DataKeeper::setMagY(float magY){
	this->magY = magY;
}

/**
 * reads in Z value from the HMC5883L
 * @param magZ
 */
void DataKeeper::setMagZ(float magZ){
	this->magZ = magZ;
}

/**
 *  reads in X Ang value from the HMC5883L
 * @param angX
 */
void DataKeeper::setAngX(float angX){
	this->angX = angX;
}

/**
 * reads in Y Ang value from the HMC5883L
 * @param angY
 */
void DataKeeper::setAngY(float angY){
	this->angY = angY;
}

/**
 * reads in Z Ang value from the HMC5883L
 * @param angZ
 */
void DataKeeper::setAngZ(float angZ){
	this->angZ = angZ;
}

/**
 * reads in Heading value from the HMC5883L
 * @param heading
 */
void DataKeeper::setHeading(float heading){
	this->heading = heading;
}

/**
 * reads in Heading value in Degrees from the HMC5883L
 * @param headingDeg
 */
void DataKeeper::setHeadingDeg(float headingDeg){
	this->headingDeg = headingDeg;
}

/**
 * reads in the Path from the A* method
 * @param path
 */
void DataKeeper::setPath(std::string path){
	this->path = path;
}

/**
 * reads in IP address
 * @param ip
 */
void DataKeeper::setIP(std::string ip){
	this->ip = ip;
}

/**
 * Reads in current X coordinate
 * @param currentX
 */
void DataKeeper::setCurrentX(int currentX){
	this->currentX = currentX;
}

/**
 * Reads in current Y coordinate
 * @param currentY
 */
void DataKeeper::setCurrentY(int currentY){
	this->currentY = currentY;
}

/**
 * Reads in destination X coordinate
 * @param destX
 */
void DataKeeper::setDestX(int destX){
	this->destX = destX;
}

/**
 * Reads in destination Y coordinate
 * @param destY
 */
void DataKeeper::setDestY(int destY){
	this->destY = destY;
}

/**
 * Reads in the direction the robot is facing
 * @param facing
 */
void DataKeeper::setFacing(int facing){
	this->facing = facing;
}


DataKeeper::~DataKeeper() {

}

