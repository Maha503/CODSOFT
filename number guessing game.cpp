#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
   
    srand(time(0)); 

    int target_number = rand() % 100 + 1; 
    int userGuess;
    int no_of_chances = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

   
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        
        
         no_of_chances++;

       
        (userGuess < target_number) ? cout << "Too low! Try again." << endl :
        (userGuess > target_number) ? cout << "Too high! Try again." << endl :
        cout << "Congratulations! You've guessed the number!" << endl;

    } while (userGuess != target_number);  

    cout << "It took you " << no_of_chances << " attempts." << endl;

    return 0;
}

