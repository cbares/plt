#include "Server.h"

#include <boost/asio.hpp>
#include <iostream>

using namespace server;
using namespace std;
using namespace boost;

const int port = 8080;
const int backlog_size =  2;

Server::Server (){
    this->io_context = std::make_shared<boost::asio::io_context>();
    this->lobby = std::make_shared<Lobby>();
    this->stopped = true;
}

void Server::start(){
    stopped = false;
    this->thread = std::make_shared<std::thread>(&Server::run,this);
    thread->detach();
}

void Server::run (){
    std::shared_ptr<Acceptor> acc = std::make_shared<Acceptor>(io_context,port,lobby);
    while(!stopped.load()){
        acc->accept();
    }
}
void Server::stop (){
    stopped = true;
}
