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
#include "MotorManager.h"

using namespace std;



int main() {
	MotorManager motorManager = MotorManager();
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();

	cout << "Robot Booting..." << endl;
	cout << "HELP ME" << endl;


	for(int i=0;i<100;i++){
	sensorManager.readSensors(dataKeeper);
	//motorManager.driveMotors(dataKeeper);

/*	magSense.selfTest();
	cout << "Test" << endl;
	cout << "Mag X Value " << magSense.getMagX() << endl;
	cout << "Mag Y Value " << magSense.getMagY() << endl;
	cout << "Mag Z Value " << magSense.getMagZ() << endl;
	cout << "Read Data" << endl;

	for(int i=0; i<100;i++){
		for(int j=0; j<2; j++){
				magSense.readSensorState();
		}
		cout << "Mag X Value " << magSense.getMagX() << endl;
		cout << "Mag Y Value " << magSense.getMagY() << endl;
		cout << "Mag Z Value " << magSense.getMagZ() << endl;
		usleep(500000);
	}
*/
	cout << "X Accel Value " << dataKeeper.getGyroAccelX() << endl;
	cout << "Y Accel Value " << dataKeeper.getGyroAccelY() << endl;
	cout << "Z Accel Value " << dataKeeper.getGyroAccelZ() << endl;
	cout << "Roll Value " << dataKeeper.getGyroRoll() << endl;
	cout << "Pitch Value " << dataKeeper.getGyroPitch() << endl;

	usleep(5000000);
	}

	return 0;
}
