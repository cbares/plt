#include "Client.h"

#include <iostream>
#include <boost/asio.hpp>

#include "network/UserNameMessage.h"
#include "network/AckMessage.h"
#include "network/Message.h"

using namespace client;
using namespace std;
using namespace boost;
using namespace network;

const int port = 8080;
const std::string ip_address = "127.0.0.1";

void Client::start(){
    asio::ip::tcp::endpoint endpoint(asio::ip::address::from_string(ip_address),port);
    asio::io_context io_context;

    std::shared_ptr<asio::ip::tcp::socket> socket = make_shared<asio::ip::tcp::socket>(io_context,endpoint.protocol());

    socket->connect(endpoint);
    std::string userName;
    std::cout << "username :" << endl;
    cin >> userName;
    std::shared_ptr<network::UserNameMessage> userNameMessage = make_shared<network::UserNameMessage>(userName);
    socket->send(asio::buffer(network::Message::format(userNameMessage->serialize())));

	asio::streambuf buf;
    asio::read_until(*socket, buf, '\n');
    std::istream stream(&buf);
	Json::Value response;
	Json::Reader reader;
	reader.parse(stream,response,false);
    std::shared_ptr<AckMessage> ackMessage = std::dynamic_pointer_cast<AckMessage>(Message::unserialize(response));
    if(ackMessage){
        cout << "connected" << endl;
    }
	else{
        cout << "error" << endl;
    }
}