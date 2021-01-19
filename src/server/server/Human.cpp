#include "Human.h"

#include <boost/asio.hpp>
#include <iostream>
#include <list>

#include "Game.h"
#include "network.h"

using namespace server;
using namespace std;
using namespace boost;
using namespace engine;
using namespace network;

void Human::updateState (std::shared_ptr<state::State> state){
    std::shared_ptr<StateMessage> stateMessage = std::make_shared<StateMessage>(state);
	client->socket->send(asio::buffer(Message::format(stateMessage->serialize())));

    Json::Reader reader;
    asio::streambuf buf;
    asio::read_until(*(client->socket), buf, '\n');
    std::istream stream(&buf);
	Json::Value response;
	reader.parse(stream,response,false);
    std::shared_ptr<AckMessage> ackMessage = std::dynamic_pointer_cast<AckMessage>(Message::unserialize(response));
    if(!ackMessage){
        cout << "error receiving ack from updateState" << endl;
    }
    
}

std::shared_ptr<engine::Command> Human::getCommand (){
    cout << "trying to get command " <<endl;
    std::shared_ptr<RequestCommandMessage> requestCommandMessage = std::make_shared<RequestCommandMessage>();
	client->socket->send(asio::buffer(Message::format(requestCommandMessage->serialize())));

    cout << "sent request " <<endl;

    Json::Reader reader;
    asio::streambuf buf;
    asio::read_until(*(client->socket), buf, '\n');
    std::istream stream(&buf);
	Json::Value response;
	reader.parse(stream,response,false);
    std::shared_ptr<CommandMessage> commandMessage = std::dynamic_pointer_cast<CommandMessage>(Message::unserialize(response));
    if(commandMessage){
        return commandMessage->command;
    }
    else{
        cout <<"error receiving message" << endl;
    }
    return nullptr;
}

Human::Human (std::shared_ptr<state::Player> player,std::shared_ptr<Client> client) : Actor(player){
    this->client = client;
}
