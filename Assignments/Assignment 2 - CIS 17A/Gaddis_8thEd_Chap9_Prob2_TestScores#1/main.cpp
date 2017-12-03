/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Sep 27, 2017, 3:34 PM
 * Purpose: Finding Mean/Average test scores
 */

//System Libraries Here
#include <iostream> //input - output Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void mrkSort(int *, int);
float testAvg(int *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int nTests,perLine=10;  //number of test scores within array
    float avg;
     cout<<"Enter the number of tests graded."<<endl;
    cin>>nTests;
    int *array=new int [nTests];
    
    //Input or initialize values Here
    for (int i=0;i<=nTests-1;i++){
        cin>>array[i];
    }
    cout<<endl;
    //Process/Calculations Here
    mrkSort(array,nTests);
    avg=testAvg(array,nTests);
    //Output Located Here
    cout<<"List of all "<<nTests<<" Scores from Lowest to Highest"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0;i<=nTests-1;i++){
        cout<<array[i]<<" ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl<<"Average score = "<<avg<<" points"<<endl;
    delete []array;
    //Exit
   return 0;
}
void mrkSort(int *a, int n){
    for (int pos=0; pos<n-1;pos++){
        for (int indx2=pos+1;indx2<n;indx2++){
            if (a[pos]>a[indx2]){
                    int temp;
                    temp=a[pos];
                    a[pos]=a[indx2];
                    a[indx2]=temp;
            }
        }
    }
}
float testAvg(int *a, int n){
    float sum=0.0f,avrg=0.0f;
    for (int i=0;i<=n-1;i++){
        sum+=a[i];
    }
    avrg=sum/n;
    return avrg;
}