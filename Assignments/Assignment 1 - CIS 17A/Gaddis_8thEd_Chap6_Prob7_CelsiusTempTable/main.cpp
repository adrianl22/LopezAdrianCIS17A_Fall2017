/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on April 1, 2017, 8:12 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Formatting
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable

//Like PI, e, Gravity, or conversions

//Function Prototypes Here
float celsius(float);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float   f,//Fahrenheit
            c;//Celsius
    //Input or initialize values Here
    cout<<"This Program Converts Fahrenheit to Celsius"<<endl;
    cout<<"Enter degrees in Fahrenheit to convert"<<endl;
    cin>>f;
    //Process/Calculations Here
    c=celsius(f);
    //Output Located Here
    cout<<fixed<<setprecision(1);
    cout<<f<<"°F = "<<c<<"°C"<<endl;
    //Exit
   return 0;
}
float celsius(float a){
    float b;
    b=5.0f/9.0f*(a-32);
    return b;
}
