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
		boost::asio::streambuf request;
		boost::asio::read_until(*socket.get(), request, '\n');         // Emulate request processing.         
		std::istream is(&request);
		std::string str;
		is >> str;
		std::cout << str;
        /*      
		std::this_thread::sleep_for(std::chrono::milliseconds(500));         // Sending response.         
		std::string response = "Response\n";         
		boost::asio::write(*socket.get(), boost::asio::buffer(response));      
        */
	}      
	catch (system::system_error &e) {         
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
	}      // Clean-up.      
	delete this; 
}
