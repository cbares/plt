#include "ConnectionService.h"

#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <thread>

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
		std::string username;
		stream >> username;
		std::cout << username << endl;
		lobby->clients.push_back(std::make_shared<Client>(username,socket));
	}      
	catch (system::system_error &e) {         
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
	}      // Clean-up.      
	delete this; 
}
