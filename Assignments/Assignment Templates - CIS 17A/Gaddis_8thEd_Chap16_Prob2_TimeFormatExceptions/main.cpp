/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Dec , 2017, 3:43 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
using namespace std;


//User Libraries Here
#include "Time.h"
//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    Time time;
    //Input or initialize Time
    cout<<"This Program take in military hours to display"<<endl;
    cout<<"the time in standard hours"<<endl<<endl;
    time.setTime();
    //Process/Calculations Here

    //Output Located Here
    time.getHour();
    time.getStandHr();
    //Exit
   return 0;
}