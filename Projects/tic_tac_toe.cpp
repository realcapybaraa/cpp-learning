#include <iostream>
#include<string>
#include <iomanip>
#include <sstream>
//global declarations
const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';

//function prototypes
void initializeBoard();
void displayBoard();
int getPlayerMove();
void switchPlayer();
bool checkWin();
bool checkDraw();
void playGame();
bool playAgain();

int main() {

    do {
        playGame();//runs whole game round once
    } while (playAgain());

    std::cout << "Thanks for playing...\n";
    return 0;
}

//defining void initializeBoard function
void initializeBoard() {
    char cellNumber = '0' + 1;
    //filling the board cells with digits from 1-9
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cellNumber;
            cellNumber++;
        }
    }
}
//defining displayBoard function
void displayBoard() {

    //displaying board using ASCII UI and iomanip header functions
    std::cout << std::string(30, '=') << "\n";
    std::cout << std::left << std::setw(10) << " " << std::left << std::setw(20) << "TIC-TAC-TOE" << "\n";
    std::cout << std::string(30, '=') << "\n\n";

    std::cout << std::left << std::setw(7) << " " << "PLAYER " << currentPlayer << std::left << std::setw(15) << "'S TURN" << "\n\n";

    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << std::left << std::setw(5) << " " << std::left << std::setw(18) << "+-----+-----+-----" << "+\n";
        std::cout << std::left << std::setw(5) << " " << std::left << std::setw(18) << "|     |     |     " << "|\n";
        std::cout << std::left << std::setw(5) << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << "|  " << board[i][j] << "  ";
        }
        std::cout << "|\n";
        std::cout << std::left << std::setw(5) << " " << std::left << std::setw(18) << "|     |     |     " << "|\n";
    }
    std::cout << std::left << std::setw(5) << " " << std::left << std::setw(18) << "+-----+-----+-----" << "+\n\n";
    std::cout << std::string(30, '=') << "\n";
}
//defining getPlayerMove function
int getPlayerMove() {
    int positionNum;

    do {
        std::string input;
        std::cout << "Enter a position: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> positionNum) {//if extraction of integer is succeed
            std::string extra;
            if (!(ss >> extra)) {//if extra extraction fails
                if (positionNum >= 1 && positionNum <= BOARD_SIZE * BOARD_SIZE) {//check whether entered position is within allowed range
                    //convert positionNum into corresponding cells row and column indices
                    int rowIndex = (positionNum - 1) / BOARD_SIZE;
                    int colIndex = (positionNum - 1) % BOARD_SIZE;
                    //check if cell is occupied
                    if (board[rowIndex][colIndex] != 'X' && board[rowIndex][colIndex] != 'O') {
                        return positionNum;
                    }
                }
            }
        }
        //display error message if the input is invalid
        std::cout << "Invalid input! Please enter a valid number...\n";
    } while (true);
}
//defining swtichPlayer function
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}
//defining checkWin function
bool checkWin() {
    //rows checking win condition
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }
    //columns checking win condition
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    //diagonals checking win condition
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    //if winning condition not found
    return false;
}
//defining checkDraw function
bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //check whether cell is still empty
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return false;
            }
        }
    }
    return true;
}
//defining playGame function
void playGame() {

    currentPlayer = 'X';
    initializeBoard();//initializles the cellNumbers in the board
    for (int moveCount = 0; moveCount < BOARD_SIZE * BOARD_SIZE; moveCount++) {
        displayBoard();//displays the board with cellNumbers
        int positionNum = getPlayerMove();
        //convert positionNum into corresponding cells row and column indices
        int rowIndex = (positionNum - 1) / BOARD_SIZE;
        int colIndex = (positionNum - 1) % BOARD_SIZE;
        board[rowIndex][colIndex] = currentPlayer;//assign current player symbol into that cell

        //calling checkWin function that checks if any winning combination by any player is occured
        if (checkWin()) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " Won...Hurrayyy.\n";
            break;
        }
        else {
            //calling checkDraw function that only checks whether the board is full
            if (checkDraw()) {
                displayBoard();
                std::cout << "Nobody Won! It's Draw...\n";
                break;
            }
            else {
                switchPlayer();
            }
        }
    }
}
//defining playAgain function
bool playAgain() {
    char choice;

    do {
        std::string input;
        std::cout << "Play Again?(Y / N): ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> choice) {//if extraction of character is succeed
            std::string extra;
            if (!(ss >> extra)) {//if extra extraction fails
                if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {//check whether entered decision is valid
                    if (choice == 'Y' || choice == 'y') {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        //display error message if the input is invalid
        std::cout << "Invalid input! Please enter a valid character...\n";
    } while (true);
}