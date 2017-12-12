/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Nov , 2017, 3:43 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
using namespace std;


//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
template <class T>T AbsV(T a){
            if (a<0){
                a=a*(-1);
                return a;
            }
            else{ 
                return a;
            }
        }
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float num=0,abs=0;
    //Input or initialize values Here
    cout<<"Enter a number to see its absolute value"<<endl;
    cin>>num;
    //Process/Calculations Here
    abs=AbsV(num);
    //Output Located Here
    cout<<"Absolute Value = "<<abs<<endl;
    //Exit
   return 0;
}