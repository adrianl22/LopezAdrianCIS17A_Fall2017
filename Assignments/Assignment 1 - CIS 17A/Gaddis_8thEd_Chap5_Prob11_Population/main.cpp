/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on September 17, 2017, 2:12 PM
 * Purpose:  Determining the growing population of an organism
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Formatting
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int     pop=0,   //Population size
            nPop=0;  //New population size
    float   incPer=0.0f,//Increase Percentage
            nDays=0.0f; //Number of days
    //Input or initialize values Here
    cout<<"This program determines the growing"<<endl;
    cout<<"population of an organism."<<endl;
    do{
        cout<<endl<<"Enter the Size of the population."<<endl;
        cin>>pop;
        if (pop<2)
            cout<<"Enter a number bigger than 2."<<endl;
    }while (pop<2);
    do{
        cout<<endl<<"Enter the population increase as a percentage."<<endl;
        cin>>incPer;
        if (incPer<0)
            cout<<"Enter a positive percentage"<<endl;
    }while (incPer<0);
    do{
        cout<<endl<<"Enter the number of days they will multiply."<<endl;
        cin>>nDays;
        if (nDays<1){
            cout<<"At least put one day so they actually have a chance"<<endl;
            cout<<"at having babies"<<endl;}
    }while (nDays<1);
    //Process/Calculations Here
    nPop=pop*(incPer/nDays)+pop;
    //Output Located Here
    cout<<"Original Population                 = "<<pop<<endl;
    cout<<"Increase Percentage                 = "<<incPer<<endl;
    cout<<"Number of Days                      = "<<nDays<<endl;
    cout<<"Future Population size after "<<nDays<<" days = "<<nPop<<
            " organisms"<<endl;
    //Exit
   return 0;
}