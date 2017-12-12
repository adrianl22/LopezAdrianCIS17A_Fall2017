/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Oct 12, 2017, 4:28 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <string>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int strLen(string );
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string input;
    int nChar=0;
    
    //Input or initialize values Here
    cout<<"Type in a string to see how many characters it has."<<endl;
    cin>>input;
    //Process/Calculations Here
    nChar=strLen(input);
    //Output Located Here
    cout<<"There are "<<nChar<<" Characters in your string"<<endl;
    //Exit
   return 0;
}
int strLen(string a){
    int n=0,i=0;
    do{
        if ((a[i]>='!'&&a[i]<='}')){
            n++;
            i++;
        }
    }while (a[i]!='\0');
    return n;
}