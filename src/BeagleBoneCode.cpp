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
	cout << "HELP ME" << endl;
	cout << "Rebooted code :D" << endl;

	float avgX = 0, avgY =0, avgZ =0;
	int loop = 100;

	for(int i=0;i<loop;i++){
	sensorManager.readSensors(dataKeeper);
	//motorManager.driveMotors(dataKeeper);
	//cout << "Mag X Value " << dataKeeper.getMagX() << endl;
	//cout << "Mag Y Value " << dataKeeper.getMagY() << endl;
	//cout << "Mag Z Value " << dataKeeper.getMagZ() << endl;

	avgX+=dataKeeper.getMagX();
	avgY+=dataKeeper.getMagY();
	avgZ+=dataKeeper.getMagZ();

	cout << i << endl;

/*
	cout << "X Accel Value " << dataKeeper.getAccelGyroX() << endl;
	cout << "Y Accel Value " << dataKeeper.getAccelGyroY() << endl;
	cout << "Z Accel Value " << dataKeeper.getAccelGyroZ() << endl;
	cout << "Roll Value " << dataKeeper.getAccelRoll() << endl;
	cout << "Pitch Value " << dataKeeper.getAccelPitch() << endl;
	cout << "Yaw Value " << dataKeeper.getAccelYaw() << endl;
*/
	usleep(500000);
	}

	avgX/= loop;
	avgY/= loop;
	avgZ/= loop;

	cout << "X = " << avgX << ", Y = " << avgY << ", Z = " << avgZ << endl;

	return 0;
}
