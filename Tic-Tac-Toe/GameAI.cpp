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

void GameAISimple::makeMove(){
    int AIMoves[9];
    for (int i = 0; i!= 9; i++){
        if (playboard.BoardValue[i] == ' '){
            AIMoves[i] = i;
        }else{
            AIMoves[i] = 10;
        }
    }
    random_shuffle(begin(AIMoves), end(AIMoves));
    if (AIMoves[0] == 10){
        GameAISimple::makeMove();
    }else{
        playboard.BoardValue[AIMoves[0]] = 'O';
        cout<<"My move is "<< AIMoves[0]+1<<endl;
    }
}

void GameAIMedium::makeMove(){
    if (winningMovePossible()){
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
        }else{
            AIMoves[i] = 10;
        }
    }
    random_shuffle(begin(AIMoves), end(AIMoves));
    if (AIMoves[0] == 10){
        GameAIMedium::makeMove();
    }else{
        playboard.BoardValue[AIMoves[0]] = 'O';
        cout<<"My move is "<< AIMoves[0]+1<<endl;
    }
}

bool GameAIMedium::winningMovePossible(){
    Board testBoard;
    char players[2] = {'X', 'O'};
    for (int i = 0; i!= 9; i++){
        testBoard.BoardValue[i] = playboard.BoardValue[i];
    }
    bool makeMove = false;
    for (int i = 0; i!= 2; i++){
        char player = players[i];
        for (int i = 0; i!= 9; i++){
            if (testBoard.BoardValue[i] == ' ' && makeMove == false){
                testBoard.BoardValue[i] = player;
                if (testBoard.checkForWin(player)){
                    playboard.BoardValue[i] = 'O';
                    makeMove = true;
                    cout<<"My move is "<<i+1<<endl;
                }else{
                    testBoard.BoardValue[i] = ' ';
                }
            }
        }
    }
    return makeMove;
}

void GameAIHard::makeMove(){
    int corners[4] = {0, 2, 6, 8};
    int center[1] = {5};
    int middle[4] = {1, 3, 5, 7};
    if (winningMovePossible()){
        ;
    }else if (influentialMoves(corners, 4)){
        ;
    }else if (influentialMoves(center, 1)){
        
    }else if (influentialMoves(middle, 4)){
        
    }else{
        moveRandomisation();
    }
    
}

void GameAIHard::moveRandomisation(){
    int AIMoves[9];
    for (int i = 0; i!= 9; i++){
        if (playboard.BoardValue[i] == ' '){
            AIMoves[i] = i;
        }else{
            AIMoves[i] = 10;
        }
    }
    random_shuffle(begin(AIMoves), end(AIMoves));
    if (AIMoves[0] == 10){
        GameAIHard::makeMove();
    }else{
        playboard.BoardValue[AIMoves[0]] = 'O';
        cout<<"My move is "<< AIMoves[0]+1<<endl;
    }
}

bool GameAIHard::winningMovePossible(){
    Board testBoard;
    char players[2] = {'X', 'O'};
    for (int i = 0; i!= 9; i++){
        testBoard.BoardValue[i] = playboard.BoardValue[i];
    }
    bool makeMove = false;
    for (int i = 0; i!= 2; i++){
        char player = players[i];
        for (int i = 0; i!= 9; i++){
            if (testBoard.BoardValue[i] == ' ' && makeMove == false){
                testBoard.BoardValue[i] = player;
                if (testBoard.checkForWin(player)){
                    playboard.BoardValue[i] = 'O';
                    makeMove = true;
                    cout<<"My move is "<<i+1<<endl;
                }else{
                    testBoard.BoardValue[i] = ' ';
                }
            }
        }
    }
    return makeMove;
}

bool GameAIHard::influentialMoves(int possiblePreferences[], int size){
    bool hasMoved = false;
    int move[4];
    int emptyArray = 0;
    for (int i = 0; i!= size; i++){
        if (playboard.BoardValue[possiblePreferences[i]] == ' '){
            move[i] = possiblePreferences[i];
        }
    }
    for (int i = 0; i!= size; i++){
        if (move[i] == 0){
            emptyArray = emptyArray+1;
        }
    }
    if (emptyArray != 4){
        random_shuffle(begin(move), end(move));
        playboard.BoardValue[move[0]] = 'O';
        cout<<"My move is "<< move[0]+1<<endl;
        hasMoved = true;
    }
    return hasMoved;
}

