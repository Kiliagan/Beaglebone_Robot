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

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

	cout << "Robot Booting... " << endl;

	DataKeeper dataKeeper = DataKeeper();

	string job = argv[1];

	cout << "Hello!\nLet's see what job I've been assigned." << endl;

	if(job=="driver"){
		cout << "My job is as driver." << endl;
		int wheels = atoi(argv[2]);

		dataKeeper.setCurrentX(atoi(argv[3]));
		dataKeeper.setCurrentY(atoi(argv[4]));
		dataKeeper.setDestX(atoi(argv[5]));
		dataKeeper.setDestY(atoi(argv[6]));

		dataKeeper.setIP(argv[7]);
		RoamingBot robot = RoamingBot();
		robot.start(dataKeeper, wheels);
	}
	else if(job=="planner"){
		cout << "My job is as planner." << endl;
		CentralHub robot = CentralHub();
		robot.start();
	}
	else{
		cout << "Huh?\n" << job << ", that's not a job. The jobs are 'driver' and 'planner'" << endl;
	}

	cout << "Goodbye. Hope to see you again." << endl;

	cout << "Robot Shutting Down... " << endl;

	return 0;
}
