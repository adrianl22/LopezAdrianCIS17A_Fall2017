/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Dec 3, 2017, 2:44 PM
 * Purpose: Finding Mean/Average test scores
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <vector>   //Vector Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

void mrkSort(vector<int>&, int);
float testAvg(vector<int>&,  int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int nTests,perLine=10;  //number of test scores within array
    float avg;
     cout<<"Enter the number of tests graded: ";
    cin>>nTests;
    cout<<"____________________________________"<<endl;
    vector<int> scores(nTests-1);
    
    //Input or initialize values Here
    for (int i=0;i<=nTests-2;i++){
        int t=0;
        cin>>t;
        scores[i]=t;
    }
    cout<<"Enter the last score"<<endl;
    int temp=0;
    cin>>temp;
    scores.push_back(temp);
    cout<<endl;
    //Process/Calculations Here
    mrkSort(scores,nTests);
    avg=testAvg(scores,nTests);
    //Output Located Here
    cout<<"List of all "<<nTests<<" score(s) from Lowest to Highest"<<endl;
    cout<<"___________________________________________"<<endl;
    for (int i=0;i<=nTests-1;i++){
        cout<<scores[i]<<" ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl<<"Average score = "<<avg<<" points"<<endl;
    //Exit
   return 0;
}
void mrkSort(vector<int>&a, int n){
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
float testAvg(vector<int>&a, int n){
    float sum=0.0f,avrg=0.0f;
    for (int i=0;i<=n-1;i++){
        sum+=a[i];
    }
    avrg=sum/n;
    return avrg;
}