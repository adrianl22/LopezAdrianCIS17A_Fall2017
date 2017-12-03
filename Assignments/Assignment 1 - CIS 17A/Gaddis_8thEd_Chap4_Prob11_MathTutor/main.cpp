/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on March 19, 2017, 5:15 PM
 * Purpose: Math tutor
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random number generator
#include <ctime>     //Time Library to seed the random number generator

using namespace std; //Name-space under which system libraries exist

//User Libraries


//Global Constants


//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Initialize variables
    int num1, num2, ans;//Random numbers and sum of numbers
    char choice, opt;
    //Input data
    cout<<"This program is for tutoring when it comes"<<endl;
    cout<<"to addition and subtraction. Attempt the question"<<endl;
    cout<<"yourself then press 'enter' to see the correct answer."<<endl;
    //Map inputs to outputs or process the data
    do{
    cout<<"Choose Addition [+] or Subtraction [-]?"<<endl;
    cin>>choice;
    cout<<endl;
    if  (choice=='+')
    {   num1=rand()%1000+10;
        num2=rand()%500+10;
        
        ans=num1+num2;
        
        cout<<" "<<num1<<endl;
        cout<<"+"<<num2<<endl;
        cout<<"----";
        cin.get();
        cin.ignore();
        cout<<ans<<endl;}
    if  (choice=='-')
    {   num1=rand()%1000+10;
        num2=rand()%500+10;
        
        ans=num1-num2;
        
        cout<<" "<<num1<<endl;
        cout<<"-"<<num2<<endl;
        cout<<"----";
        cin.get();
        cin.ignore();
        cout<<ans<<endl;}
    cout<<endl<<"Would you like to try another problem?"<<endl;
    cout<<"[Y]es / [N]o"<<endl<<endl;
    cin>>opt;
    }while (opt=='y'||opt=='Y');
    //Output
    cout<<endl<<"You got this!"<<endl;
    //Exit stage!
    return 0;
}
