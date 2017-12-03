/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Sep 27, 2017, 8:07 PM
 * Purpose: Rewriting into pointer notation
 */

//System Libraries Here
#include <iostream> //input - output Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int doSmtng(int &, int &);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int     x,//integer number 1
            y,//integer number 2
            sum;
    //Input or initialize values Here
    cout<<"Enter two numbers"<<endl;
    cin>>x;
    cin>>y;
    //Process/Calculations Here
    cout<<"I will now do something to these two numbers."<<endl;
    sum=doSmtng(x,y);
    
    //Output Located Here
    cout<<"I change your first input into   "<<x<<endl;
    cout<<"The second number was changed to "<<y<<endl;
    cout<<"The sum of the new numbers is  = "<<sum<<endl;
    //Exit
   return 0;
}
int doSmtng(int &x, int &y){
    int temp=x;
    x=y*10;
    y=temp*10;
    return x+y;
}