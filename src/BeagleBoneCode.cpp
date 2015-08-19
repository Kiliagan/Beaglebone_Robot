//============================================================================
// Name        : BeagleBoneCode.cpp
// Author      : Kilian
// Version     :
// Copyright   :
// Description : Code to control BeagleBone Robot
//============================================================================

#include <iostream>
#include <unistd.h>
#include <math.h>

#include "DataKeeper.h"
#include "CentralHub.h"
#include "RoamingBot.h"

using namespace std;

int main(int argc, char *argv[]) {

//	int i = 0;
	cout << "Robot Booting... " << endl;

	DataKeeper dataKeeper = DataKeeper();

	string type = argv[1];

	int wheels = atoi(argv[2]);

	dataKeeper.setCurrentX(atoi(argv[3]));
	dataKeeper.setCurrentY(atoi(argv[4]));
	dataKeeper.setDestX(atoi(argv[5]));
	dataKeeper.setDestY(atoi(argv[6]));

	if(type=="client"){
		RoamingBot robot = RoamingBot();
		robot.start(dataKeeper, wheels);
	}
	else if(type=="server"){
		CentralHub robot = CentralHub();
		robot.start(dataKeeper);
	}
	else{
		cout << "Incorrect value please enter either: client or server" << endl;
	}

	cout << "Robot Shutting Down... " << endl;



//	pathPlanner.main(dataKeeper, 0);
//	pathPlanner.displayMap();
//	cout << "Heres the Path: " << pathPlanner.pathFind(0,0,57,43) << endl;
//	pathPlanner.displayMap();

	return 0;
}
