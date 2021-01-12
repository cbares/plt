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
	this->clients.push_back(client);
	this->clients.unique();
}

void Lobby::removeClient(std::shared_ptr<server::Client> client) {
	this->clients.remove(client);
}

std::set<std::string> Lobby::getClients() {
	return this->clients;
}

