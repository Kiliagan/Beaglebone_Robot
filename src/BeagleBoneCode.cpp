//============================================================================
// Name        : BeagleBoneCode.cpp
// Author      : Kilian
// Version     :
// Copyright   :
// Description : Code to control BeagleBone Robot
//============================================================================

#include <iostream>
#include <unistd.h>
#include <boost/version.hpp>

#include "SensorManager.h"
#include "DataKeeper.h"
//#include "MotorManager.h"

using namespace std;



int main() {
//	MotorManager motorManager = MotorManager();
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();

	cout << "Robot Booting..." << endl;

	int loop = 20;

	for(int i=0;i<loop;i++){
	sensorManager.readSensors(dataKeeper);
	//motorManager.driveMotors(dataKeeper);

	cout << "Heading Degrees: " << dataKeeper.getHeadingDeg() << endl;

	usleep(500000);
	}

	return 0;
}
