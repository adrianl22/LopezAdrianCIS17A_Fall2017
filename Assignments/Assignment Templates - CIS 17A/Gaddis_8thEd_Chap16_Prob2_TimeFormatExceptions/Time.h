/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: FlamingEdchidna
 *
 * Created on December 3, 2017, 10:00 PM
 */

#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time();
    void setTime();
    void getHour();
    void getStandHr();
    
private:
    int milHours;   //Military hours
    int milSec;     //Seconds
    int hour;       //Hours in standard time
    int min;        //Minutes for standard time
    

};

#endif /* TIME_H */

