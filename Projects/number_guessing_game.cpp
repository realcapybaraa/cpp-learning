#include <cstdlib>  // Header for functions like rand() and srand()
#include <ctime>  // Header providing time functions used to seed the random generator
#include <iostream>
using namespace std;

//declaring functions
void showWelcomeScreen();
int chooseDifficulty();
void showModeScreen(int difficulty);
int getMaxNumber(int difficulty);
int generateSecretNumber(int maxNumber);
int getMaxAttempts(int difficulty);
int getScoreMultiplier(int difficulty);
void pauseScreen();
int getValidGuess(int maxNumber);
int getRoundScore(int attempt, int scorePoint);
void tooHighMessage(int attempt);
void tooLowMessage(int attempt);
void youWonMessage(int count);
void youLoseMessage(int secretNumber);
bool playAgain();
int playRound(int difficulty);
int main()
{
        bool decision;
        int choice, roundScore, totalScore = 0;
        srand(time(0));  // Seeds the random number generator with the current time for unique numbers each run

        do
        {
                choice = chooseDifficulty();

                // further operation on the basis of users selection
                roundScore = playRound(choice);

                decision = playAgain();
                // total score
                totalScore += roundScore;

        } while (decision);

        //printing total score
        cout << "+----------------------------------------+ \n";
        cout << "| Total score: " << totalScore << "                       | \n";
        cout << "+----------------------------------------+ \n";


        return 0;
}
//defining showWelcomeScreen() function
void showWelcomeScreen() {
        cout << "+----------------------------------------+ \n";
        cout << "|                                        | \n";
        cout << "|          NUMBER GUESSING GAME          | \n";
        cout << "|                                        | \n";
        cout << "+----------------------------------------+ \n";
        cout << "|                                        | \n";
        cout << "|             WELCOME, PLAYER            | \n";
        cout << "| Try your luck and challenge your mind. | \n";
        cout << "|                                        | \n";
        cout << "+----------------------------------------+ \n";
        cout << "|                                        | \n";
        cout << "| SELECT DIFICULLTY                      | \n";
        cout << "|                                        | \n";
        cout << "| [1] EASY                               | \n";
        cout << "| [2] MEDIUM                             | \n";
        cout << "| [3] HARD                               | \n";
        cout << "|                                        | \n";
        cout << "+----------------------------------------+ \n";
}
//defining chooseDifficulty function
int chooseDifficulty() {
        int choice;
        bool isValid;
        do {
                isValid = true;
                showWelcomeScreen();
                cout << "| ENTER YOUR CHOICE: ";
                cin >> choice;
                cout << "+----------------------------------------+ \n\n";

                // Check for input failures (letters instead of numbers) with ASCII UI
                if (cin.fail())
                {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "+----------------------------------------+ \n";
                        cout << "| Invalid input! Please enter a number.  | \n";
                        isValid = false;
                        pauseScreen();
                }
                else {//check for input failers(numbers)
                        if (choice < 1 || choice > 3) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "+----------------------------------------+ \n";
                                cout << "| Enter the number from menu only!       | \n";
                                isValid = false;
                                pauseScreen();
                        }
                }
        } while (!isValid);
        return choice;
}
//defining roundPlay() function
int playRound(int difficulty) {
        int roundScore = 0;
        int maxNumber = getMaxNumber(difficulty);
        int secretNumber = generateSecretNumber(maxNumber);
        int attempt = getMaxAttempts(difficulty);
        int scorePoint = getScoreMultiplier(difficulty);
        int count = 1;

        while (attempt > 0)
        {
                showModeScreen(difficulty);
                int guess = getValidGuess(maxNumber);

                if (guess > secretNumber)
                {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        attempt--;
                        tooHighMessage(attempt);
                        pauseScreen();
                        count++;

                }
                else if (guess < secretNumber)
                {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        attempt--;
                        tooLowMessage(attempt);
                        pauseScreen();
                        count++;

                }
                else
                {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        youWonMessage(count);
                        roundScore = getRoundScore(attempt, scorePoint);
                        pauseScreen();
                        break;
                }

                // limited attempt
                if (attempt == 0)
                {
                        youLoseMessage(secretNumber);
                        roundScore = getRoundScore(attempt, scorePoint);
                        pauseScreen();
                        break;
                }
        }
        return roundScore;
}
//defining showModeScreen() function
void showModeScreen(int difficulty) {
        if (difficulty == 1) {
                cout << "+----------------------------------------+ \n";
                cout << "|                                        | \n";
                cout << "|              EASY MODE                 | \n";
                cout << "|                                        | \n";
                cout << "+----------------------------------------+ \n";
                cout << "| Maximum attempt: 10  Maximum score: 100| \n";
                cout << "|                                        | \n";
                cout << "| Guess the number betweeen 1 and 50     | \n";
                cout << "+----------------------------------------+ \n";
        }
        else if (difficulty == 2) {
                cout << "+----------------------------------------+ \n";
                cout << "|                                        | \n";
                cout << "|              MEDIUM MODE               | \n";
                cout << "|                                        | \n";
                cout << "+----------------------------------------+ \n";
                cout << "| Maximum attempt: 10  Maximum score: 200| \n";
                cout << "|                                        | \n";
                cout << "| Guess the number betweeen 1 and 100    | \n";
                cout << "+----------------------------------------+ \n";
        }
        else {
                cout << "+----------------------------------------+ \n";
                cout << "|                                        | \n";
                cout << "|              HARD MODE                 | \n";
                cout << "|                                        | \n";
                cout << "+----------------------------------------+ \n";
                cout << "| Maximum attempt: 6  Maximum score: 300 | \n";
                cout << "|                                        | \n";
                cout << "| Guess the number betweeen 1 and 100    | \n";
                cout << "+----------------------------------------+ \n";
        }
}
//defining getMaxNumber() function
int getMaxNumber(int difficulty) {
        if (difficulty == 1) {
                return 50;
        }
        else if (difficulty == 2) {
                return 100;
        }
        else {
                return 100;
        }
}
//defining generateSecretNumber() function
int generateSecretNumber(int maxNumber) {
        return rand() % maxNumber + 1;
}
//defining getMaxAttempts() function
int getMaxAttempts(int difficulty) {
        if (difficulty == 1 || difficulty == 2) {
                return 10;
        }
        else {
                return 6;
        }
}
//defining getScoreMultiplier() function
int getScoreMultiplier(int difficulty) {
        if (difficulty == 1) {
                return 10;
        }
        else if (difficulty == 2) {
                return 20;
        }
        else {
                return 50;
        }
}
//defining pauseScreen() function
void pauseScreen() {
        cout << "| Press Enter to continue...             | \n";
        cout << "+----------------------------------------+ \n";
        cin.get();   // Wait for the user to press Enter
}
//defining getValidGuess() function
int getValidGuess(int maxNumber) {
        int guess;
        bool isValid;

        do {
                isValid = true;
                cout << "| Enter your guess: ";
                cin >> guess;
                cout << "+----------------------------------------+ \n\n";

                // Check for input failures (letters instead of numbers)
                if (std::cin.fail())
                {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        cout << "+----------------------------------------+ \n";
                        cout << "| Invalid input! Please enter a number.  | \n";
                        isValid = false;
                        pauseScreen();
                        continue;
                }
                else {
                        // compare between user guessed number and computer generated random number
                        if (guess < 1 || guess > maxNumber)
                        {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                cout << "+----------------------------------------+ \n";
                                cout << "| Invalid number! enter between 1 and " << maxNumber << ".  | \n";
                                isValid = false;
                                pauseScreen();
                                continue;
                        }
                }
        } while (!isValid);
        return guess;
}
//defining getRoundScore() function
int getRoundScore(int attempt, int scorePoint) {
        // score for each round game
        int roundScore = attempt * scorePoint;
        cout << "| Round score: " << roundScore << "                        | \n";
        cout << "+----------------------------------------+ \n";
        return roundScore;
}
//defining playAgain() function
bool playAgain() {
        int choice;
        bool isValid;
        // replay message loop
        do
        {
                isValid = true;
                cout << "+----------------------------------------+ \n";
                cout << "| PLAY AGAIN?                            | \n";
                cout << "| [1] Yes  [0] No                        | \n";
                cout << "+----------------------------------------+ \n";
                cout << "| Enter your choice: ";
                cin >> choice;
                cout << "+----------------------------------------+ \n\n";

                // Check for input failures (letters instead of numbers)
                if (std::cin.fail())
                {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "| Invalid input! Please enter a number.  | \n";
                        isValid = false;
                        continue;
                }
                else {
                        if (choice < 0 || choice > 1) {
                                cout << "Enter either 1 or 0. \n";
                                isValid = false;
                        }
                }
        } while (!isValid);
        //suppose user inputs valid descision
        if (choice == 1) {
                return true;
        }
        else {
                return false;
        }
}
//defining TooHighMessage() function
void tooHighMessage(int attempt) {
        cout << "+----------------------------------------+" << " \n";
        cout << "| TOO HIGH! Try lower.                   | \n";
        cout << "|                                        | \n";
        cout << "| Attempts remaining: " << attempt << "                  | \n";
}
//defining TooLowMessage() function
void tooLowMessage(int attempt) {
        cout << "+----------------------------------------+" << " \n";
        cout << "| TOO LOW! Try higher.                   | \n";
        cout << "|                                        | \n";
        cout << "| Attempts remaining: " << attempt << "                  | \n";
}
//defining YouWonMessage() fucntion
void youWonMessage(int count) {
        cout << "+----------------------------------------+ \n";
        cout << "|               YOU WON!                 | \n";
        cout << "+----------------------------------------+ \n";
        cout << "|           CONGRATULATIONS!             | \n";
        cout << "| You guessed the number in " << count << " attempts.  | \n";
        cout << "|                                        | \n";
        cout << "+----------------------------------------+ \n";
}
//defining YouLoseMessage() function
void youLoseMessage(int secretNumber) {
        cout << "+----------------------------------------+ \n";
        cout << "|               YOU LOSE!                | \n";
        cout << "+----------------------------------------+ \n";
        cout << "| The correct number was " << secretNumber << ".             | \n";
}