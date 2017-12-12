/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guess.cpp
 * Author: Adrian Lopez
 * 
 * Created on December 11, 2017, 7:17 PM
 */

#include "Guess.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

Guess::Guess() {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    x=rand()%5+1;
    num=pow(10,x);
    num=rand()%num+1;
    nGuess=log2(pow(10,x))+1;
}
Guess::getX()const{
    return x;
}
Guess::getNGuess()const{
    return nGuess;
}
Guess::getNum()const{
    return num;
}
Guess::~Guess() {
}
