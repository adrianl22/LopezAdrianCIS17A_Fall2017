/* 
 * File:   Time.cpp
 * Author: Adrian Lopez
 * 
 * Created on December 3, 2017, 10:00 PM
 */

#include "Time.h"

#include <iostream>
using namespace std;

Time::Time() {
    milHours=0;
    milSec=0;
    hour=0;
    min=0;
}
void Time::setTime(){
    //user input military hour/sec
    cout<<"Enter military time"<<endl;
    cout<<"Hours:   ";
    cin>>milHours;
    cout<<"Seconds: ";
    cin>>milSec;
    try{
        if (milHours%100>59){
            throw 1;
        }
        else if (milHours>2359||milHours<0){
            throw 2;
        }
        else if (milSec>59||milSec<0){
            throw 3;
        }
    }catch(int x){
        switch (x){
            case 1:{cout<<"Bad Minutes, ERROR NUMBER "<<x<<endl;
                    break;}
            case 2:{cout<<"Bad Military Hours, ERROR NUMBER "<<x<<endl;
                    break;}
            case 3:{cout<<"Bad Seconds, ERROR NUMBER "<<x<<endl;
                    break;}
            default:{cout<<"ERROR"<<endl;break;}
        }
        exit(0);
    }
    //set hours
    if (milHours>1259){
        hour=milHours-1200;
    }
    else if (milHours<100){
        hour=milHours;
        hour=hour+1200;
    }
    else {hour=milHours;
    }
    //minutes
    min=hour%100;
    //configure hour
    hour=(hour-min)/100;
}
void Time::getHour(){
    //Display Military time
    cout<<"Military Time = "<<milHours<<" hours "<<milSec<<" seconds"<<endl;
}
void Time::getStandHr(){
    //Display standard time
    cout<<"Standard Hour = "<<hour<<":"<<min<<":"<<milSec;
    //AM or PM
    if(milHours>=1200){
        cout<<" PM"<<endl;
    }
    else{cout<<" AM"<<endl;}
}