/**
 creates a memory matching game letting the user pick a theme, and the level of difficulty.
 Checks for wrong input from the user and gives feedback; keeps track of matched cards and moves.
 @author Ricardo Colin on 12/20/17
 @version 1.0
 Copyright © 2017 Ricardo Colin. All rights reserved.
 */
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;


class MemoryMatchGame{
private:
    //creates all variables for future use
    int MainRows, MainCols, randomCards, row1, col1, row2, col2, themeNumber;
    int cardsMatched = 0, moves = 0, loop1 = 0, loop2 = 0;
    char comma;
    string theme;
    string cards[32];
    string doubleCards[64];
    bool validAnswer = false, sameCard = false;
    bool gameover = false;
    bool cardstatus[4][4];
    string matrix [4][4];
    string states[50] = { "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH", "OK", "OR","PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
    string animals[50] = { "Ant", "Ape", "Donkey", "Baboon", "Penguin", "Bat", "Bear", "Beaver", "Bee", "Bison",
        "Boar", "Buffalo", "Camel", "Cat", "Cheetah", "Chicken", "Chough", "Clam", "Cobra", "Coyote",
        "Crab", "Crow", "Deer", "Dinosaur", "Dog", "Dolphin", "Dove", "Duck", "Eagle", "Gorilla",
        "Elephant","Elk","Emu","Falcon","Ferret","Fish","Fly","Fox","Frog","Gazelle",
        "Giraffe", "Gnu", "Goat", "Goose", "Guanaco", "Hamster", "Hawk", "Horse", "Human", "Eel"};
    //change this with auto brands, did this as example
    string carBrands[50] = { "Ant", "Ape", "Donkey", "Baboon", "Penguin", "Bat", "Bear", "Beaver", "Bee", "Bison", "Boar", "Buffalo", "Camel", "Cat", "Cheetah", "Chicken", "Chough", "Clam", "Cobra", "Coyote", "Crab", "Crow", "Deer", "Dinosaur", "Dog", "Dolphin", "Dove", "Duck", "Eagle", "Gorilla", "Elephant","Elk","Emu","Falcon","Ferret","Fish","Fly","Fox","Frog","Gazelle", "Giraffe", "Gnu", "Goat", "Goose", "Guanaco", "Hamster", "Hawk", "Horse", "Human", "Eel"};


public:
    MemoryMatchGame(){
        start();
    }

    /** Displays the level menu and gets the chosen size
     @return  The grid size. */
    int difficulty()
    {
        string ch;
        int gridsize = 0;

        //add spaces
        for (int s = 0; s < 2; ++s){
            cout<<endl;
        }
        while(gridsize == 0){
            cout << "Type E for easy grid: 4x4" <<endl;
            cout << "Type M for moderate grid: 6x6" <<endl;
            cout << "Type D for difficult grid: 8x8" <<endl;
            cout << "\nInput: ";
            cin >> ch;


            if (ch == "e" || ch=="E")
            {
                gridsize = 4;

            }
            else if (ch=="m" || ch=="M")
            {
                gridsize = 6;
            }
            else if (ch =="d" || ch =="D")
            {
                gridsize = 8;
            }
            else {
                cout<<"\nWrong Input! Try Again!\n" <<endl;
                gridsize = 0;
            }
        }
        return gridsize;
    }

    /** Displays the theme menu and gets the chosen theme
     @return  the chosen theme. */
    int themeChoice(){
        cout << "WELCOME TO THE MATCHING GAME!!\n"<<endl;
        cout << "    SELECT A THEME\n" <<endl;
        cout << "1. Animals"<<endl;
        cout << "2. States"<<endl;
        cout << "3. Car Brands"<<endl;
        cout << "\nEnter your choice (1,2,3): ";


        while(!(cin >> themeNumber) || themeNumber > 3 || themeNumber < 1){
            if (!cin){
                cout << "\nWrong Format! Please enter a number from 1 to 3: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if( themeNumber > 3){
                cout << "\nNumber too Big! Please enter a number from 1 to 3: " << endl;
            }
            else{
                cout << "\nNumber too Small! Please enter a number from 1 to 3: " << endl;
            }
        }
        return themeNumber;
    }

    /** Starts the game and calls the previous functions.
     @return  The grid size. */
    void start(){
        themeChoice();

        srand((unsigned)time(NULL));
        MainRows = difficulty();
        MainCols = MainRows;
        randomCards = ((MainRows*MainCols)/2);


        //pick ramdon cards array
        for (int r=0; r < randomCards; ++r){
            if (themeNumber == 1){
                cards[r] = animals[rand()%49];

            }else if (themeNumber == 2){
                cards[r] = states[rand()%49];
            }else{
                cards[r] = carBrands[rand()%49];
            }


            //check random cards
            //cout<<cards[r] + " ";
        }
        //cout<<"\n" <<endl;

        //double cards in the first array
        for (int d=0; d < randomCards*2; ++d){
            doubleCards[d] = cards[loop1];
            //test doubling cards
            //cout<<doubleCards[d] + " ";
            ++loop1;
            if(loop1 >= randomCards){
                loop1 = 0;
            }
        }


        //shuffle cards
        for (int i=0; i< randomCards*2; i++) {
            int r = rand() % randomCards*2;  // generate a random position
            string temp = doubleCards[i];
            doubleCards[i] = doubleCards[r];
            doubleCards[r] = temp;
            //check shuffle cards
            //cout<<doubleCards[i] + " ";
        }
        cout<<"\n" <<endl;

        //assign values to 2d array
        for (int rr=0; rr< MainRows; ++rr){

            for(int cc=0; cc < MainCols; ++cc){

                matrix[rr][cc] = doubleCards[loop2];
                //check double array cards
                //cout << matrix[rr][cc] + "\t\t";

                ++loop2;
            }
            //cout <<endl;

        }

        //cout<<"\n"<<endl;

        displaycards();

    }


    /** This fuction creates a displayable grid and keeps track of all matched cards and moves*/

    void displaycards(){
        /*
         //space between blocks
         for( int i=0; i< 2; i++)
         {
         cout<<endl;
         }
         */

        cout <<"     ";
        for(int co = 0; co < MainCols; ++co){
            cout<<co+1 << "\t\t";
        }
        cout<<endl;
        cout<<"   ";
        for(int co = 1; co < MainCols; ++co){
            cout<< "___________";
        }
        cout<<endl;
        for( int r=0; r<MainRows; r++){

            cout<<r+1<<" |\t";

            for( int c=0; c<MainCols; c++){


                cout<< "*\t\t";
                cardstatus[r][c] = false;
            }

            // cout <<  << "\t";
            cout<<endl;
        }
        cout<< "\nCards Matched: "<< cardsMatched <<" Moves: "<< moves << "\n"<<endl;


        do // game starts from here as user will do moves here onwards.
        {
            do
            {

                //selection
                cout<<"Please insert the FIRST card row and column separated by a comma.(Example: 1,1)\n";
                cout << "Input: ";

                while(!(cin >> row1>>comma>>col1) || row1 > MainRows || row1 < 1 ||col1 > MainCols || col1 < 1){
                    if (!cin){
                        cout << "\nPlease enter the answer in the right format. (Example: 1,1)" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else{
                        cout<<"\nPlease enter a value that grid. Try Again! (Example: 1,1)"<<endl;

                    }
                }



                if(cardstatus[row1-1][col1-1] == true) // check if the card is flipped.
                {
                    cout << "\nThis card is already flipped! Select another card.\n"<<endl;
                }



            }while(cardstatus[row1-1][col1-1]!= false);

            do
            {
                cout<<"\nPlease insert the SECOND card row and column separated by a comma.(Example: 2,2) \n";
                cout << "Input: ";

                while(!(cin >> row2>>comma>>col2) || row2 > MainRows || row2 < 1 ||col2 > MainCols || col2 < 1){
                    if (!cin){
                        cout << "\nPlease enter the answer in the right format. (Example: 2,2)" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else{
                        cout<<"\nPlease enter a value that exist in the grid. Try Again! (Example: 2,2)"<<endl;

                    }
                }

                sameCard = false;
                if(cardstatus[row2-1][col2-1] == true) // check if the card is flipped.
                {
                    cout << "This card is already flipped! Select another card.\n\n";
                    sameCard = true;
                }

                if((row1==row2)&&(col1==col2))
                {
                    cout << "\nYou can't select the same card twice!\n";
                    sameCard = true;

                }
            }while(cardstatus[row2-1][col2-1]!= false || sameCard == true);
            moves++; // counting moves here.
            //fix
            row1--;
            col1--;
            row2--;
            col2--;
            //reveal

            if (matrix[row1][col1] == matrix[row2][col2]) //if cards match, add 1 to matchedcards
            {
                ++cardsMatched;
            }

            cout<<"\n\n\n\n";
            cout <<"     ";
            for(int co = 0; co < MainCols; ++co){
                cout<<co+1 << "\t\t";
            }
            cout<<endl;
            cout<<"   ";
            for(int co = 1; co < MainCols; ++co){
                cout<< "___________";
            }
            cout<<endl;
            for (int r=0; r<MainRows; r++)
            {
                cout<<r+1<<" |\t";

                for (int c=0; c<MainCols; c++)
                {
                    if ((r==row1)&&(c==col1))
                    {
                        cout<< matrix[r][c]<<"\t\t";
                    }
                    else if((r==row2)&&(c==col2))
                    {
                        cout<<matrix[r][c]<<"\t\t";
                    }
                    else if (cardstatus[r][c] == true)
                    {
                        cout<<matrix[r][c]<<"\t\t";
                    }
                    else
                    {
                        cout<<"*\t\t";
                    }
                }

                cout<<endl;

            }
            cout<< "\nCards Matched: "<< cardsMatched <<" Moves: "<< moves << "\n"<<endl;

            //match?

            if (matrix[row1][col1] == matrix[row2][col2]) // if cards match, keep them flipped.
            {
                cout << "\nCards Matched!"<<endl;

                cardstatus[row1][col1] = true;
                cardstatus[row2][col2] = true;



            }else{
                cout<<"Cards did not matched!"<<endl;
            }

            cout << "\nPress ENTER to keep going!"<<endl;
            cin.get();
            cin.get();

            //this pushes the next board onto a blank screen
            for (int b=0; b<=10; b++){
                cout<<endl;
            }
            cout <<"     ";
            for(int co = 0; co < MainCols; ++co){
                cout<<co+1 << "\t\t";
            }
            cout<<endl;
            cout<<"   ";
            for(int co = 1; co < MainCols; ++co){
                cout<< "___________";
            }
            cout<<endl;
            for (int r=0; r<MainRows; r++) // reprint the board, makes it easy for user to put a new guess.
            {
                cout<<r+1<<" |\t";

                for (int c=0; c<MainCols; c++)
                {
                    if (cardstatus[r][c] == true)
                    {
                        cout<<matrix[r][c]<<"\t\t";
                    }
                    else
                    {
                        cout<<"*\t\t";
                    }
                }
                cout<<endl;

            }
            cout<< "\nCards Matched: "<< cardsMatched <<" Moves: "<< moves << "\n"<<endl;
            cout<<endl;
            gameover = true;
            for (int r=0; r<4; r++) // check all card status, they all should be true/flipped to end the game.
            {
                for (int c=0; c<4; c++)
                {
                    if(cardstatus[r][c]==false)
                    {
                        gameover = false;
                        break;
                    }
                }
                if(gameover == false)
                {
                    break;
                }
            }

            //repeat
        }while(gameover != true);

    }
};


int main() {
    MemoryMatchGame  Game1;  // first line - declare instance of game
    Game1.start();                            // second line - start game
}
