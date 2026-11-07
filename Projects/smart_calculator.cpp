#include <iostream>
#include <string>

//decaling functions(aka functions prototypes)
void showWelcome();
void showMenu();
int getMenuChoice();
double getValidNum(std::string prompt);
void displayResult(double result, std::string operation);
void displayTwoResults(
    std::string label1, double result1,
    std::string label2, double result2
);
void pauseScreen();
void zeroDenominator();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double division(double a, double b);
int remainder(int a, int b);
double calcPercent(double number, double percent);
double calcDiscount(double price, double discount);
double calcTax(double price, double taxPercent);
double calcSimpleInterest(double p, double t, double r);

int main() {

    int choice;

    do {

        do {

            //printing full ASCII UI
            showWelcome();
            showMenu();
            choice = getMenuChoice();
        } while (choice < 0 || choice > 9);

        switch (choice) {
        case 1: {//Addition
            double n1, n2;
            n1 = getValidNum("Enter first number: ");
            n2 = getValidNum("Enter second number: ");

            double result = add(n1, n2);
            displayResult(result, "Addition ");
            pauseScreen();
            break;
        }
        case 2: {//Subtraction
            double n1, n2;
            n1 = getValidNum("Enter first number: ");
            n2 = getValidNum("Enter second number: ");

            double result = subtract(n1, n2);
            displayResult(result, "Subtraction ");
            pauseScreen();
            break;
        }
        case 3: {//Multiplication
            double n1, n2;
            n1 = getValidNum("Enter first number: ");
            n2 = getValidNum("Enter second number: ");

            double result = multiply(n1, n2);
            displayResult(result, "Multiplication ");
            pauseScreen();
            break;
        }
        case 4: {//Division
            double n1, n2;
            n1 = getValidNum("Enter numerator: ");
            n2 = getValidNum("Enter denominator: ");

            //check if denominator is zero
            do {
                if (n2 == 0) {
                    zeroDenominator();
                    n2 = getValidNum("Enter denominator again: ");
                }
            } while (n2 == 0);

            double result = division(n1, n2);
            displayResult(result, "Division ");
            pauseScreen();
            break;
        }
        case 5: {//Remainder
            int n1, n2;
            n1 = getValidNum("Enter numerator: ");
            n2 = getValidNum("Enter denominator: ");

            //check if denominator is zero
            do {
                if (n2 == 0) {
                    zeroDenominator();
                    n2 = getValidNum("Enter denominator again: ");
                }
            } while (n2 == 0);

            double result = remainder(n1, n2);
            displayResult(result, "Remainder ");
            pauseScreen();
            break;
        }
        case 6: {//Percentage
            double number, percent;
            number = getValidNum("Enter the number: ");
            percent = getValidNum("Enter the percentage: ");

            double result = calcPercent(number, percent);
            displayResult(result, "Percentage ");
            pauseScreen();
            break;
        }
        case 7: {//Discount
            double price, discount;
            price = getValidNum("Enter the original price: ");
            discount = getValidNum("Enter the discount percentage: ");

            double discAmount = calcDiscount(price, discount);
            double finalPrice = price - discAmount;

            displayTwoResults("Discount amount: ", discAmount, "Final price: ", finalPrice);
            pauseScreen();
            break;
        }
        case 8: {//Tax
            double price, taxPercent;
            price = getValidNum("Enter the original amount: ");
            taxPercent = getValidNum("Enter the tax percentage: ");

            double taxAmount = calcTax(price, taxPercent);
            double finalPrice = price + taxAmount;

            displayTwoResults("Tax amount: ", taxAmount, "Final price: ", finalPrice);
            pauseScreen();
            break;
        }
        case 9: {//Simple Interest
            double p, t, r;
            p = getValidNum("Enter the principal: ");
            t = getValidNum("Enter the time in years: ");
            r = getValidNum("Enter the rate: ");

            //check if years is in negative
            do {
                if (t < 0) {
                    std::cout << "Sorry! Years cannot be negative. \n";
                    t = getValidNum("Enter the years in positive: ");
                }
            } while (t < 0);

            double simpleInterest = calcSimpleInterest(p, t, r);
            double totalAmount = p + simpleInterest;

            displayTwoResults("Simple interest: ", simpleInterest, "Total amount: ", totalAmount);
            pauseScreen();
            break;
        }
        case 0: {//Exit
            std::cout << "Exiting calculator... \n\n";
            break;
        }
        default: {
            std::cout << "Enter the valid choice from the menu above! \n";
            pauseScreen();
            break;
        }
        }
    } while (choice != 0);
    return 0;
}
//defining showWelcome function
void showWelcome() {
    std::cout << "+----------------------------------------+ \n";
    std::cout << "|         WELCOME TO CAPYBARA'S          | \n";
    std::cout << "|           SMART CALCULATOR             | \n";
    std::cout << "|             version 2.0                | \n";
    std::cout << "|                                        | \n";
    std::cout << "+----------------------------------------+ \n";
}
//defining showMenu function
void showMenu() {
    std::cout << "|              MAIN MENU                 | \n";
    std::cout << "+----------------------------------------+ \n";
    std::cout << "|                                        | \n";
    std::cout << "|   [1]Addition         [2]Subtraction   | \n";
    std::cout << "|   [3]Multiplication   [4]Division      | \n";
    std::cout << "|   [5]Remainder        [6]Percentage    | \n";
    std::cout << "|   [7]Discount         [8]Tax           | \n";
    std::cout << "|   [9]Simple Interest                   | \n";
    std::cout << "|                                        | \n";
    std::cout << "|   [0]Exit                              | \n";
    std::cout << "+----------------------------------------+ \n";
}
//defining getMenuChoice function
int getMenuChoice() {
    int choice;
    std::cout << "|   Enter your choice: ";
    std::cin >> choice;
    std::cout << "+----------------------------------------+ \n";

    // Check for input failures (letters instead of numbers)
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input! Please enter a number.\n";
        std::cout << "Press Enter to continue... \n";
        std::cin.get();
        return -1;
    }
    //check for input failers(numbers)
    if (choice < 0 || choice > 9) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter the number from menu only!   \n";
        std::cout << "Press Enter to continue...         \n";
        std::cin.get();

    }
    return choice;
}
//denining getValidNum function
double getValidNum(std::string prompt) {
    double num;
    bool isValid;
    do {
        isValid = true;
        std::cout << "|   " << prompt;
        std::cin >> num;
        std::cout << "+----------------------------------------+ \n\n";

        // Check for input failures (letters instead of numbers)
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            isValid = false;
        }
    } while (!isValid);
    return num;
}
//defining displayResult function
void displayResult(double result, std::string operation) {
    std::cout << "+----------------------------------------+ \n";
    std::cout << "|              RESULT PANEL              | \n";
    std::cout << "+----------------------------------------+ \n";
    std::cout << "| " << operation << "result: " << result << "                |\n";
}
//defining displayTwoResults function
void displayTwoResults(
    std::string label1, double result1,
    std::string label2, double result2
) {
    std::cout << "+----------------------------------------+ \n";
    std::cout << "|              RESULT PANEL              | \n";
    std::cout << "+----------------------------------------+ \n";
    std::cout << "| " << label1 << result1 << "\t" << label2 << result2 << "   | \n";
}
//defining pauseScreen function
void pauseScreen() {
    std::cout << "|                                        | \n";
    std::cout << "|   Press Enter to continue...           | \n";
    std::cout << "+----------------------------------------+ \n";

    // Pause the screen so the user can read the result before the menu redraws
    std::cin.ignore(10000, '\n'); // Clear any leftover input
    std::cin.get();// Wait for the user to press Enter
}
//defining zeroDenominator function
void zeroDenominator() {
    std::cout << "+----------------------------------------+ \n";
    std::cout << "|   Enter denominator except 0, Thank you| \n";
}
//defining add() function
double add(double a, double b) {
    return a + b;
}
//defining subtract function
double subtract(double a, double b) {
    return a - b;
}
//defining multiply function
double multiply(double a, double b) {
    return a * b;
}
//defining division function
double division(double a, double b) {
    return a / b;
}
//defining remainder function
int remainder(int a, int b) {
    return a % b;
}
//defining calcPercent function
double calcPercent(double number, double percent) {
    return (number * percent) / 100;
}
//defining calcDiscount function
double calcDiscount(double price, double discount) {
    return calcPercent(price, discount);
}
//defining calcTax function
double calcTax(double price, double taxPercent) {
    return calcPercent(price, taxPercent);
}
//defining calcSimpleInterest function
double calcSimpleInterest(double p, double t, double r) {
    return (p * t * r) / 100;
}