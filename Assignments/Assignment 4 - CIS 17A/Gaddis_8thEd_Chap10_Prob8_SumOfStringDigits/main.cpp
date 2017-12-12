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
int length(string );
void sum(string, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    string input,back;
    int nChar=0,j=0;;
    
    //Input or initialize values Here
    cout<<"Type in a string of digits and this program"
            " will find the sum of them."<<endl;
    cin>>input;
    
    //Process/Calculations Here
    nChar=length(input);
   
    //Output Located Here
    sum(input,nChar);
    //Exit
   return 0;
}
int length(string a){
    int n=0,i=0;
    do{
        if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||
            (a[i]>='!'&&a[i]<=')')||(a[i]>='0'&&a[i]<='9')){
            n++;
            i++;
        }
    }while (a[i]!='\0');
    return n;
}
void sum(string a, int b){
    float num=0.0f, sm=0.0f;
    cout<<"Sum of your numbers  = ";
    for (int i=b-1;i>=0;i--){
        if (a[i]=='1')num=1;
        if (a[i]=='2')num=2;
        if (a[i]=='3')num=3;
        if (a[i]=='4')num=4;
        if (a[i]=='5')num=5;
        if (a[i]=='6')num=6;
        if (a[i]=='7')num=7;
        if (a[i]=='8')num=8;
        if (a[i]=='9')num=9;
        if (a[i]=='0')num=0;
        sm+=num;
    }
    cout<<sm<<endl;
}