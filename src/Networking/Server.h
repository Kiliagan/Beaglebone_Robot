/*
 * Server.h
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "../Managers/DataKeeper.h"

class Server {
private:
	int port;
public:
	Server(int port);
	virtual void startServer();
	virtual ~Server();
};

#endif /* SERVER_H_ */
