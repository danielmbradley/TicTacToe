//
//  printBoard.cpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 09/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#include "printBoard.hpp"
#include <string>

using namespace std;

Board::Board(bool isNewBoard){
    char BoardValue[9];
    const int winningValues[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
}

void Board::printBoard(){
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"|";
    for (int i=0; i!= 9; i++){
        cout<<BoardValue[i]<<"|";
        if (i == 2 || i == 5){
            cout<<endl;
            cout<<"-------"<<endl;
            cout<<"|";
        }
    }
    return;
}

void Board::initalise(){
    BoardValue[0] = '1';
    BoardValue[1] = '2';
    BoardValue[2] = '3';
    BoardValue[3] = '4';
    BoardValue[4] = '5';
    BoardValue[5] = '6';
    BoardValue[6] = '7';
    BoardValue[7] = '8';
    BoardValue[8] = '9';
}

void Board::clearBoard(){
        for (int i=0; i!= 9; i++){
            BoardValue[i] = ' ';
        }
}

bool Board::validateMove(){
    bool movePoss = false;
    for (int i = 0; i != 9; i++){
        if (BoardValue[i] == ' '){
            movePoss = true;
        }
    }
    return movePoss;
}

bool Board::checkForWin(char player){
    bool win = false;
    for (int x = 0; x!= 8; x++){
        int count = 0;
        for (int i = 0; i != 3; i++){
            if (BoardValue[winningValues[x][i]] == player){
                count = count + 1;
                if (count == 3){
                    break;
                }
            }
        }
        if (count == 3){
            win = true;
        }
    }
    return win;
}
