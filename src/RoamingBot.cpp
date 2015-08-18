/*
 * RoamingBot.cpp
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#include "RoamingBot.h"

using namespace std;

RoamingBot::RoamingBot() {
	// TODO Auto-generated constructor stub

}

RoamingBot::~RoamingBot() {
	// TODO Auto-generated destructor stub
}

void RoamingBot::start(DataKeeper &dataKeeper, int wheels){
	MotorManager motorManager = MotorManager(wheels);
	SensorManager sensorManager = SensorManager();
	AStar pathPlanner = AStar();
	Client client = Client("192.168.43.41", 5050);

	client.startClient(dataKeeper);
	cout << "I'm here 1" << endl;
	cout << "My path is: " << dataKeeper.getPath() << endl;
	pathPlanner.newPath(dataKeeper);
	pathPlanner.setStartDest(dataKeeper);
	cout << "I'm here 3" << endl;
	pathPlanner.displayMap();
	cout << "I'm here 7" << endl;
}
