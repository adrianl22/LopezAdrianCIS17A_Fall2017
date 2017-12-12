/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Nov , 2017, 3:43 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Formatting
using namespace std;


//User Libraries Here
#include "TestScores.h"
//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int num=0;      //Number of Scores to be entered
    TestScores c1;  //Scores for group of tests;
    
    //Input or initialize values Here
    cout<<"This program takes a numbers of tests scores and"<<endl;
    cout<<"gives the average of them all."<<endl;
    cout<<"Enter the number of Test Scores"<<endl;
    cin>>num;
    cout<<endl;
    
    //Process/Calculations Here
    c1.setScores(num);
    c1.setAvg();
    //Output Located Here
    cout<<fixed<<setprecision(2);
    cout<<"Class Average = "<<c1.getAvg()<<endl;
    //Exit
   return 0;
}