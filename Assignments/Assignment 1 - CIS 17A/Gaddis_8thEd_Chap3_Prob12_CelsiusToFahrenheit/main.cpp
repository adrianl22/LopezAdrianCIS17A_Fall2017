/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on September 17, 2017, 1:19 PM
 * Purpose:  Conversion from degrees Celsius
 *           to degrees Fahrenheit
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Formatting


using namespace std; //Name-space under which system libraries exist
//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Initialize variables
    float degCel=0.0f, //Degrees Celsius
          degFar=0.0f; //Degrees Fahrenheit 

    //Input data
    cout<<"This program converts from degrees"<<endl;
    cout<<"Celsius into degrees Fahrenheit."<<endl;
    cout<<endl<<"Give an amount in degrees Celsius to convert into"<<endl;
    cout<<"Fahrenheit."<<endl;
    cin>>degCel;
    //Map inputs to outputs or process the data
    degFar=9.0f/5.0f*degCel+32;
    //Output the transformed data
    cout<<fixed<<setprecision(1);
    cout<<degCel<<" C = "<<degFar<<" F"<<endl;

    //Exit stage!
    return 0;
}
