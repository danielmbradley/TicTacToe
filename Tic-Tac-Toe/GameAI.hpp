//
//  GameAI.hpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 12/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#ifndef GameAI_hpp
#define GameAI_hpp

#include <stdio.h>
#include "printBoard.hpp"

class GameAISimple{
public:
    void makeMove();
private:
};

class GameAIMedium{
public:
    void makeMove();
    void moveRandomisation();
    bool winningMovePossible();
    bool goingToLose();
private:
};

class GameAIHard{
public:
    void makeMove();
    void moveRandomisation();
    bool winningMovePossible();
    bool goingToLose();
    bool influentialMoves(int possiblePreferences[], int);
private:
};

#endif /* GameAI_hpp */
