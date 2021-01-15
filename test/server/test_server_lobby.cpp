#include <boost/test/included/unit_test.hpp>
#include <memory>
#include <iostream>

#include "../../src/server/server.h"

using namespace server;
using namespace std;

BOOST_AUTO_TEST_SUITE(server_Lobby)

BOOST_AUTO_TEST_CASE(Lobby_addAndRemoveClients){
    /*boost::asio::io_context io_context;
    shared_ptr<boost::asio::ip::tcp::socket> socket = make_shared<boost::asio::ip::tcp::socket>(io_context);
    shared_ptr<Client> player1 = make_shared<Client>(string("My name"), socket);
    shared_ptr<Client> player2 = make_shared<Client>(string("Your name"), socket);
    shared_ptr<Lobby> lobby = make_shared<Lobby>();

    BOOST_TEST(lobby->getClients().size() == 0);

    lobby->addClient(player1);

    BOOST_TEST(lobby->getClients().size() == 1);

    lobby->removeClient(player2);

    BOOST_TEST(lobby->getClients().size() == 1);

    lobby->removeClient(player1);

    BOOST_TEST(lobby->getClients().size() == 0);

    lobby->addClient(player1);
    lobby->addClient(player2);

    BOOST_TEST(lobby->getClients().size() == 2);*/
}

BOOST_AUTO_TEST_SUITE_END();
