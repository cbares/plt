#include <iostream>
#include <state.h>
#include <server.h>
#include <cstring>
#include <random>

using namespace std;
using namespace state;
using namespace server;

int main(int argc,char* argv[]){   
    srand(time(NULL));
    Server server;
    server.start();
    std::string input;
    while(1){
        std::getline(std::cin,input);
            if(input == "stop"){
            server.stop();
            break;
        }
    }
    return 0;
}
