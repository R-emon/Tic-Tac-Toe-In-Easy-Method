// Tic Tac Toe Game build in simpliest logic.
// BY [Rabiul Islam Emon].

#include <iostream>
#include <stdlib.h>
#include <dos.h>     // Necessary Header Files.
#include <windows.h>
#include <ctype.h>
#include "color.h"  // color.h user defined header file where all the micros are defined for colors.
using namespace std;

int winCheck(char num[],int length,char choise_For_First_Player,char choise_For_Second_Player,string name1,string name2);
bool checkEntry(char ch[], int length, int x);
void printStructure(char num[],int length);    // All function calls.
void startGame(string name1, string name2);
int printOptions(string name1,string name2);
int exitGame();

int main()
{
    string name1,name2;
    system("Color 0");  // from windows.h background color is set to black as {0-> Black}
    cout<<MAG<<"     "<<"~~~~Welcome To Tic Tac Toe Game~~~\n" RESET<<endl; // MAG is used for color and RESET used to reset the color.
    cout<<YEL<<"     "<<"Enter player1 name." RESET<<endl;                  // after printing the string.
    cout<<"     ";                                                          // same as all used in other cout.
    cin>>name1;
    cout<<BLU<<"     "<<"Enter player2 name." RESET<<endl;                     // Welcome part of the game.
    cout<<"     ";
    cin>>name2;
    cout<<"\n"<<GRN<<"     "<<"Welcome "<<name1<<" and "<<name2<<" to the game...!" RESET<<endl;
    printOptions(name1,name2);  // function call to print all the option from printOption() function.
                                // Both player names (name1 and name2) are passed in the function.
    return 0;
}
void printStructure(char num[],int length){ // structure of the tic tac toe game this is how it will look.

    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;
    cout<<CYN<<"     "<<"   "<<RED<<num[0]<< RESET<<CYN<<"   |    "<<RED<<num[1]<< RESET<<CYN<<"    |   "<<RED<<num[2]<< RESET<<endl;
    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;
    cout<<CYN<<"     "<<" ----------------------- " RESET<<endl;
    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;
    cout<<CYN<<"     "<<"   "<<RED<<num[3]<< RESET<<CYN<<"   |    "<<RED<<num[4]<< RESET<<CYN<<"    |   "<<RED<<num[5]<< RESET<<endl;
    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;
    cout<<CYN<<"     "<<" ----------------------- " RESET<<endl;
    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;
    cout<<CYN<<"     "<<"   "<<RED<<num[6]<< RESET<<CYN<<"   |    "<<RED<<num[7]<< RESET<<CYN<<"    |   "<<RED<<num[8]<< RESET<<endl;
    cout<<CYN<<"     "<<"       |         |       " RESET<<endl;

}
void startGame(string name1, string name2){            // startGame() function operate the whole game.
    char num[9]={'1','2','3','4','5','6','7','8','9'}; //char array to store all the moves as X and O. Previously defined by [1-9].
    cout<<GRN<<"\n      Starting The Game.... \n" RESET<<endl;
    printStructure(num,9);                                     // function to print structure of the game. the num array is and it's size is passed.
    char choise_For_First_Player,choise_For_Second_Player; // Two char type variable to store choice of two players.
    while(true){                                           // while infinite loop until user input correct sign.
        cout<<"\n"<<YEL<<"     "<<name1<<" Select Your Sign [X/O]:" RESET<<" ";
        cin>>choise_For_First_Player;
        if((choise_For_First_Player=='x') | (choise_For_First_Player=='X') | (choise_For_First_Player=='o') // checking either user only input [X or O].
           | (choise_For_First_Player=='O')) break; //if user inputs only X or O break it will break the loop.
        else{
            cout<<RED<<"     "<<"Wrong Input PLease select [X/O]..." RESET<<endl; // else print error message and continue the loop.
            continue;
        }
    }
    while(true){                                    //while loop same as for second player
        cout<<"\n"<<BLU<<"     "<<name2<<" Select Your Sign [X/O]:" RESET<<" ";
        cin>>choise_For_Second_Player;
        if((choise_For_First_Player=='x') | (choise_For_First_Player=='X') && (choise_For_Second_Player=='x') // checking if 2nd players input is same sign [X] that is taken by 1st player
           | (choise_For_Second_Player=='X')){
            cout<<RED<<"     "<<"[X] sign is already taken..."<<endl;      // if true then throwing a error message and continuing the to loop take input again.
            cout<<"     "<<"Please select [O]..." RESET<<endl;
                continue;
        }
        else if((choise_For_First_Player=='o') | (choise_For_First_Player=='O') && (choise_For_Second_Player=='o') //// checking if 2nd players input is same sign [O] that is taken by 1st player
           | (choise_For_Second_Player=='O')){
               cout<<RED<<"     "<<"[O] sign is already taken..."<<endl;   // if true then throwing a error message and continuing the loop to take input again.
            cout<<"     "<<"Please select [X]..." RESET<<endl;
                continue;
           }
        else if((choise_For_Second_Player=='x') | (choise_For_Second_Player=='X') | (choise_For_Second_Player=='o') // This part of conditon checks weather user only [X or O].
           | (choise_For_Second_Player=='O')) break;
        else{
            cout<<RED<<"     "<<"Wrong Input PLease select [X/O]..." RESET<<endl; //else throw a error message.
            continue;
        }
    }
    if(islower(choise_For_First_Player)!=0){ // checking if player1 inputs the character in lowercase.
        choise_For_First_Player=toupper(choise_For_First_Player); // converts to uppercase.
        cout<<"\n"<<YEL<<"     "<<"Player["<<name1<<"]"<<" Assigned To: "<<choise_For_First_Player<< RESET<<endl;
    }
    else // else if it is already in upper case then just prints the message.
        cout<<"\n"<<BLU<<"     "<<"Player["<<name1<<"]"<<" Assigned To: "<<choise_For_First_Player<< RESET<<endl;
    if(islower(choise_For_Second_Player)!=0){ // checking if player2 inputs the character in lowercase.
        choise_For_Second_Player=toupper(choise_For_Second_Player);
        cout<<BLU<<"     "<<"Player["<<name2<<"]"<<" Assigned To: "<<choise_For_Second_Player<< RESET<<endl;
    }
    else // else if it is already in upper case then just prints the message.
        cout<<"\n"<<BLU<<"     "<<"Player["<<name2<<"]"<<" Assigned To: "<<choise_For_Second_Player<< RESET<<endl;

    cout<<"\n"<<GRN<<"     "<<"Please wait for 5sec it's loading.....!" RESET<<endl;

    Sleep(5000);   //let the console stay sleep for 5 second.
    system("CLS"); // clear everything int the console.

    printStructure(num,9); // prints the structure of tic tac toe.
    int c=0; // variable to store the loop count for 9 moves in the game.

    while(1){ // infinite while loop until the game ends.

    int q=1;  // variable to store return value from winCheck()function.
    int assignTo_1=0,assignTo_2=0; // variables to store user input for their moves.

    while(true){ // infinite while loop for first player input until right move.

    cout<<YEL<<"     "<<"Player1 enter your preferred position[1-9]:" RESET<<" ";
    cin>>assignTo_1;
    bool entryX=checkEntry(num,9,assignTo_1); // function to check for right available move is given by user.
    if(entryX==true) break;                   // if true break
    else if(entryX==false) continue;          //else continue until right move.
    }
    if(choise_For_First_Player=='X')          // checking for X sign is taken by player1
        num[assignTo_1-1]='X';                // if true then assign X in that position given by player 1.
    else
        num[assignTo_1-1]='O';                //else do same for sign O.
    system("CLS");
    printStructure(num,9);
    q=winCheck(num,9,choise_For_First_Player,choise_For_Second_Player,name1,name2); //winCheck function to check weather player wins or loose after taking a move.
    if(q==0) break;     // if player wins the function returns 0 and break then game.
    if(c==4){           //if the loop continues for 4 times then all the 9 moves are complete at this line.
        cout<<RED<<"     "<<"Its a tie...!" RESET<<endl; // the it's a tie.
        printOptions(name1,name2);
        break;
    }
    // Same as player 1.
    while(true){

    cout<<BLU<<"     "<<"Player2 enter your preferred position[1-9]:" RESET<<" ";
    cin>>assignTo_2;
    bool entryY=checkEntry(num,9,assignTo_2);
    if(entryY==true) break;
    else if(entryY==false) continue;
    }
    if(choise_For_Second_Player=='X')
        num[assignTo_2-1]='X';
    else
        num[assignTo_2-1]='O';
    system("CLS");
    printStructure(num,9);
    q=winCheck(num,9,choise_For_First_Player,choise_For_Second_Player,name1,name2);
    if(q==0) break;

    c++; // iterating c by 1.
    }
}
// function to exit from the game.
int exitGame(){
    cout<<RED<<"     "<<"Exiting The Game....!" RESET<<endl;
    Sleep(2000);
    return 0;
}
// function to print all the options.
// and taking the choice from the user.
int printOptions(string name1,string name2){
    int opt;
    while(true){
        cout<<MAG<<"     "<<"[1]. Start The Game."<<endl;
        cout<<"     "<<"[2]. Play again."<<endl;
        cout<<"     "<<"[3]. Stop The Game"<<endl;
        cout<<"\n     "<<"Choose Your Option:" RESET;
        cin>>opt;
        if((opt==1) | (opt==2) | (opt==3)) break; //checking either user inputs among 1-3.
        else{   // else prints error message.
            system("CLS");
            cout<<RED<<"     "<<"Wrong input please try again [1/2/3]...\n" RESET<<endl;
            continue;
        }

    }

    switch(opt){ //switch case for the options.
    case 1:
        startGame(name1,name2);
        break;
    case 2:
        system("CLS");
        startGame(name1,name2);
        break;
    case 3:
        exitGame();
        break;
    }
    return 0;
}
//win check function to check if a player won the game.
// here 8 win possibilities are checked for player 1 and player 1
// checking by index like num[0],num[1],num[2] are same character or not.
//as   x | x | x
//    -----------
//       |   |
//    -----------
//       |   |
// so on for other 7 possibilities for X and O.
int winCheck(char num[],int lenght,char choise_For_First_Player, char choise_For_Second_Player,string name1,string name2){
    //For X
    if(num[0]=='X' && num[1]=='X' && num[2]=='X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[3]=='X' && num[4]=='X' && num[5]=='X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[6]=='X' && num[7]=='X' && num[8]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[0]=='X' && num[3]=='X' && num[6]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[1]=='X' && num[4]=='X' && num[7]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[2]=='X' && num[5]=='X' && num[8]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[0]=='X' && num[4]=='X' && num[8]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[2]=='X' && num[4]=='X' && num[6]== 'X'){
        if(choise_For_First_Player=='X'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    //For O
    else if(num[0]=='O' && num[1]=='O' && num[3]=='O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[3]=='O' && num[4]=='O' && num[5]=='O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[6]=='O' && num[7]=='O' && num[8]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[0]=='O' && num[3]=='O' && num[6]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[1]=='O' && num[4]=='O' && num[7]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[2]=='O' && num[5]=='O' && num[8]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[0]=='O' && num[4]=='O' && num[8]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }
    else if(num[2]=='O' && num[4]=='O' && num[6]== 'O'){
        if(choise_For_First_Player=='O'){
            cout<<GRN<<"     "<<name1<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
        else{
            cout<<GRN<<"     "<<name2<<" Won Congratulations....\n" RESET<<endl;
            printOptions(name1,name2);
            return 0;
        }
    }

    return 1;
}
// boolean function to check either user has input among [1 to 9].
bool checkEntry(char ch[], int length, int x){
        if((x==1) && (ch[0]=='1')){
            return true;
        }

        else if((x==2) && (ch[1]=='2')){
            return true;
        }
        else if((x==3) && (ch[2]=='3')){
            return true;
        }
        else if((x==4) && (ch[3]=='4')){
            return true;
        }
        else if((x==5) && (ch[4]=='5')){
            return true;
        }
        else if((x==6) && (ch[5]=='6')){
            return true;
        }
        else if((x==7) && (ch[6]=='7')){
            return true;
        }
        else if((x==8) && (ch[7]=='8')){
            return true;
        }else if((x==9) && (ch[8]=='9')){
            return true;
        }
        else{
            cout<<RED<<"     "<<"Wrong Move Error!..." RESET<<endl;
            return false;
        }

    }
//                                END OF CODE
//                                   Thanks
