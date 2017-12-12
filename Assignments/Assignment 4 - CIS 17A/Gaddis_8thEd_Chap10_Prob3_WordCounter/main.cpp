/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Oct 12, 2017, 4:28 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int wordCnt(char [],int);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=100;
    char input[SIZE];
    int nChar=0,j=0;;
    
    //Input or initialize values Here
    cout<<"Type in a sentence within 100 characters to see how"
            " many words you typed."<<endl;
    cout<<"Don't forget to end your sentence with a '.', '!' or '?'."<<endl;
    cout<<"For the best result of course."<<endl<<endl;
    cin.getline(input,SIZE);
    nChar=wordCnt(input,SIZE);
    
    //Process/Calculations Here
    cout<<endl<<"Number of words = "<<nChar<<endl;
    
    //Output Located Here

    //Exit
   return 0;
}
int wordCnt(char a[],int b){
    int count=0;
    for(int i=0;i<=b;i++){
        if (a[i]==' '||a[i]=='.'||a[i]=='!'||a[i]=='?'){
            count++;
            if(a[i]=='.'||a[i]=='!'||a[i]=='?')break;
        }
    }
    return count;
}
