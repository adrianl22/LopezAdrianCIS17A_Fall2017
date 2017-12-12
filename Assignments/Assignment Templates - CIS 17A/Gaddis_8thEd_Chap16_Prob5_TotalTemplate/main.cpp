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
template <class T> T total(T a,T b){
    cout<<"Enter the values"<<endl;
    for (int i=1;i<=a;i++){
        int j=0;
        cin>>j;
        b=b+j;
    }
    return b;
}
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int num=0,ttl=0;
    //Input or initialize values Here
    cout<<"This program takes in a number of values then adds up"<<endl;
    cout<<"the values entered to get the total"<<endl;
    cout<<"Enter the number of values"<<endl;
    cin>>num;
    //Process/Calculations Here
    ttl=total(num, ttl);
    //Output Located Here
    cout<<endl<<"Number of values        = "<<num<<endl;
    cout<<"Total of all the values = "<<ttl<<endl;
    //Exit
   return 0;
}