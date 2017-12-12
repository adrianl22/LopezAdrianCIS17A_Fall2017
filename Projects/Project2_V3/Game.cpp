/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: Adrian Lopez
 * 
 * Created on December 11, 2017, 10:43 AM
 */

#include "Game.h"
#include "Rules.h"
#include <iostream>
#include <fstream>
using namespace std;

int Game::num=0;
Game::Game() {
    pos=0;
    die=0;
    nPlay=0;
}
void Game::setNum(){
    num=num+1;
}
void Game::setPos(const int d){
    pos=d;
}
void Game::rules(){
    ifstream inFile;
    inFile.open("rules.txt");
    if (inFile.fail()){
        cerr<<"Error Opening File"<<endl;
        exit(1);
    }
    //Display rules
    string text;    //words found in text
    int count=0;    //counter for words
    cout<<"Rules"<<endl;
    cout<<"_____"<<endl;
    
    //loop words displayed
    while (inFile.good()){
        inFile>>text;
        cout<<text<<" ";
        count++;
        //end line after 12 words
        if (count==12){
            cout<<endl;
            count=0;
        }
    }
    
    //close file
    inFile.close();
}
void Game::setNPlay(const int a){
    nPlay=a;
}
Game::~Game() {
}

