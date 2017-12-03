/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Sep 27, 8:36 PM
 * Purpose: Reversing an array
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <cstdlib>   //Random number generator
#include <ctime>     //Time Library to seed the random number generator
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(int *, int);
int filAray(int *, int);
int revAray(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    const int SIZE=10;
    int array[SIZE];
   
    //Process/Calculations Here
    filAray(array,SIZE);

    //Output Located Here
        cout<<"First array"<<endl;
    cout<<"________________________________"<<endl;
    for (int i=0;i<=SIZE;i++){
        cout<<array[i]<<" ";       
    }
    cout<<endl<<endl;
    cout<<"Reversed Array"<<endl;
    cout<<"________________________________"<<endl;
    revAray(array,SIZE);
    //Exit
   return 0;
}
int filAray(int *a,int n){
    for (int i=0;i<=n-1;i++){
        int n=0;
        n=rand()%89+10;
        a[i]=n;
    }
    return *a;
}
int revAray(int *a, int n){
    int array[n];
    int k=0;
    for (int i=n;i>=0;i--){
        int temp=a[i];
        array[k]=temp;
        k++;
    }
    for (int i=0;i<=n;i++){
        cout<<array[i]<<" ";       
    }
}