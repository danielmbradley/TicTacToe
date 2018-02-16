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
    void generateMove();
private:
};

class GameAIMedium{
public:
    void generateMove();
    void moveRandomisation();
    bool winningMovePossible();
    bool goingToLose();
private:
};

#endif /* GameAI_hpp */
