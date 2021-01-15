#include "ConnectionService.h"

#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include <json/json.h>

#include "network/UserNameMessage.h"
#include "network/AckMessage.h"

using namespace server;
using namespace std;
using namespace boost;

void ConnectionService::startHandlingClient (std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::shared_ptr<Lobby> lobby){
    std::thread th(([this, socket,lobby](){handleClient(socket,lobby);}));      
	th.detach(); 
}
void ConnectionService::handleClient (std::shared_ptr<boost::asio::ip::tcp::socket> socket, std::shared_ptr<Lobby> lobby){
	try{
		asio::streambuf buf;
		asio::read_until(*socket, buf, '\n');
		std::istream stream(&buf);
		Json::Value response;
		Json::Reader reader;
		reader.parse(stream,response,false);
		std::cout << "user \"" << response["userName"].asString() << "\" connected"<< endl;
		lobby->addClient(std::make_shared<Client>(response["userName"].asString(),socket));
	}
	catch (system::system_error &e) {         
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
	}
	delete this; 
}
