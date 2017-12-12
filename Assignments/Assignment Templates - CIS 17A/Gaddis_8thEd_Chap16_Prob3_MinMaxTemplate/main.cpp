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
template <class T>T Min(T a,T b){
            if (a<b){
                return a;
            }
            else return b;
        }
template <class T>T Max(T a,T b){
            if (a>b){
                return a;
            }
            else return b;
        }
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float num1=0,num2=0,abs=0;
    //Input or initialize values Here
    cout<<"This functions takes in two numbers and tells"<<endl;
    cout<<"you which number is greater and which is smaller"<<endl;
    cout<<"Enter two numbers"<<endl;
    cin>>num1;
    cin>>num2;
    //Process/Calculations Here
    
    //Output Located Here
    cout<<endl<<"Your numbers = "<<num1<<", "<<num2<<endl;
    cout<<"Maximum      = "<<Max(num1,num2)<<endl;
    cout<<"Minimum      = "<<Min(num1,num2)<<endl;
    //Exit
   return 0;
}