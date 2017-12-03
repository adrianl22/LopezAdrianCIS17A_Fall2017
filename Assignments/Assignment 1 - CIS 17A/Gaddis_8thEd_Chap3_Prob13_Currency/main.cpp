/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on September 17, 2017, 1:19 PM
 * Purpose:  Conversion from U.S. Dollars into Japanese Yen
 *           or to Euros.
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Formatting


using namespace std; //Name-space under which system libraries exist

//User Libraries


//Global Constants
const float YNPDOLL=110.85f,//yen per US dollars
            EUPDOLL=0.84f;  //euro per US dollars

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Initialize variables
    float op1; //Amount money user has

    //Input data
    cout<<fixed<<setprecision(2);   //Set precision to decimal places
    cout<<"This Program converts from U.S dollars to"
            " Japanese Yen and Euros."<<endl;
    //Amount of dollars to be converted
    cout<<"How many U.S dollars do you have?"<<endl;
    cout<<"$";
    cin>>op1;
    cout<<endl;
    //Map inputs to outputs or process the data
    //Convert into yen
    cout<<"$"<<op1<<" U.S Dollars = "<<op1*YNPDOLL<<" Yen"<<endl;
    //Convert into Euros
    cout<<"$"<<op1<<" U.S Dollars = "<<op1*EUPDOLL<<" Euros"<<endl;
    
    //Output the transformed data


    //Exit stage!
    return 0;
}
