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
#include "AStar.h"

using namespace std;

int main() {

	MotorManager motorManager = MotorManager(2);
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();
	AStar pathPlanner = AStar();

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

	pathPlanner.main();
//	while(i<1){
//
//		sensorManager.readSensors(dataKeeper);
//	//	turn("l");
//	//	motorManager.left();
//		float curAngle = dataKeeper.getHeadingDeg();
//		float finAngle, lowFinAngle, highFinAngle;
//		int tolerance = 3;
//
//		cout << "At Stop 1" << endl;
//
//		finAngle = curAngle + 90;
//
//		lowFinAngle = finAngle - tolerance;
//		highFinAngle = finAngle + tolerance;
//
//		if(lowFinAngle > 360){ lowFinAngle -= 360;}
//		else if(lowFinAngle < 0){ lowFinAngle += 360;}
//
//		if(highFinAngle > 360){ highFinAngle -= 360;}
//		else if(highFinAngle < 0){ highFinAngle += 360;}
//
//		cout << "At Stop 2" << endl;
//
//		if(lowFinAngle > highFinAngle){
//			while(curAngle < lowFinAngle && curAngle > highFinAngle){
//				cout << "At Stop 3: loop" << endl;
//
//				motorManager.left();
//				sensorManager.readSensors(dataKeeper);
//				curAngle = dataKeeper.getHeadingDeg();
//				cout << lowFinAngle << endl;
//				cout << highFinAngle << endl;
//				cout << curAngle << endl;
//				usleep(500000);
//			}
//		}
//		else{
//			while(curAngle < (lowFinAngle) || curAngle > (highFinAngle)){
//				cout << "At Stop 3: loop" << endl;
//
//				motorManager.left();
//				sensorManager.readSensors(dataKeeper);
//				curAngle = dataKeeper.getHeadingDeg();
//				cout << lowFinAngle << endl;
//				cout << highFinAngle << endl;
//				cout << curAngle << endl;
//				usleep(500000);
//			}
//		}
//		cout << "At Stop 4" << endl;
//
//		i++;
//	}
	return 0;
}
