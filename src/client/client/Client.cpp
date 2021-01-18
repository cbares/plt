#include "Client.h"

#include <iostream>
#include <boost/asio.hpp>

#include "network/UserNameMessage.h"
#include "network/StateMessage.h"

#include "network/AckMessage.h"
#include "network/Message.h"

using namespace client;
using namespace std;
using namespace boost;
using namespace network;

const int port = 8080;
const std::string ip_address = "127.0.0.1";

Json::Value receive(std::shared_ptr<asio::ip::tcp::socket> socket){
	Json::Reader reader;
    asio::streambuf buf;
    asio::read_until(*socket, buf, '\n');
    std::istream stream(&buf);
	Json::Value response;
	reader.parse(stream,response,false);
    return response;
}

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

	Json::Value response = receive(socket);
    std::shared_ptr<AckMessage> ackMessage = std::dynamic_pointer_cast<AckMessage>(Message::unserialize(response));
    if(ackMessage){
        cout << "connected" << endl;
        this->socket = socket;
        this->state = make_shared<state::State>(-1,"res/cardsData/");
        
	    response = receive(socket);
        std::shared_ptr<StateMessage> stateMessage = std::dynamic_pointer_cast<StateMessage>(Message::unserialize(response));
        if(stateMessage){

            this->state->unserialize(stateMessage->state->serialize());
            //Create the interface
            this->run();
        }
        else{
            cout << "error " << endl;
        }
    }
	else{
        cout << "Error when receiving ack for connection" << endl;
    }
    
}

void Client::run(){
    while(1){
        Json::Value response = receive(socket);
        switch((MessageID)response["id"].asInt()){
            case MessageID::STATE:{
                std::shared_ptr<StateMessage> stateMessage = std::dynamic_pointer_cast<StateMessage>(Message::unserialize(response));
                this->state->unserialize(stateMessage->state->serialize());
                break;
            }  
            case MessageID::REQUEST_COMMAND:{
                //Recupere la commande et l'envoie
                break;
            }
            default :  
                cout << "expected StateMessage or RequestMessage got something else" << endl;
        }
    }
}
