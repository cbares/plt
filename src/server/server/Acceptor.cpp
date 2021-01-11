#include "Acceptor.h"

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace server;
using namespace std;
using namespace boost;

Acceptor::Acceptor(std::shared_ptr<boost::asio::io_context> io_context, int port, std::shared_ptr<Lobby> lobby){
    this->io_context = io_context;
    this->acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(*(io_context.get()),
                            asio::ip::tcp::endpoint(asio::ip::address_v4::any(), port));
    this->lobby = lobby;
    acceptor->listen();
}

void Acceptor::accept(){
	std::shared_ptr<asio::ip::tcp::socket> socket = std::make_shared<asio::ip::tcp::socket>(asio::ip::tcp::socket(*io_context.get()));
    acceptor->accept(*socket.get());
	(new ConnectionService)->startHandlingClient(socket,lobby);
}
