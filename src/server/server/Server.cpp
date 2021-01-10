#include "Server.h"

#include <boost/asio.hpp>
#include <iostream>

using namespace server;
using namespace std;
using namespace boost;

const int port = 8080;
const int backlog_size =  2;

void Server::start(){
    asio::ip::tcp::endpoint endpoint(asio::ip::address_v4::any(),port);
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor(io_context,endpoint.protocol());
    acceptor.bind(endpoint);
    acceptor.listen(backlog_size);
    asio::ip::tcp::socket active_socket(io_context);
    acceptor.accept(active_socket);
}