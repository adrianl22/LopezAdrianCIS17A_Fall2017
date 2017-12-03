/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Sep 27, 2017, 7:37 PM
 * Purpose: Filling an array with allocated memory
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
int filAray(int *,int);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    int size=0,perLine=10;  //number of test scores within array
    float avg;
     cout<<"Enter the size of the array"<<endl;
    cin>>size;
    int *array=new int [size];
    
    //Input or initialize values Here
    cout<<"Filling the array with "<<size<<" numbers within it."<<endl;
    filAray(array,size);
    cout<<endl;
    //Process/Calculations Here

    //Output Located Here

    for (int i=0;i<=size-1;i++){
        cout<<array[i]<<" ";
        if (i%perLine==(perLine-1))cout<<endl;
    }

    delete []array;
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