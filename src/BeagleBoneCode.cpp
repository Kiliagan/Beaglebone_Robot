//============================================================================
// Name        : BeagleBoneCode.cpp
// Author      : Kilian
// Version     :
// Copyright   :
// Description : Code to control BeagleBone Robot
//============================================================================

#include <iostream>
#include <unistd.h>
//#include <boost/version.hpp>
#include <math.h>

#include "SensorManager.h"
#include "DataKeeper.h"
#include "MotorManager.h"
#include "AStar.h"
#include "Server.h"
#include "Client.h"

using namespace std;

int main() {

	MotorManager motorManager = MotorManager(2);
	SensorManager sensorManager = SensorManager();
	DataKeeper dataKeeper = DataKeeper();
	AStar pathPlanner = AStar();
	Server server = Server(5050);
	Client client = Client("192.168.43.41", 5050);


//	int i = 0;
	cout << "Robot Booting... " << endl;

	server.startServer(dataKeeper);

/*	pathPlanner.main(dataKeeper, 0);
	client.startClient(dataKeeper);*/


//	pathPlanner.main(dataKeeper, 0);
//	pathPlanner.displayMap();
//	cout << "Heres the Path: " << pathPlanner.pathFind(0,0,57,43) << endl;
//	pathPlanner.displayMap();

	return 0;
}
