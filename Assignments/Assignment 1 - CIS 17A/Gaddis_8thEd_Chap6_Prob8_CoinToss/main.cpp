/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on April 1, 2017, 8:12 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <cstdlib>  //Random num gen
#include <ctime>    //Set random num seed
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int coinToss(int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int n;//number of times coin is flipped
    //Input or initialize values Here
    cout<<"This program simulates a coin toss"<<endl;
    cout<<"Enter the number of times should be tossed"<<endl;
    cin>>n;
    cout<<endl;
    //Process/Calculations Here

    //Output Located Here
    coinToss(n);
    //Exit
   return 0;
}
int coinToss(int a){
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    int num,nHeads=0,nTails=0;
    for (int i=1;i<=a;i++){
        num=rand()%2+1;
        if (num==1){
            cout<<"Toss #"<<i<<" = "<<"Heads"<<endl;
            nHeads++;}
        else if (num==2){
            cout<<"Toss #"<<i<<" = "<<"Tails"<<endl;
            nTails++;}
    }
    cout<<endl<<"Total number of Tails = "<<nTails<<endl;
    cout<<"Total number of Heads = "<<nHeads<<endl;
}