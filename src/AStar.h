/*
 * AStar.h
 *
 *  Created on: 27 Jul 2015
 *      Author: root
 */

#ifndef ASTAR_H_
#define ASTAR_H_

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "DataKeeper.h"

class AStar {
private:
	std::string path;
	int startX, startY, endX, endY;
public:

	AStar();

	virtual void main(DataKeeper &dataKeeper);
	virtual void displayMap();
	virtual std::string pathFind( const int & xStart, const int & yStart, const int & xFinish, const int & yFinish );
	virtual void newObstacle(int xObj, int yObj);
	virtual void newPath(DataKeeper &dataKeeper);
	virtual void setStartDest(DataKeeper &dataKeeper);


	virtual ~AStar();
};

#endif /* ASTAR_H_ */
