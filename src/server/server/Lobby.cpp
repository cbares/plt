#include "Lobby.h"

#include <boost/asio.hpp>
#include <iostream>
#include <list>

#include "Game.h"

using namespace server;
using namespace std;
using namespace boost;

void Lobby::addClient(std::shared_ptr<server::Client> client) {
	this->clientsMutex.lock();
	this->clients.push_back(client);
	this->clients.unique();
	if(clients.size()==2){
		(new Game(clients))->start();
	}

	this->clientsMutex.unlock();
}

void Lobby::removeClient(std::shared_ptr<server::Client> client) {
	this->clientsMutex.lock();
	this->clients.remove(client);
	this->clientsMutex.unlock();
}

std::list<std::shared_ptr<Client>> Lobby::getClients() {
	return this->clients;
}

