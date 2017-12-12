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
void backSt(string, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string input,back;
    int nChar=0,j=0;;
    
    //Input or initialize values Here
    cout<<"Type in a string to see what it looks like backwards."<<endl;
    cin>>input;
    
    //Process/Calculations Here
    nChar=strLen(input);
   
    //Output Located Here
    backSt(input,nChar);
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
void backSt(string a, int b){
    cout<<"Your string backwards = ";
    for (int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
}