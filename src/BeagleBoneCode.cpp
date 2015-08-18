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

	if(*argv[1]=='client'){
		cout << "Yay it worked" << endl;
	}
	else if(*argv[1]=='server'){
		cout << "This also worked" << endl;
	}
	else{
		cout << "Incorrect value please enter either: client or server" << endl;
	}

	cout << "Robot Shutting Down... " << endl;

//	server.startServer(dataKeeper);

/*	pathPlanner.main(dataKeeper, 0);
	client.startClient(dataKeeper);*/


//	pathPlanner.main(dataKeeper, 0);
//	pathPlanner.displayMap();
//	cout << "Heres the Path: " << pathPlanner.pathFind(0,0,57,43) << endl;
//	pathPlanner.displayMap();

	return 0;
}
