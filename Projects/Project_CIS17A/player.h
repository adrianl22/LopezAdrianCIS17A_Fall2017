/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.h
 * Author: Adrian Lopez
 *
 * Created on November 4, 2017, 10:58 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
struct player{
    string name;
    int row=10;
    int col=1;
    int turns=1;
};


#endif /* PLAYER_H */

