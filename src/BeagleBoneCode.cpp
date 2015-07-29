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

static int NORTH = 0;
static int WEST = 90;
static int SOUTH = 0;
static int NORTH = 0;

int main() {

	MotorManager motorManager = MotorManager(2);
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();
	AStar pathPlanner = AStar();

//	int i = 0;
	cout << "Robot Booting... " << endl;

	pathPlanner.main(dataKeeper, 0);
	pathPlanner.displayMap();
	cout << "Heres the Path: " << pathPlanner.pathFind(0,0,57,43) << endl;
	pathPlanner.displayMap();

	return 0;
}
