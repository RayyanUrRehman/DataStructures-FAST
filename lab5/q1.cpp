#include<iostream>
using namespace std;

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
                cout<<"Guess low"<<endl;
            else{
                cout<<"Guess high"<<endl;
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
                cout<<"Guess low"<<endl;
            else{
                cout<<"Guess high"<<endl;
            }
            return game(target, 1);
        }
    }

    
}


int main()
{
    int max = 100; int min = 1;
    int target = (rand() % (max - min + 1)) + min;
    
    game(target,1);
    return 0;
}