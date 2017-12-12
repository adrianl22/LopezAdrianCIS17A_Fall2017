/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Oct 12, 2017, 4:28 PM
 * Purpose:
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Formatting
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int wordCnt(char [],int);
float avgWord(char [],int );

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=100;
    char input[SIZE];
    int nChar=0,j=0;
    float avg=0.0f;
    
    //Input or initialize values Here
    cout<<"Type in a sentence within 100 characters to see how"
            " many words you typed."<<endl;
    cout<<"Don't forget to end your sentence with a '.', '!' or '?'."<<endl;
    cout<<"For the best result of course."<<endl<<endl;
    cin.getline(input,SIZE);
    nChar=wordCnt(input,SIZE);
    avg=avgWord(input,SIZE);
    //Process/Calculations Here
    cout<<fixed<<setprecision(0);
    cout<<"Number of word(s)       = "<<nChar<<endl;
    cout<<"Avg letters per word    ≈ "<<avg<<endl;
    cout<<input[78];
    
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
float avgWord(char a[],int b){
    float count=0,n=0.0f,m=0.0f;
    float avg=0.0f;
    for(int i=0;i<=b;i++){
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
            n++;
        }
        if (a[i]==' '||a[i]=='.'||a[i]=='!'||a[i]=='?'){
            count++;
            if(a[i]=='.'||a[i]=='!'||a[i]=='?')break;
        }
        
    }
    avg=n/count;
    cout<<"Number of letter(s)     = "<<n<<endl;
    return avg;
}