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
#include <math.h>

#include "SensorManager.h"
#include "DataKeeper.h"
#include "MotorManager.h"

using namespace std;



int main() {
	MotorManager motorManager = MotorManager();
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();
	int i = 0;
	cout << "Robot Booting... " << endl;

	while(true){

	motorManager.driveMotors(dataKeeper, sensorManager);

	i++;

	}
	return 0;
}
