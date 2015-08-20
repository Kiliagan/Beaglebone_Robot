/*
 * RoamingBot.cpp
 *
 *  Created on: 18 Aug 2015
 *      Author: root
 */

#include "RoamingBot.h"
#include <sstream>
#include <unistd.h>

using namespace std;

/**
 *
 */
RoamingBot::RoamingBot() {
	UP = 0;
	RIGHT = 90;
	DOWN = 180;
	LEFT = 270;

}

/**
 *
 */
RoamingBot::~RoamingBot() {
}

/**
 *
 * @param dataKeeper
 * @param sensorManager
 * @param motorManager
 * @param dir
 */
void RoamingBot::direction(DataKeeper &dataKeeper, SensorManager &sensorManager, MotorManager &motorManager, int dir){

	sensorManager.readSensors(dataKeeper);
	float curAngle = dataKeeper.getHeadingDeg();
	float finAngle, lowFinAngle, highFinAngle;
	int tolerance = 3;

	switch(dir){
	case 0: finAngle = DOWN;break;
	case 1: finAngle = LEFT;break;
	case 2: finAngle = UP;break;
	case 3: finAngle = RIGHT;break;
	}

	lowFinAngle = finAngle - tolerance;
	highFinAngle = finAngle + tolerance;

	if(lowFinAngle > 360){ lowFinAngle -= 360;}
	else if(lowFinAngle < 0){ lowFinAngle += 360;}

	if(highFinAngle > 360){ highFinAngle -= 360;}
	else if(highFinAngle < 0){ highFinAngle += 360;}

	if(lowFinAngle > highFinAngle){
		while(curAngle < lowFinAngle && curAngle > highFinAngle){

			motorManager.left();
			sensorManager.readSensors(dataKeeper);
			curAngle = dataKeeper.getHeadingDeg();
			usleep(500000);
		}
	}
	else{
		while(curAngle < (lowFinAngle) || curAngle > (highFinAngle)){

			motorManager.left();
			sensorManager.readSensors(dataKeeper);
			curAngle = dataKeeper.getHeadingDeg();
			usleep(500000);
		}
	}
}

/**
 *
 * @param dataKeeper
 * @param wheels
 */
void RoamingBot::start(DataKeeper &dataKeeper, int wheels){
	MotorManager motorManager = MotorManager(wheels);
	SensorManager sensorManager = SensorManager();
	AStar pathPlanner = AStar();
	Client client = Client(dataKeeper.getIP(), 5050);

	client.startClient(dataKeeper, 1);
	std::string path = dataKeeper.getPath();
	pathPlanner.newPath(dataKeeper);
	pathPlanner.setStartDest(dataKeeper);
	pathPlanner.displayMap();

	int i = 0;

	while(i<path.length()){
		int x;

		istringstream(path.substr(i,1)) >> x;
		dataKeeper.setFacing(x);
	//	direction(dataKeeper, sensorManager, motorManager, x);

		motorManager.forward();
		i++;
		sensorManager.readSensors(dataKeeper);
		if(dataKeeper.getIRDistance() < 100){
			client.startClient(dataKeeper, 2);
			client.startClient(dataKeeper, 1);
			path = dataKeeper.getPath();
			i = 0;
		}

	}
}
