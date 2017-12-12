/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guess.h
 * Author: Adrian Lopez
 *
 * Created on December 11, 2017, 7:17 PM
 */

#ifndef GUESS_H
#define GUESS_H

class Guess {
public:
    Guess();
    getX()const;
    getNGuess()const;
    getNum()const;
    virtual ~Guess();
private:
    int num;
    int nGuess;
    int x;
    int guess;
};

#endif /* GUESS_H */

