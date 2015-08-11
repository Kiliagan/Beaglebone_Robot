/*
 * Client.h
 *
 *  Created on: 11 Aug 2015
 *      Author: root
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>

class Client {
private:
	std::string ip;
	int port;
public:
	Client(std::string ip, int port);
	virtual void startClient();
	virtual ~Client();
};

#endif /* CLIENT_H_ */
