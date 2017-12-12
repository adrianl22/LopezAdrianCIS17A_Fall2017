/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: Adrian Lopez
 *
 * Created on December 11, 2017, 10:43 AM
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class Game{
public:
    static int num;
    Game();
    void setNum();
    void setPos(const int);
    void rules();
    void setNPlay(const int);
    getPos()const{
        return pos;
    }
    virtual ~Game();
protected:
    int nPlay;
private:
    int pos;
    int die;
};
class Numbr: public Game{
public: 
    getNum()const{
        return nPlay;
    }
};
class Numero:public Game{
public: 
    getNum()const{
        return nPlay;
    }
};

#endif /* GAME_H */
