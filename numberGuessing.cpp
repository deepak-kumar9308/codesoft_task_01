//gussing a number between 1 to 100....
//made by Deepak kr
//date: 06-06-2024

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <limits>
#include <cmath>

using namespace std;
using namespace chrono;

int main() {
    srand(time(0));

    char playAgain = 'Y';

    cout << "=========================================\n";
    cout << "      NUMBER GUESSING GAME\n";
    cout << "=========================================\n";

    string player;
    cout << "Enter your name: ";
    getline(cin, player);

    while (playAgain == 'Y' || playAgain == 'y') {

        int choice, maxRange, chances;

        cout << "\nChoose Difficulty\n";
        cout << "1. Easy (1-50, 10 chances)\n";
        cout << "2. Medium (1-100, 8 chances)\n";
        cout << "3. Hard (1-200, 6 chances)\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                maxRange = 50;
                chances = 10;
                break;
            case 2:
                maxRange = 100;
                chances = 8;
                break;
            case 3:
                maxRange = 200;
                chances = 6;
                break;
            default:
                cout << "Invalid choice! Medium selected.\n";
                maxRange = 100;
                chances = 8;
        }

        int randomNumber = rand() % maxRange + 1;
        int guess;
        int score = 100;

        auto start = high_resolution_clock::now();

        cout << "\nGuess the number between 1 and " << maxRange << "\n";

        while (chances > 0) {

            cout << "\nEnter your guess: ";

            while (!(cin >> guess)) {
                cout << "Invalid input! Enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (guess < 1 || guess > maxRange) {
                cout << "Please enter a number between 1 and " << maxRange << ".\n";
                continue;
            }

            if (guess == randomNumber) {

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);

                cout << "\nCongratulations " << player << "!\n";
                cout << "You guessed the correct number: " << randomNumber << endl;
                cout << "Score : " << score << endl;
                cout << "Time Taken : " << duration.count() << " seconds\n";
                break;
            }

            chances--;
            score -= 10;

            int diff = abs(randomNumber - guess);

            if (guess < randomNumber)
                cout << "Too Low!\n";
            else
                cout << "Too High!\n";

            if (diff <= 5)
                cout << "🔥 Very Hot! You're extremely close.\n";
            else if (diff <= 10)
                cout << "🌡 Hot!\n";
            else if (diff <= 20)
                cout << "🙂 Warm.\n";
            else
                cout << "❄ Cold.\n";

            if (chances > 0)
                cout << "Remaining Chances: " << chances << endl;
            else {
                cout << "\nGame Over!\n";
                cout << "The correct number was: " << randomNumber << endl;
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nThanks for playing! Have a nice day.\n";

    return 0;
}
