#include<iostream>
using namespace std;
#include <ctime>    // For time()


// Assume you are developing a program to simulate a game where players take turns to guess a
// number between 1 and 100. The program generates a random number between 1 and 100 at
// the start of the game, and the player who guesses the correct number wins the game. If a player
// guesses incorrectly, the program tells them whether their guess was too high or too low, and
// the turn passes to the next player. Solve it using Direct Recursion?

void game(int target, int player)
{
    int guess; 

    if (player == 1){
        cout<<"player 1: ";
        cin>>guess;

        if (guess == target){
            cout<<"player 1 wins!";
            return;
        }
        else{
            if (guess < target)
                cout<<"Guess is low"<<endl;
            else{
                cout<<"Guess is high"<<endl;
            }
            return game(target,2);
        }
    }

    if (player == 2){
        cout<<"player 2: ";
        cin>>guess;

        if (guess == target){
            cout<<"player 2 wins!";
            return;
        }
        else{
            if (guess < target)
                cout<<"Guess is low"<<endl;
            else{
                cout<<"Guess is high"<<endl;
            }
            return game(target, 1);
        }
    }

    
}


int main()
{
    srand(time(0));
    int max = 100; int min = 1;
    int target = (rand() % (max - min + 1)) + min;

    game(target,1);
    return 0;
}