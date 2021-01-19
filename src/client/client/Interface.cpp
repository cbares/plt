#include "Interface.h"

#include <iostream>
#include <stdio.h>
#include <functional>
#include <memory>

using namespace client;
using namespace std;

Interface::Interface (std::shared_ptr<state::State> state, std::string playerName)  {
    this->playerName = playerName;
    this->stateRenderer = make_shared<render::StateRenderer>();
    state->registerObserver(stateRenderer);

}

void Interface::start (){
    this->thread = std::make_shared<std::thread>(&Interface::run,this);
}


void Interface::run (){
    while (stateRenderer->isOpen())
    {
        // Process events
        sf::Event event;

        while (stateRenderer->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                stateRenderer->close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed){
		        vector<shared_ptr<render::RiverRenderer>> _riverRenderers = stateRenderer->riverRenderers;

                // Loop on rivers:
                for(uint riverpos = 0; riverpos < _riverRenderers.size(); riverpos++){
                    shared_ptr<render::RiverRenderer> _riverRenderer = _riverRenderers[riverpos];
                    // _riverRenderer is current river.
                    
                    // Loop on cards (in current river):
                    for(uint cardpos = 0; cardpos < _riverRenderer->cards.size(); cardpos++){
                        sf::Sprite _sprite = _riverRenderer->cards[cardpos]->sprite;
                        sf::Vector2f _cardPosition = _riverRenderer->cards[cardpos]->cardPosition;
                        sf::Vector2f _cardDimension = _riverRenderer->cards[cardpos]->cardDimension;

                        bool x_condition = event.mouseButton.x >= _cardPosition.x && event.mouseButton.x <= _cardPosition.x+_cardDimension.x;
                        bool y_condition = event.mouseButton.y >= _cardPosition.y && event.mouseButton.y <= _cardPosition.y+_cardDimension.y;

                        if (x_condition && y_condition){
                            // Clicked on that card !
                            cout << "click to be handled" << endl;
                            
                            std::shared_ptr<engine::PickCommand> command = std::make_shared<engine::PickCommand>(riverpos, cardpos, this->playerName);
                            
                            this->commandMutex.lock();
                            this->commandBuffer = command;
                            this->commandMutex.unlock();
                            

                        }
                    }
                }                
            }
        }
    }
}