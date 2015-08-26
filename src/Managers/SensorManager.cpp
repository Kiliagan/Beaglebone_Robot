/*
 * SensorManager.cpp
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#include "SensorManager.h"

IR2Y0A21 irDistance = IR2Y0A21();
ADXL345 gyroSensor = ADXL345(1,0x53);
//MPU6050 accelSensor = MPU6050(1,0x68);
GY273 magSensor = GY273(1,0x1E);

SensorManager::SensorManager() {

}

/**
 * Reads in the data from all sensors on the robot
 * @param dataKeeper
 */
void SensorManager::readSensors(DataKeeper &dataKeeper){
	//num = num + 1;

	dataKeeper.setIRDistance(irDistance.getDistance());
	dataKeeper.setIRRaw(irDistance.getDistanceRAW());

/*	accelSensor.readSensorState();
	dataKeeper.setAccelAccelX(accelSensor.getAccelerationX());
	dataKeeper.setAccelAccelY(accelSensor.getAccelerationY());
	dataKeeper.setAccelAccelZ(accelSensor.getAccelerationZ());
	dataKeeper.setAccelGyroX(accelSensor.getGyroX());
	dataKeeper.setAccelGyroY(accelSensor.getGyroY());
	dataKeeper.setAccelGyroZ(accelSensor.getGyroZ());
	dataKeeper.setAccelPitch(accelSensor.getPitch());
	dataKeeper.setAccelRoll(accelSensor.getRoll());
	dataKeeper.setAccelYaw(accelSensor.getYaw());
*/
	gyroSensor.readSensorState();
	dataKeeper.setGyroAccelX(gyroSensor.getAccelerationX());
	dataKeeper.setGyroAccelY(gyroSensor.getAccelerationY());
	dataKeeper.setGyroAccelZ(gyroSensor.getAccelerationZ());
	dataKeeper.setGyroRoll(gyroSensor.getRoll());
	dataKeeper.setGyroPitch(gyroSensor.getPitch());

	for(int k = 0; k < 2; k++){
		magSensor.readSensorState();
	}
	dataKeeper.setMagX(magSensor.getMagX());
	dataKeeper.setMagY(magSensor.getMagY());
	dataKeeper.setMagZ(magSensor.getMagZ());
	dataKeeper.setHeading(magSensor.getHeading());
	dataKeeper.setHeadingDeg(magSensor.getHeadingDeg());
}

SensorManager::~SensorManager() {
	// TODO Auto-generated destructor stub
}

