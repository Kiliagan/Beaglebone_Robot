/*
 * SensorManager.h
 *
 *  Created on: 10 Jul 2015
 *      Author: kilian
 */

#ifndef SENSORMANAGER_H_
#define SENSORMANAGER_H_

#include "DataKeeper.h"
#include "../Sensors/ADXL345.h"
#include "../Sensors/GY273.h"
#include "../Sensors/IR2Y0A21.h"
#include "../Sensors/MPU6050.h"

class SensorManager {
public:
	SensorManager();
	virtual void readSensors(DataKeeper &dataKeeper);
	virtual ~SensorManager();
};

#endif /* SENSORMANAGER_H_ */
