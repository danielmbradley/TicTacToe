//
//  gamePlay.hpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 10/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#ifndef gamePlay_hpp
#define gamePlay_hpp

#include <stdio.h>
#include "printBoard.hpp"

extern Board playboard;

void levelOne();

void levelTwo();

void levelThree();

void levelFour();

void runGame();

char changePlayer(char);

void movement(char);

#endif /* gamePlay_hpp */
