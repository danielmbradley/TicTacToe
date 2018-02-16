//
//  printBoard.hpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 09/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#ifndef printBoard_hpp
#define printBoard_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Board{
    public:
        char BoardValue[9];
        const int winningValues[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
        Board () {};
        Board (bool);
        void printBoard();
        void initalise();
        void clearBoard();
        bool validateMove();
        bool checkForWin(char player);
    private:
};

#endif /* printBoard_hpp */
