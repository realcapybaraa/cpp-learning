#include <cstdlib>  // Header for functions like rand() and srand()
#include <ctime>  // Header providing time functions used to seed the random generator
#include <iostream>
using namespace std;

int main()
{
        int choice, roundScore = 0, totalScore = 0;
        srand(time(0));  // Seeds the random number generator with the current time
        // for unique numbers each run

        do
        {
                // Menu validation loop with ASCII UI
                do
                {
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
                        cout << "| YOUR CHOICE: ";
                        cin >> choice;
                        cout << "+----------------------------------------+ \n\n";

                        // Check for input failures (letters instead of numbers) with ASCII
                        // UI
                        if (cin.fail())
                        {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "+----------------------------------------+ \n";
                                cout << "| Invalid input! Please enter a number.  | \n";
                                cout << "| Press Enter to continue...             | \n";
                                cout << "+----------------------------------------+ \n";
                                cin.get();   // Wait for the user to press Enter
                                continue;
                        }
                        //check for input failers(numbers)
                        if (choice < 1 || choice > 3) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                cout << "+----------------------------------------+ \n";
                                cout << "| Enter the number from menu only!       | \n";
                                cout << "| Press Enter to continue...             | \n";
                                cout << "+----------------------------------------+ \n";
                                cin.get();   // Wait for the user to press Enter
                                continue;
                        }
                } while (choice < 1 || choice > 3);

                // further operation on the basis of users selection
                switch (choice)
                {
                case 1:
                {
                        int random = rand() % 50 + 1;  // Generates a pseudo-random integer value.
                        // Formula: random = rand() % maxm + minm.
                        int attempt = 10, count = 1, num;
                        int remainAttempt, diffPoint = 10;

                        while (attempt > 0)
                        {
                                cout << "+----------------------------------------+ \n";
                                cout << "|                                        | \n";
                                cout << "|              EASY MODE                 | \n";
                                cout << "|                                        | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Maximum attempt: 10  Maximum score: 100| \n";
                                cout << "|                                        | \n";
                                cout << "| Guess the number betweeen 1 and 50     | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Enter your guess: ";
                                cin >> num;
                                cout << "+----------------------------------------+ \n\n";

                                // Check for input failures (letters instead of numbers)
                                if (std::cin.fail())
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid input! Please enter a number.  | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }

                                // compare between user guessed number and computer
                                // generated random number
                                if (num < 1)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 50.| \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else if (num > 50)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 50.|\n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else
                                {
                                        if (num > random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO HIGH! Try lower.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else if (num < random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO LOW! Try higher.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|               YOU WON!                 | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|           CONGRATULATIONS!             | \n";
                                                cout << "| You guessed the number in " << count << " attempts.  | \n";
                                                cout << "|                                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                // score for each round game
                                                remainAttempt = attempt;
                                                roundScore = remainAttempt * diffPoint;
                                                attempt--;
                                                cout << "| Round score: " << roundScore << "                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                cin.get();  // Wait for the user to press Enter
                                                break;
                                        }
                                }
                                // limited attempt
                                if (attempt == 0)
                                {
                                        cout << "+----------------------------------------+ \n";
                                        cout << "|               YOU LOSE!                | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| The correct number was " << random << ".             | \n";
                                        // score for each round game
                                        remainAttempt = attempt;
                                        roundScore = remainAttempt * diffPoint;
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Round score: " << roundScore << "                        | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        break;
                                }
                        }
                        break;
                }
                case 2:
                {
                        int random = rand() % 100 + 1;  // Generates a pseudo-random integer value.
                        // Formula: random = rand() % maxm + minm.
                        int attempt = 10, count = 1, num;
                        int remainAttempt, diffPoint = 20;

                        while (attempt > 0)
                        {
                                cout << "+----------------------------------------+ \n";
                                cout << "|                                        | \n";
                                cout << "|              MEDIUM MODE               | \n";
                                cout << "|                                        | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Maximum attempt: 10  Maximum score: 200| \n";
                                cout << "|                                        | \n";
                                cout << "| Guess the number betweeen 1 and 100    | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Enter your guess: ";
                                cin >> num;
                                cout << "+----------------------------------------+ \n\n";

                                // Check for input failures (letters instead of numbers)
                                if (std::cin.fail())
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid input! Please enter a number.  | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }

                                // compare between user guessed number and computer
                                // generated random number
                                if (num < 1)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 100| \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else if (num > 100)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 100|\n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else
                                {
                                        if (num > random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO HIGH! Try lower.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else if (num < random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO LOW! Try higher.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|               YOU WON!                 | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|           CONGRATULATIONS!             | \n";
                                                cout << "| You guessed the number in " << count << " attempts.  | \n";
                                                cout << "|                                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                // score for each round game
                                                remainAttempt = attempt;
                                                roundScore = remainAttempt * diffPoint;
                                                attempt--;
                                                cout << "| Round score: " << roundScore << "                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                cin.get();  // Wait for the user to press Enter
                                                break;
                                        }
                                }
                                // limited attempt
                                if (attempt == 0)
                                {
                                        cout << "+----------------------------------------+ \n";
                                        cout << "|               YOU LOSE!                | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| The correct number was " << random << ".             | \n";
                                        // score for each round game
                                        remainAttempt = attempt;
                                        roundScore = remainAttempt * diffPoint;
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Round score: " << roundScore << "                        | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        break;
                                }
                        }
                        break;
                }
                case 3:
                {
                        int random = rand() % 100 + 1;  // Generates a pseudo-random integer value.
                        // Formula: random = rand() % maxm + minm.
                        int attempt = 6, count = 1, num;
                        int remainAttempt, diffPoint = 50;

                        while (attempt > 0)
                        {
                                cout << "+----------------------------------------+ \n";
                                cout << "|                                        | \n";
                                cout << "|              HARD MODE                 | \n";
                                cout << "|                                        | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Maximum attempt: 6  Maximum score: 300 | \n";
                                cout << "|                                        | \n";
                                cout << "| Guess the number betweeen 1 and 100    | \n";
                                cout << "+----------------------------------------+ \n";
                                cout << "| Enter your guess: ";
                                cin >> num;
                                cout << "+----------------------------------------+ \n\n";

                                // Check for input failures (letters instead of numbers)
                                if (std::cin.fail())
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid input! Please enter a number.  | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }

                                // compare between user guessed number and computer
                                // generated random number
                                if (num < 1)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 100| \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else if (num > 100)
                                {
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Invalid number! enter between 1 and 100|\n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        continue;
                                }
                                else
                                {
                                        if (num > random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO HIGH! Try lower.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else if (num < random)
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+" << " \n";
                                                cout << "| TOO LOW! Try higher.                   | \n";
                                                cout << "|                                        | \n";
                                                // remaining attempt
                                                attempt--;
                                                cout << "| Attempts remaining: " << attempt << "                  | \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                count++;
                                                cin.get();  // Wait for the user to press Enter
                                                //continue;
                                        }
                                        else
                                        {
                                                std::cin.clear();
                                                std::cin.ignore(10000, '\n');
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|               YOU WON!                 | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "|           CONGRATULATIONS!             | \n";
                                                cout << "| You guessed the number in " << count << " attempts.  | \n";
                                                cout << "|                                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                // score for each round game
                                                remainAttempt = attempt;
                                                roundScore = remainAttempt * diffPoint;
                                                attempt--;
                                                cout << "| Round score: " << roundScore << "                        | \n";
                                                cout << "+----------------------------------------+ \n";
                                                cout << "| Press Enter to continue...             | \n";
                                                cout << "+----------------------------------------+ \n\n";
                                                cin.get();  // Wait for the user to press Enter
                                                break;
                                        }
                                }
                                // limited attempt
                                if (attempt == 0)
                                {
                                        cout << "+----------------------------------------+ \n";
                                        cout << "|               YOU LOSE!                | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| The correct number was " << random << ".             | \n";
                                        // score for each round game
                                        remainAttempt = attempt;
                                        roundScore = remainAttempt * diffPoint;
                                        cout << "+----------------------------------------+ \n";
                                        cout << "| Round score: " << roundScore << "                        | \n";
                                        cout << "| Press Enter to continue...             | \n";
                                        cout << "+----------------------------------------+ \n";
                                        cin.get();  // Wait for the user to press Enter
                                        std::cin.clear();
                                        std::cin.ignore(10000, '\n');
                                        break;
                                }
                        }
                        break;
                }
                default:
                {
                        cout << "| Enter a valid number from the menu above! \n";
                        break;
                }
                }

                // replay message loop
                do
                {
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
                                choice = 2;  // assigning value to choice that makes condition
                                // true so that loop runs again
                                continue;
                        }
                        else if (choice < 0 || choice > 1)
                        {
                                cout << "| Enter either 1 or 0!                    | \n\n";
                        }
                } while (choice != 1 && choice != 0);

                // total score
                totalScore += roundScore;

        } while (choice != 0);

        //printing total score
        cout << "+----------------------------------------+ \n";
        cout << "| Total score: " << totalScore << "                       | \n";
        cout << "+----------------------------------------+ \n";


        return 0;
}