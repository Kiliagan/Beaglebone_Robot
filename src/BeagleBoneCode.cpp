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

	MotorManager motorManager = MotorManager(2);
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();

	int i = 0;
	cout << "Robot Booting... " << endl;

//	while(i<100){
//
//		//motorManager.forward();
//		sensorManager.readSensors(dataKeeper);
//		cout << dataKeeper.getHeadingDeg() << endl;
//
//		usleep(500000);
//
//		i++;
//	}

	while(i<1){

		sensorManager.readSensors(dataKeeper);
	//	turn("l");
	//	motorManager.left();
		float curAngle = dataKeeper.getHeadingDeg();
		float finAngle;

		cout << "At Stop 1" << endl;

		finAngle = curAngle + 90;

		if(finAngle > 360){ finAngle -= 360;}
		else if(finAngle < 0){ finAngle += 360;}

		cout << "At Stop 2" << endl;

		//motorBase.startPWM();

		while(curAngle < (finAngle - 2) || curAngle > (finAngle + 2)){
			cout << "At Stop 3: loop" << endl;

			motorManager.left();
			sensorManager.readSensors(dataKeeper);
			curAngle = dataKeeper.getHeadingDeg();
			cout << finAngle << endl;
			cout << curAngle << endl;
			usleep(500000);
		}

		cout << "At Stop 4" << endl;

		i++;
	}
	return 0;
}
