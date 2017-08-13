#include <iostream>

#include "Game.h"
#include "TickTackToe.h"
#include "PayoffManager.h"

#include<string>

#include<cstdlib>

#include<memory>

struct GameMove {
  std::string informationset;
  int action;

  PayoffData()
  {
    trials = 0;
    payoff = 0;
  }
} ;

int main()
{
    auto pm = std::make_unique<PayoffManager>();

    for(int i = 0; i < 10; i++){
        auto game = std::make_unique<TickTackToe>();
        int currentPlayer = 0;

        while(game->getResult() == game->NOT_ENDED){

            //Get all the data
            std::string info = game->getInformationSet(currentPlayer);
            auto opts = game->getPossibleActions(currentPlayer);
            int action = std::rand() % opts.size();

            //Output it
            std::cout << "Player: " << currentPlayer << " Info: " << info
              << " Ations: " << opts.size()
              << " Choosing: " << action
              << " (" << opts[action] << ")" << std::endl;

            //Do the action
            game->doAction(opts[action], currentPlayer);

            //Change player
            if(currentPlayer == 0)
              currentPlayer = 1;
            else
              currentPlayer = 0;
        }
        std::cout << game->getResult() << " won" << std::endl;
    }

    //std::cout << "It works: " << g->getResult() << std::endl;
    return 0;
}

//Compile with: g++ *.cpp -o main.exe
