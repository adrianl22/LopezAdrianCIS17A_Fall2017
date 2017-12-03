/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on March 19, 2017, 9:20 PM
 * Purpose:  
 */

//System Libraries
#include <iostream>  //Input - Output Library

using namespace std; //Name-space under which system libraries exist

//User Libraries


//Global Constants


//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Initialize variables
    string  num;//Integer valid from [1-10]
    int choice;
    //Input or initialize values Here
    cout<<"This program produces the Roman Numeral counter"
            "part for a number between 1-10"<<endl;
    cout<<"Type in the number [1-10] you wish to see."<<endl;
    cin>>choice;
    if ((choice>10 || choice<1))    //Limit to just numbers [1-10]
    {    cout<<"Invalid number."<<endl;
        return 1;}
    
    //Process/Calculations Here
    switch(choice){    //Convert number [1-10] 
        case 10: num='X';break;
        case  9: num="IX";break;
        case  8: num="VIII";break;
        case  7: num="VII";break;
        case  6: num="VI";break;
        case  5: num='V';break;
        case  4: num="IV";break;
        case  3: num="III";break;
        case  2: num="II";break;
        case  1: num='I';break;}
    //Output Located Here
    cout<<"For "<<choice<<" the Roman Numeral is "<<num<<endl;

    //Exit
    return 0;
}

