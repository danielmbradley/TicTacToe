//
//  gamePlay.cpp
//  Tic-Tac-Toe
//
//  Created by Daniel Bradley on 10/02/2018.
//  Copyright © 2018 Perawk. All rights reserved.
//

#include "gamePlay.hpp"
#include "printBoard.hpp"
#include "GameAI.hpp"
#include <iostream>
#include <sstream>

Board playboard;
GameAISimple AILevel1;
GameAIMedium AILevel2;

void levelOne(){
    char turn = 'X';
    string replay;
    playboard.clearBoard();
    turn = 'X';
    playboard.printBoard();
    cout<<endl;
    cout<<endl;
    while ((playboard.checkForWin(changePlayer(turn)) == false && playboard.validateMove()) == true){
        movement(turn);
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?"<<endl;
        cin>>replay;
        if (replay =="y"){
            levelOne();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?"<<endl;
        cin>>replay;
        if (replay =="y"){
            levelOne();
        }else{
            runGame();
        }
    }
}

void levelTwo(){
    char turn = 'X';
    string replay;
    playboard.clearBoard();
    turn = 'X';
    playboard.printBoard();
    cout<<endl;
    cout<<endl;
    while ((playboard.checkForWin(changePlayer(turn)) == false && playboard.validateMove()) == true){
        if (turn == 'X'){
           movement(turn);
        }else{
            AILevel1.generateMove();
        }
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?(y/n)"<<endl;
        cin>>replay;
        if (replay =="y"){
            levelTwo();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?(y/n)"<<endl;
        if (replay =="y"){
            levelTwo();
        }else{
            runGame();
        }
    }
}

void levelThree(){
    char turn = 'X';
    string replay;
    playboard.clearBoard();
    turn = 'X';
    playboard.printBoard();
    cout<<endl;
    cout<<endl;
    while ((playboard.checkForWin(changePlayer(turn)) == false && playboard.validateMove()) == true){
        if (turn == 'X'){
            movement(turn);
        }else{
            AILevel2.generateMove();
        }
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?(y/n)"<<endl;
        cin>>replay;
        if (replay =="y"){
            levelTwo();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?(y/n)"<<endl;
        if (replay =="y"){
            levelTwo();
        }else{
            runGame();
        }
    }
}


void runGame(){
    playboard.clearBoard();
    cout<<"Each box has a number, the number is indicated in the grib below."<<endl;
    cout<<"To place a counter in a box, simply type the box number when asked"<<endl;
    playboard.initalise();
    playboard.printBoard();
    playboard.clearBoard();
    string level;
    cout<<endl;
    cout<<endl;
    cout<<"Noughts and Crosses"<<endl;
    cout<<"1. Multiplayer Player"<<endl;
    cout<<"2. Easy Single Player"<<endl;
    cout<<"3. Medium Single Player"<<endl;
    cout<<"4. Hard Single Player"<<endl;
    cin>> level;
    int levelNum;
    try{
        levelNum = stoi(level);
    }
    catch(const std::invalid_argument& ia){
        level = "1";
        levelNum = stoi(level);
    }
    switch (levelNum){
        case 1 : levelOne();
        case 2 : levelTwo();
        case 3 : levelThree();
    }
}

void movement(char whosTurn){
    bool rightNum = false;
    while (!rightNum){
        int squareInt;
        string square;
        cout<<"Which square would "<< whosTurn << " like to place their "<< whosTurn <<" on? ";
        cin >> square;
        try{
            squareInt = stoi(square);
        }
        catch(const std::invalid_argument& ia){
            square = "-2";
            squareInt = stoi(square);
        }
        squareInt = squareInt - 1;
        if ((squareInt >= 0)&&(squareInt<10)){
            if (playboard.BoardValue[squareInt] == ' '){
                playboard.BoardValue[squareInt] = whosTurn;
                rightNum = true;
            }else{
                cout<<"There is already a value in that square"<<endl;
            }
        }else{
            cout<<"Incorrect Square, try again"<<endl;
        }
    }
}

char changePlayer(char whichPlayer){
    if (whichPlayer == 'X'){
        whichPlayer = 'O';
    }
    else{
        whichPlayer = 'X';
    }
    return whichPlayer;
}
