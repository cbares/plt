#include "Lobby.h"

#include <boost/asio.hpp>
#include <iostream>
#include <list>

using namespace server;
using namespace std;
using namespace boost;

Lobby::Lobby() {

}

void Lobby::addClient(std::shared_ptr<server::Client> client) {
	this->clientsMutex.lock();
	this->clients.push_back(client);
	this->clients.unique();
	this->clientsMutex.unlock();
}

void Lobby::removeClient(std::shared_ptr<server::Client> client) {
	this->clientsMutex.lock();
	this->clients.remove(client);
	this->clientsMutex.unlock();
}

std::set<std::string> Lobby::getClients() {
	return this->clients;
}

