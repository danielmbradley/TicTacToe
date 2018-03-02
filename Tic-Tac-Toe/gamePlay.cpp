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
#include <unistd.h>

Board playboard;
GameAISimple AILevel1;
GameAIMedium AILevel2;
GameAIHard AILevel3;

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
        cout<<"New Game? (Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelOne();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game? (Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
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
            cout<<endl;
            cout<<endl;
            sleep(1);
            cout<<"Making Move."<<endl;
            sleep(1);
            cout<<"Making Move.."<<endl;
            sleep(1);
            cout<<"Making Move..."<<endl;
            sleep(1);
            AILevel1.makeMove();
        }
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelTwo();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
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
            cout<<endl;
            cout<<endl;
            sleep(1);
            cout<<"Making Move."<<endl;
            sleep(1);
            cout<<"Making Move.."<<endl;
            sleep(1);
            cout<<"Making Move..."<<endl;
            sleep(1);
            AILevel2.makeMove();
        }
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelThree();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelThree();
        }else{
            runGame();
        }
    }
}

void levelFour(){
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
            cout<<endl;
            cout<<endl;
            sleep(1);
            cout<<"Making Move."<<endl;
            sleep(1);
            cout<<"Making Move.."<<endl;
            sleep(1);
            cout<<"Making Move..."<<endl;
            sleep(1);
            AILevel3.makeMove();
        }
        playboard.printBoard();
        turn = changePlayer(turn);
    }
    if (playboard.checkForWin(changePlayer(turn))){
        cout<<"Player "<<changePlayer(turn)<<" wins"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelFour();
        }else{
            runGame();
        }
    }
    else{
        cout<<"A Draw"<<endl;
        cout<<"New Game?(Y/N)"<<endl;
        cin>>replay;
        if (replay =="y" || replay == "Y"){
            levelFour();
        }else{
            runGame();
        }
    }
}


void runGame(){
    playboard.clearBoard();
    cout<<"Each box has a number, the number is indicated in the grid below."<<endl;
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
    cout<<"5. Exit"<<endl;
    cin>> level;
    int levelNum;
    try{
        levelNum = stoi(level);
    }
    catch(const std::invalid_argument& ia){
        cout<<"Invalid Input"<<endl;
        level = "180383944";
        levelNum = stoi(level);
    }
    switch (levelNum){
        case 1 : levelOne();
        case 2 : levelTwo();
        case 3 : levelThree();
        case 4 : levelFour();
        case 5 : return;
        case 180383944 : runGame();
        default : return;
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
