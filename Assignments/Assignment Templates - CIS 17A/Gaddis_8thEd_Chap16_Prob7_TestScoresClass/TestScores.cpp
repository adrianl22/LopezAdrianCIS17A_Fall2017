/* 
 * File:   TestScores.cpp
 * Author: Adrian Lopez
 * 
 * Created on December 3, 2017, 12:50 PM
 */

#include "TestScores.h"

#include <iostream>
using namespace std;

TestScores::TestScores() {
    nTests=0;
    grades=0;
    avg=0.0f;
}
void TestScores::setScores(int a){
    nTests=a;
    int *scores=new int[nTests];
    cout<<"Enter the Scores for each Test [0-100 points]."<<endl;
    for (int i=0;i<=nTests-1;i++){
        cin>>scores[i];
    }
    //Test for error
    try{
        //Scores should be between [0,100]
        for(int i=0;i<=nTests-1;i++){
            //Throw error code
            if (scores[i]<0||scores[i]>100){
                throw 12;
            }
        }
    //Catch error. Terminate program if caught.
    }catch(int x){
        cout<<endl<<"Tests Score not within range, ERROR NUMBER: "<<x<<endl;
        delete []scores;
        exit(0);
    }
    grades=scores;
    delete []scores;
}
float TestScores::setAvg(){
    //Get average for scores;
    for (int i=0;i<=nTests-1;i++){
        avg=avg+grades[i];
    }
    avg=avg/(nTests);
}