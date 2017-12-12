/* 
 * File:   TestScores.h
 * Author: Adrian Lopez
 *
 * Created on December 3, 2017, 12:50 PM
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores {
public:
    TestScores();
    void setScores(int);
    float setAvg();
    float getAvg(){
        return avg;
    }

private:
    int nTests;     //Number of tests
    int *grades;    //Grades to be entered
    float avg;      //Average of the scores entered
};

#endif /* TESTSCORES_H */

