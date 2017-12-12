/* 
 * File:   main.cpp
 * Author: Adrian Lopez
 * Created on Dec 11, 2017, 10:43 AM
 * Purpose: Project 2
 */

//System Libraries Here
#include <iostream> //input - output Library
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


//User Libraries Here
#include "Game.h"
#include "Rules.h"
#include "Guess.h"

//Global Constants Only, No Global Variable
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
template <class T>T C(T c){
    cout<<"Welcome to Chutes and Ladders 2.0"<<endl;
    cout<<"What would you like to do?"<<endl;
    cout<<"[1] Play a game."<<endl;
    cout<<"[2] Look at the Rules for Chutes and Ladders."<<endl;
    cout<<"Enter anything else to exit the program"<<endl;
    cin>>c;
    return c;
    
}
template <class T>T B(T c){
    cout<<"Welcome to Chutes and Ladders 2.0"<<endl;
    cout<<"What would you like to do?"<<endl;
    cout<<"[1] Play Chutes and ladders."<<endl;
    cout<<"[2] Play Guessing game."<<endl;
    cout<<"[3] Look at the Rules for Chutes and Ladders."<<endl;
    cout<<"[4] See the previous winner for Chutes and Ladders."<<endl;
    cout<<"Enter anything else to return to the Main Menu"<<endl;
    cin>>c;
    return c;
    
}
template<class T>T D(T c){
    c=rand()%6+1;
    return c;
}
void play();
void playGuess();
void winners();
void rules();
void playGame();
void writeWin();
Guess guessNum(Guess);
Game turns(Game *,const int);
Game roll(Game *,const int);
Game position(Game *,const int ,const int);
Game slideClimb(Game *,const int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare all Variables Here
    int choice=0;
    
    //Input or initialize values Here
    do{
        choice=C(choice);
        cout<<endl<<endl;
        switch (choice){
            case 1:{
                play();
                break;
            }
            case 2:{
                rules();break;
            }
            default:{cout<<"Bye, Bye"<<endl;break;}
        }
    }while(choice>=1&&choice<=2);
    
    //Process/Calculations Here
    
    //Output Located Here
    cout<<"Thanks for Playing!"<<endl;
    
    //Exit
   return 0;
}
void play(){
    //Declare Variables
    int choice;
    //Display menu
    do{
        choice=B(choice);
        cout<<endl<<endl;
        switch (choice){
            case 1:{
                playGame();
                break;
            }
            case 2:{
                playGuess();
                break;
            }
            case 3:{
                rules();break;
            }
            case 4:{
                winners();break;
            }
            default:{cout<<"Entering Main Menu"<<endl<<endl;break;}
        }
    }while(choice>=1&&choice<=4);
}
void playGuess(){
    //Declare variables
    char choice;
    
    //Loop guessing game
    do{
        Guess guess;
        cout<<"I have a number between 1 and 10^"<<guess.getX()<<"."<<endl;
        cout<<"Can you guess my number? You will"<<endl;
        cout<<"be given a maximum of log2(10^x)+1"<<endl;
        cout<<"guesses. That's "<<guess.getNGuess()<<" guesses."<<endl;
        guessNum(guess);
        cout<<"Would you like to play again? y/n"<<endl;
        cin>>choice;
    }while (choice=='y'||choice=='Y');

}
Guess guessNum(Guess guess){
    //Declare Variables
    int g=0;
    
    //Loop guesses
    for (int i=guess.getNGuess();i>=0;i--){
        if (i==0){
            cout<<"You've used up all your guesses."<<endl;
            cout<<"The number i chose was "<<guess.getNum()<<endl;
            break;
        }
        cout<<"Type in your guess."<<endl;
        cin>>g;
        if (g==guess.getNum()){
            cout<<"Congratulations! You got it."<<endl<<endl;
            break;
        }
        if (g>guess.getNum()){
            cout<<"Too high. Try again."<<endl<<endl;
        }
        if (g<guess.getNum()){
            cout<<"Too low. Try again"<<endl<<endl;
        }
    }

}
void writeWin(){
    //Declare Variables
    string name;
    cout<<"Enter your name"<<endl;
    cin>>name;
    //Open binary file
    fstream file("winners.bin",ios::in | ios::out | ios::binary);
    if(!file.is_open()){
        cout<<"Error File not Open"<<endl;
        exit(1);
    }
    //Write to binary file
    file.write(reinterpret_cast<char *>(&name),sizeof(name));
    //Close File
    file.close();
    cout<<endl<<endl;
}
void winners(){
    //Declare Variables
    streampos size;
    char name[50];
    //Open file
    fstream file("winners.bin",ios::in | ios::binary );
    if(!file.is_open()){
        cout<<"Error File not Open"<<endl;
        exit(1);
    }

    file.read(reinterpret_cast<char *>(&name),50);
    cout<<name<<endl;
    //Close File
    file.close();
}
void rules(){
    //Declare variables
    ifstream inFile;
    inFile.open("rules.txt");
    if (inFile.fail()){
        cerr<<"Error Opening File"<<endl;
        exit(1);
    }
    //Display rules
    string text;    //words found in text
    int count=0;    //counter for words
    cout<<"Rules"<<endl;
    cout<<"_____"<<endl;
    
    //loop words displayed
    while (getline(inFile,text)){
        cout<<text<<endl;
        count++;
        //end line after 12 words

    }
    
    //close file
    inFile.close();
    cout<<endl<<endl;
    
}
void playGame(){
    //Declare Variables
    int n=0;        //number of players
    
    //Get number of Players
    do{
        cout<<"This game is played with at least 1 player"<<endl;
        cout<<"and at most 4"<<endl;
        cout<<"Enter the number of players"<<endl;
        cin>>n;
        
        //ensure that n>0&&n<=4 via exception
        try{
            if(n<0||n>4){
                throw 1;
            }
        }catch(int x){
            cout<<"Invalid number of players, Error Code "<<x<<endl<<endl;
        }
        
    }while(n<0||n>4);
    
    //Polymorphism
    Numbr e;
    Numero s;
    Game *num1 = &e;
    Game *num2 = &s;
    num1->setNPlay(n);
    num2->setNPlay(n);
    cout<<"The number of players is "<<e.getNum()<<endl;
    cout<<"Again, the number of players is "<<s.getNum()<<endl<<endl;
    //create players object array
    Game *g=new Game[n-1];
    for(int i=0;i<n;i++){
        int temp=0;
        g[i].setPos(temp);
        g[i].setNum();
    }
    turns(g,n);
    writeWin();
    delete[]g;
}
Game turns(Game *g,const int n){
    //Declare variables
    bool winner=false;
    int     i=0,
            choice=0;
    
    //Start loop to see what each player will do
    do{
        do{
            cout<<endl<<"Player "<<i+1<<endl;
            cout<<"What would you like to do?"<<endl;
            cout<<"[1] Roll die"<<endl;
            cout<<"[2] Look at the board"<<endl;
            cout<<"[3] Look at the rules again"<<endl;
            cout<<"[4] Quit the current game"<<endl;
            cin>>choice;
            cout<<endl<<endl;
            switch (choice){
                
                case 1:{
                    //roll die for turn
                    roll(g,i);
                    break;
                }
                case 2:{
                    //see board
                    int     row=9,
                            col=9;
                    //create board
                    vector< vector<int> > v={{100,99,98,97,96,95,94,93,92,91},
                                             {81,82,83,84,85,86,87,88,89,90},
                                             {80,79,78,77,76,75,74,73,72,71},
                                             {61,62,63,64,65,66,67,68,69,70},
                                             {60,59,58,57,56,55,54,53,52,51},
                                             {41,42,43,44,45,46,47,48,49,50},
                                             {40,39,38,37,36,35,34,33,32,31},
                                             {21,22,23,24,25,26,27,28,29,30},
                                             {20,19,18,17,16,15,14,13,12,11},
                                             {1,2,3,4,5,6,7,8,9}};
                    //stl
                    v[9].push_back(10);
                    //Display board with player positions
                    cout<<"Number of Players = "<<Game::num<<endl;
                    cout<<"Player "<<i+1<<"'s position = "<<g[i].getPos()<<endl;
                    cout<<"____________________________"<<endl;
                    for(int r=0;r<=row;r++){
                        for(int c=0;c<=col;c++){
                            if(v[r][c]==g[i].getPos()){
                                if(g[i].getPos()<=10){
                                    cout<<"~ ";
                                }
                                else{
                                    cout<<"~  ";
                                }
                            }
                            else{
                                if (v[r][c]<=10){
                                    cout<<v[r][c]<<"  ";
                                }
                                else {
                                    cout<<v[r][c]<<" ";
                                }
                            }
                        }
                        cout<<endl;
                    }
                    cout<<endl<<endl;
                    break;
                }
                case 3:{
                    //Display rules using inheritance
                    Rules txt;
                    txt.rules();
                    break;
                }
                case 4:{
                    cout<<"Quitting game."<<endl;
                    delete []g;
                    exit(0);
                }
                default :{
                    break;
                }
                
            }
        }while(choice!=1);
        
        //Check to see if game is won
        if(n>=1){
            if (g[0].getPos()==100){
                winner=true;
                cout<<"Congratulations Player "<<1<<"."<<endl;
                cout<<"You win!"<<endl;
            }
        }
        if(n>=2){
            if (g[1].getPos()==100){
                winner=true;
                cout<<"Congratulations Player "<<2<<"."<<endl;
                cout<<"You win!"<<endl;
            }
        }
        if(n>=3){
            if (g[2].getPos()==100){
                winner=true;
                cout<<"Congratulations Player "<<3<<"."<<endl;
                cout<<"You win!"<<endl;
            }
        }
        if(n>=4){
            if (g[3].getPos()==100){
                winner=true;
                cout<<"Congratulations Player "<<4<<"."<<endl;
                cout<<"You win!"<<endl;
            }
        }
        
        i++;
        if(i==n){
            i=0;
        }
        //exit loop when winner is found
    }while(winner!=true);
}
Game roll(Game *g, const int i){
    //Declare variables
    int die=0;
    
    //Roll die
    die=D(die);
    cout<<"You Rolled a "<<die<<endl;
    
    //get new position
    position(g,i,die);
    
}
Game position(Game *g,const int i,const int d){
    //Declare variables
    int pos=g[i].getPos();
    
    //Change position based on die
    pos=pos+d;
    
    //Last row check
    if (pos>100){
        int temp;
        temp=pos-100;
        pos=100;
        pos=pos-temp;
    }
    
    g[i].setPos(pos);
    cout<<"Your new position = "<<g[i].getPos()<<endl;
    slideClimb(g,i);
    
    //check for event
}
Game slideClimb(Game *g,const int i){
    //Declare variables
    int pos=0;
    
    //Climb up ladders
    if(g[i].getPos()==1||g[i].getPos()==4||g[i].getPos()==9||
            g[i].getPos()==21||g[i].getPos()==28||g[i].getPos()==36||
            g[i].getPos()==51||g[i].getPos()==71||g[i].getPos()==80){
        
        if(g[i].getPos()==1){
            cout<<"You landed on a ladder"<<endl;
            pos=38;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==4){
            cout<<"You landed on a ladder"<<endl;
            pos=14;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==9){
            cout<<"You landed on a ladder"<<endl;
            pos=31;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==21){
            cout<<"You landed on a ladder"<<endl;
            pos=42;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==28){
            cout<<"You landed on a ladder"<<endl;
            pos=84;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==36){
            cout<<"You landed on a ladder"<<endl;
            pos=44;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==51){
            cout<<"You landed on a ladder"<<endl;
            pos=67;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==71){
            cout<<"You landed on a ladder"<<endl;
            pos=91;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==80){
            cout<<"You landed on a ladder"<<endl;
            pos=100;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
    }
    //Slide down chutes
    else if(g[i].getPos()==16||g[i].getPos()==48||g[i].getPos()==49||
            g[i].getPos()==56||g[i].getPos()==62||g[i].getPos()==64||
            g[i].getPos()==87||g[i].getPos()==93||g[i].getPos()==95||
            g[i].getPos()==98){
        if(g[i].getPos()==16){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=6;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==48){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=26;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==49){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=11;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==56){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=53;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==62){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=19;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==64){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=60;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==87){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=24;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==93){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=73;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==95){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=75;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
        else if (g[i].getPos()==98){
            cout<<"You landed on a chute in space "<<g[i].getPos()<<endl;
            pos=78;
            g[i].setPos(pos);
            cout<<"Your new position = "<<g[i].getPos()<<endl;
        }
    }
    
}
