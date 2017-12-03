/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Sep 27, 2017, 6:37 PM
 * Purpose: Finding the mode
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Format
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void mrkSort(int *, int);   //Sort the array
float testAvg(int *, int);  //Find total average
float lwstDrp(int *, int);  //Find average with lowest grade dropped
float testMed(int *, int);  //Find the Median of the grades
int testMod(int *, int);  //Find the mode of all the grades

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int nTests,perLine=10;  //number of test scores within array
    float   avg1=0.0f,      //average of all test scores
            avg2=0.0f,      //average of all scores except the lowest
            median=0.0f;
    int     mode=0;
    do{
    cout<<"Enter the number of tests graded."<<endl;
    cin>>nTests;
    if (nTests<=1){
        cout<<"Do you really need this for less than 2 tests?"<<endl;
        cout<<"Grade a few more tests for the best results."<<endl<<endl;
    }
    }while (nTests<=1);
    
    int *array=new int [nTests];//array for test grades with user defined SIZE
    
    //Fill array
    cout<<"Enter the grades one by one"<<endl;
    cout<<"---------------------------"<<endl;
    for (int i=0;i<=nTests-1;i++){
        cin>>array[i];
    }
    cout<<endl;
    //Process/Calculations Here
    mrkSort(array,nTests);
    avg1=testAvg(array,nTests); 
    avg2=lwstDrp(array,nTests); 
    median=testMed(array,nTests); 
    mode=testMod(array,nTests);  
    
    //Output Located Here
    cout<<fixed<<setprecision(2);
    cout<<"List of all "<<nTests<<" Scores from Lowest to Highest"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (int i=0;i<=nTests-1;i++){
        cout<<array[i]<<" ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl<<"Average score                     = "<<avg1<<" points"<<endl;
    cout<<"Average with lowest grade dropped = "<<avg2<<" points"<<endl;
    cout<<"Median Score                      = "<<median<<" points"<<endl;
    cout<<"Mode                              = "<<mode<<endl;
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
    float sum=0.0f,avrg=0.0f;   //Sum of all scores
    for (int i=0;i<=n-1;i++){   //Average of the scores
        sum+=a[i];              //Solve for sum
    }
    avrg=sum/n;
    return avrg;
}
float lwstDrp(int *a, int n){
    float   sum=0.0f,           //Sum of all scores
            avrg=0.0f;          //Average of the scores
    for (int i=1;i<=n-1;i++){   //Solve for sum
        sum+=a[i];
    }
    avrg=sum/(n-1);             
    return avrg;
}
float testMed(int *a, int n){
    float m;
    if (n%2!=0){                //If odd divide n by 2
        m=a[n/2];
    }
    else if (n%2==0){           //If even average between the two
        m=(a[n/2]+a[(n/2-1)])/2.0f;
    }
    return m;
}
int testMod(int *a, int n){
    int     count=1,            //Counter
            max=0,              //Maximum times a number appears
            mode=*a;            //Keep count of which score came out most
    for (int i=0;i<=n-1;i++){
        if (a[i]==a[i+1]){
            count++;
            if (count>max){
                max=count;
                mode=a[i];
            }
        }else 
            count=1;
    }
    if (max==0){
        mode=-1;
    }
    return mode;
}