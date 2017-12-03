/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Nov 4, 2017, 10:58 AM
 * Purpose: Project 1 CIS 17A
 *          Chutes and Ladders
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <iomanip>  //Formatting
#include <ctime>    //
#include <cstdlib>  //
using namespace std;


//User Libraries Here
#include "player.h"
//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
player postion(player,int); //Player position
player sldClmb(player);     //Slide/Climb to new position
void board(player);         //Board to show position
void game(player, int);     //Game
void rules();               //Rules for game
void scores();              //Previous game
int roll();                 //Roll die
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int     die=0,
            nPlay,
            choice;
    player info;

    //Initialize menu
    cout<<"Welcome to Chutes and Ladders!"<<endl;
    do {
        cout<<"What would you like to do?"<<endl;
        cout<<"Enter 1 to play the game."<<endl;
        cout<<"Enter 2 to view the rules."<<endl;
        cout<<"Enter 3 to view previous games."<<endl;
        cout<<"Enter anything else to exit the game."<<endl;
        cin>>choice;
        cout<<endl;
        
        switch (choice){
            case 1:{game(info,die);break;}
            case 2:{rules();break;}
            case 3:{scores();break;}
            default: break;
        }
        cout<<endl;
    }while(choice>=1&&choice<=3);

    //Process/Calculations Here

    //Output Located Here1
    

    //Exit
   return 0;
}
void rules(){
    cout<<"Goal"<<endl;
    cout<<"____"<<endl;
    cout<<"The Goal of the game is to move along the board"<<endl;
    cout<<"until you reach the 100th space, [Row:1] [Col:1]"<<endl;
    cout<<",or landing on the ladder located on the 80th space"<<endl;
    cout<<"[Row:3] [Col:1]"<<endl<<endl;
    cout<<"How"<<endl;
    cout<<"___"<<endl;
    cout<<"You reach the goal by rolling a 6 sided die."<<endl;
    cout<<"You move spaces on the board equal to amount"<<endl;
    cout<<"indicated on the die. The board moves snake-like"<<endl;
    cout<<"meaning that when you reach the end of the board"<<endl;
    cout<<"you move up a row and move in the other direction"<<endl;
    cout<<"If you are in [row: 1] and roll a number that"<<endl;
    cout<<"will put you higher than the 100th space, you"<<endl;
    cout<<"will move accordingly until you reach the 100th"<<endl;
    cout<<"space then move backwards the rest of the way"<<endl;
    cout<<"Landing on a ladder will benefit you and move you"<<endl;
    cout<<"up the board. While Chutes make you slide down."<<endl<<endl;
    cout<<"Locations of Ladders and Chutes"<<endl;
    cout<<"_______________________________"<<endl;
    cout<<"Ladders: [Row,Col] moves to [Row,Col]"<<endl;
    cout<<setw(11)<<"[3,1]  -> [1,1]"<<endl;
    cout<<setw(11)<<"[3,10] -> [1,10]"<<endl;
    cout<<setw(11)<<"[5,10] -> [4,7]"<<endl;
    cout<<setw(11)<<"[8,1]  -> [6,2]"<<endl;
    cout<<setw(11)<<"[8,8]  -> [2,4]"<<endl;
    cout<<setw(11)<<"[10,9] -> [7,10]"<<endl;
    cout<<setw(11)<<"[10,4] -> [9,7]"<<endl<<endl;
    cout<<"Chutes: [Row,Col] moves to [Row,Col]"<<endl;
    cout<<setw(11)<<"[1,3]  -> [3,2]"<<endl;
    cout<<setw(11)<<"[1,6]  -> [3,6]"<<endl;
    cout<<setw(11)<<"[1,8]  -> [3,8]"<<endl;
    cout<<setw(11)<<"[2,7]  -> [8,4]"<<endl;
    cout<<setw(11)<<"[4,4]  -> [5,1]"<<endl;
    cout<<setw(11)<<"[4,2]  -> [9,2]"<<endl;
    cout<<setw(11)<<"[5,7]  -> [7,7]"<<endl;
    cout<<setw(11)<<"[9,4]  -> [10,7]"<<endl<<endl;
}
void scores(){
    cout<<"No scores yet"<<endl;
}
void game(player info, int die){
    //Staring positions
    cin.ignore();
    cout<<"Enter your name : ";
    getline(cin,info.name);
    //Print board with starting position
    board(info);
    cout<<endl;
    //Play game until its won
    do{
        cout<<"Press enter to roll the Die"<<endl;
        cin.ignore();
        die=roll();                                //Roll die
        info=postion(info,die);                    //Change position
        board(info);                                //Show new position
        cout<<endl;
        info=sldClmb(info);                         //Check for event and change 
                                                    //position if needed

        info.turns++;                               //increase turn number
    }while(info.row!=1||info.col!=1); 
    cout<<"Congratulations you won"<<endl;
}
void board(player p){
    const int r=10;                                 //Rows
    const int c=10;                                 //Columns
    char field[c][r];                               //board array
    //Print info for board
    cout<<"Turn   : "<<p.turns<<endl;
    cout<<"Player : "<<p.name<<endl;
    cout<<"Player Position"<<endl;
    cout<<"_________________"<<endl;
    cout<<"Row    = "<<p.row<<endl;
    cout<<"Column = "<<p.col<<endl<<endl;
    //Create board
    for (int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            if (i!=0||j!=0){
                field[i][j]='□';
            }
        }
    }
    //Replace board with position
    for (int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            if (p.row==i&&p.col==j){
                field[i][j]='1';
            }
        }
    }
    //Print board with positions
    for (int i=1;i<=r;i++){
         for (int j=1;j<=c;j++){
             cout<<field[i][j]<<" ";
         }
         cout<<endl;
    }

}
int roll(){
    int num=0;
    num=rand()%6+1;
    cout<<endl<<"You rolled a "<<num<<endl<<endl;
    return num;
        
}
player sldClmb(player i){
    //ladders
    if (i.row==3&&i.col==1){
        i.row=1;
        i.col=1;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==3&&i.col==10){
        i.row=1;
        i.col=10;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==3&&i.col==1){
        i.row=1;
        i.col=1;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==5&&i.col==10){
        i.row=4;
        i.col=7;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==8&&i.col==1){
        i.row=6;
        i.col=2;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==8&&i.col==8){
        i.row=2;
        i.col=4;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==3&&i.col==1){
        i.row=1;
        i.col=1;
        cout<<"Nice, you landed on a ladder."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    //Chutes
    else if (i.row==1&&i.col==3){
        i.row=3;
        i.col=2;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==1&&i.col==6){
        i.row=3;
        i.col=6;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==1&&i.col==8){
        i.row=3;
        i.col=8;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==2&&i.col==7){
        i.row=8;
        i.col=4;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==4&&i.col==4){
        i.row=5;
        i.col=1;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==4&&i.col==2){
        i.row=9;
        i.col=2;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==5&&i.col==7){
        i.row=7;
        i.col=7;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else if (i.row==9&&i.col==4){
        i.row=10;
        i.col=7;
        cout<<"Looks like you landed on a chute."<<endl;
        cout<<"Your new position is"<<endl<<endl;
        board(i);
        cout<<endl;
        return i;
    }
    else return i;
}
player postion(player i,int d){
    //Rolling in row one
    if (i.row==1){
        i.col=i.col-d;
        //When roll lands perfectly into the [1,1] position
        if (i.col==1){
            return i;
        }
        //When roll is past [1,1] make it move reverse
        else if (i.col<1){
            i.col=(i.col-2)*-1;
            return i;
        }
        return i;
    }
    //Changing position in an even row
    if(i.row%2==0){
        i.col=i.col+d;
        //When changing rows to an odd one
        if(i.col>10){
            //decrease row number
            i.row=i.row-1;
            //Calculate position in new odd row
            if (i.row%2!=0){
                int temp;
                temp=i.col-11;
                i.col=10;
                i.col=i.col-temp;
                return i;
            }
        }
        return i;
    }
    //Changing position in an odd row
    else if (i.row%2!=0){
        i.col=i.col-d;
        //When changing rows to an even one
        if(i.col<1){
            i.row=i.row-1;
            //Calculate position in new even row
            if (i.row%2==0){
                int temp;
                temp=(i.col-11)*-1;
                i.col=temp-10;
                return i;
            }
        }
        return i;
    }
}