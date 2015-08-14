/*
 * Client.h
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "DataKeeper.h"

class Client {
private:
	std::string ip;
	int port;
public:
	Client(std::string ip, int port);
	virtual void startClient(DataKeeper &dataKeeper);
	virtual ~Client();
};

#endif /* CLIENT_H_ */
