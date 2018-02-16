//
//  GameAI.cpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 12/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#include "GameAI.hpp"
#include "printBoard.hpp"
#include <algorithm>
#include <iostream>
#include "gamePlay.hpp"

using namespace std;

void GameAISimple::generateMove(){
    int AIMoves[9];
    for (int i = 0; i!= 9; i++){
        if (playboard.BoardValue[i] == ' '){
            AIMoves[i] = i;
        }
    }
    random_shuffle(begin(AIMoves), end(AIMoves));
    playboard.BoardValue[AIMoves[0]] = 'O';
    cout<<"My move is "<< AIMoves[0]+1<<endl;
}

void GameAIMedium::generateMove(){
    if (winningMovePossible()){
        ;
    }else if (goingToLose()){
        ;
    }else{
        moveRandomisation();
    }
}

void GameAIMedium::moveRandomisation(){
    int AIMoves[9];
    for (int i = 0; i!= 9; i++){
        if (playboard.BoardValue[i] == ' '){
            AIMoves[i] = i;
        }
    }
    random_shuffle(begin(AIMoves), end(AIMoves));
    playboard.BoardValue[AIMoves[0]] = 'O';
    cout<<"My move is "<< AIMoves[0]+1<<endl;
}

bool GameAIMedium::winningMovePossible(){
    Board testBoard;
    for (int i = 0; i!= 9; i++){
        testBoard.BoardValue[i] = playboard.BoardValue[i];
    }
    bool makeMove = false;
    for (int i = 0; i!= 9; i++){
        if (testBoard.BoardValue[i] == ' ' && makeMove == false){
            testBoard.BoardValue[i] = 'O';
            if (testBoard.checkForWin('O')){
                playboard.BoardValue[i] = 'O';
                makeMove = true;
                cout<<"My move is "<<i+1<<endl;
            }else{
                testBoard.BoardValue[i] = ' ';
            }
        }
    }
    return makeMove;
}

bool GameAIMedium::goingToLose(){
    Board testBoard;
    for (int i = 0; i!= 9; i++){
        testBoard.BoardValue[i] = playboard.BoardValue[i];
    }
    bool makeMove = false;
    for (int i = 0; i!= 9; i++){
        if (testBoard.BoardValue[i] == ' ' && makeMove == false){
            testBoard.BoardValue[i] = 'X';
            if (testBoard.checkForWin('X')){
                playboard.BoardValue[i] = 'O';
                makeMove = true;
                cout<<"My move is "<<i+1<<endl;
            }else{
                testBoard.BoardValue[i] = ' ';
            }
        }
    }
    return makeMove;
}



