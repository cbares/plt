#include "NetworkClient.h"

#include <iostream>
#include <boost/asio.hpp>

#include "network/UserNameMessage.h"

using namespace client;
using namespace std;
using namespace boost;

const int port = 8080;
const std::string ip_address = "127.0.0.1";

void NetworkClient::start(){
    asio::ip::tcp::endpoint endpoint(asio::ip::address::from_string(ip_address),port);
    asio::io_context io_context;

    asio::ip::tcp::socket socket(io_context,endpoint.protocol());

    socket.connect(endpoint);
    std::string userName;
    std::cout << "username :" << endl;
    cin >> userName;
    std::shared_ptr<network::UserNameMessage> userNameMessage = make_shared<network::UserNameMessage>(userName);
    socket.send(asio::buffer(network::Message::format(userNameMessage->serialize())));
}