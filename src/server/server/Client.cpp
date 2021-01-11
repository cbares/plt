#include "Acceptor.h"

#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace server;
using namespace std;
using namespace boost;

Client::Client(std::string username, std::shared_ptr<boost::asio::ip::tcp::socket> socket){
    this->username =username;
    this->socket =socket;
}