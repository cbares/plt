#include "Human.h"

#include <boost/asio.hpp>
#include <iostream>
#include <list>

#include "Game.h"
#include "network/StateMessage.h"

using namespace server;
using namespace std;
using namespace boost;
using namespace engine;
using namespace network;

void Human::updateState (std::shared_ptr<state::State> state){
    std::shared_ptr<StateMessage> stateMessage = std::make_shared<StateMessage>(state);
	client->socket->send(asio::buffer(Message::format(stateMessage->serialize())));
}

std::shared_ptr<engine::Command> Human::getCommand (){
    cout << "trying to get command :/" <<endl;
}

Human::Human (std::shared_ptr<state::Player> player,std::shared_ptr<Client> client) : Actor(player){
    this->client = client;
}
