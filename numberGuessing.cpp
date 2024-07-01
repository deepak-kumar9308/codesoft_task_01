//gussing a number between 1 to 100....
//made by Deepak kr
//date: 06-06-2024

#include <iostream>        
#include <cstdlib>          
#include <ctime>             

using namespace std;


 // Generate & return a random number between 1 and 100.
int guessNumber() {
    int num;
    num = rand() % 100 + 1;
    return num;
}

/*
  Checking the remaining chances and prints appropriate messages.
  And returning true or false on basis of condition
 */
bool check(int ch) {
    if (ch > 0) {
        cout << "\nOops, you have only " << ch << " chances left.\n";
        return true;
    } else {
        cout << "\nOh no! You lost.\n";
        return false;
    }
}

//main fuction 

int main() { 
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0))); 
    
    int guess, randomNum, chance = 10;
    bool fort;
    
    // Introduction to the game
    cout << ".................WELCOME TO THE NUMBER GUESSING GAME..................\n";
    cout << "GUESS A NUMBER FROM 1 TO 100:\n";
    
    // Generate the random number by calling guessNumber function
    randomNum = guessNumber();
    
    // Game loop
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the guess is correct
        if (guess == randomNum) {
            cout << "CONGRATULATIONS! YOU GUESSED IT....!! THE RANDOM NUMBER WAS " << randomNum << ".\n";
            break;
        } 
        // Give hints if the guess is wrong
        else if (guess < randomNum) {  
            chance--;
            fort = check(chance);
            if (fort == false) {
                break;
            }
            cout << "HINT: YOUR GUESS WAS TOO SMALL, PLEASE TRY AGAIN!\n";
        } 
        else {
            chance--;
            fort = check(chance);
            if (fort == false) {
                break;
            } 
            cout << "HINT: YOUR GUESS WAS TOO BIG, PLEASE TRY AGAIN!\n";
        }
    }  
    
    // End of the game
    cout << "Thank you for playing the Number Guessing Game!\n";
    return 0;
}