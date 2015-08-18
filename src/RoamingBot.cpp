/*
 * RoamingBot.cpp
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#include "RoamingBot.h"

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

	pathPlanner.main(dataKeeper, 0);
	client.startClient(dataKeeper);
}
