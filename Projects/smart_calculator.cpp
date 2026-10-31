#include <iostream>

int main(){

    int choice;

    do{
        //printing full ASCII UI
        std::cout << "+----------------------------------------+ \n";
        std::cout << "|                                        | \n";
        std::cout << "|           SMART CALCULATOR             | \n";
        std::cout << "|             version 2.0                | \n";
        std::cout << "|                                        | \n";
        std::cout << "+----------------------------------------+ \n";
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
        std::cout << "|   Enter your choice: ";
        std::cin >> choice;
        std::cout << "+----------------------------------------+ \n";

        // Check for input failures (letters instead of numbers)
        if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input! Please enter a number.\n";
        continue;
        }

        switch(choice){
            case 1: {//Addition
                float n1, n2, sum = 0;
                std::cout << "|   Enter the numbers: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";
                sum = n1 + n2;

                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Sum = " << sum << "                              | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 2: {//Subtraction
                float n1, n2, diff = 0;
                std::cout << "|   Enter the numbers: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";
                diff = n1 - n2;
               
                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Difference = " << diff << "                              | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 3: {//Multiplication
                float n1, n2, product;
                std::cout << "|   Enter the numbers: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";
                product = n1 * n2;
             
                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Product = " << product << "                              | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 4: {//Division
                float n1, n2, division;
                std::cout << "|   Enter the numbers: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";

                //check if denominator is zero
                if(n2 == 0){
                    std::cout << "+----------------------------------------+ \n";
                    std::cout << "|   Enter denominator except 0, Thank you| \n";
                    std::cout << "|                                        | \n";
                    std::cout << "|   Press Enter to continue...           | \n";
                    std::cout << "+----------------------------------------+ \n";

                    // Pause the screen so the user can read the result before the menu redraws
                    std::cin.ignore(10000, '\n'); // Clear any leftover input
                    std::cin.get();// Wait for the user to press Enter
                }else{
                division = n1 / n2;
                
                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Division = " << division << "                   | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                }
                break;
            }
            case 5: {//Remainder
                int n1, n2, rem;
                std::cout << "|   Enter the numbers: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";

                //check if denominator is zero
                if(n2 == 0){
                    std::cout << "+----------------------------------------+ \n";
                    std::cout << "|   Enter denominator except 0, Thank you| \n";
                    std::cout << "|                                        | \n";
                    std::cout << "|   Press Enter to continue...           | \n";
                    std::cout << "+----------------------------------------+ \n";

                    // Pause the screen so the user can read the result before the menu redraws
                    std::cin.ignore(10000, '\n'); // Clear any leftover input
                    std::cin.get();// Wait for the user to press Enter
                }else{
                rem = n1 % n2;
                
                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Remainder = " << rem << "                        | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                }
                break;
            }
            case 6: {//Percentage
                float n1, n2, percentValue;
                std::cout << "|   Enter X percent of Y: ";
                std::cin >> n1 >> n2;
                std::cout << "+----------------------------------------+ \n\n";
                percentValue = (n1 * n2) / 100;

                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   " << n1 << "% of " << n2 << " is: " << percentValue << "                    | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 7: {//Discount
                float originalPrice, finalPrice, discPercent, discAmount;
                std::cout << "|   Enter the original price and discount percent: ";
                std::cin >> originalPrice >> discPercent;
                std::cout << "+----------------------------------------+ \n\n";
                discAmount = (discPercent * originalPrice) / 100;
                finalPrice = originalPrice - discAmount;

                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Discount amt: " << discAmount << "   Final price: " << finalPrice << " | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 8: {//Tax
                float originalPrice, finalPrice, taxPercent, taxAmount;
                std::cout << "|   Enter the price and tax percentage: ";
                std::cin >> originalPrice >> taxPercent;
                std::cout << "+----------------------------------------+ \n\n";
                taxAmount = (originalPrice * taxPercent) / 100;
                finalPrice = originalPrice + taxAmount;

                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Tax amt: " << taxAmount << "   Final price: " << finalPrice << "     | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
            case 9: {//Simple Interest
                float p, r, t, simpleInterest, totalAmount;
                std::cout << "|   Enter the principal, rate and time in years: ";
                std::cin >> p >> r >> t;
                std::cout << "+----------------------------------------+ \n\n";

                //check if years is in negative
                if(t < 0){
                    std::cout << "Sorry! Years cannot be negative \n";
                }else{
                simpleInterest = (p * t * r) / 100;
                totalAmount = p + simpleInterest;

                //Result panel ASCII box
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|              RESULT PANEL              | \n";
                std::cout << "+----------------------------------------+ \n";
                std::cout << "|   Simple Interest: " << simpleInterest << " Total Price: " << totalAmount << " | \n";
                std::cout << "|                                        | \n";
                std::cout << "|   Press Enter to continue...           | \n";
                std::cout << "+----------------------------------------+ \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                }
                break;
            }
            case 0: {//Exit
                std::cout << "Exiting calculator... \n\n";
                break;
            }
            default: {
                std::cout << "Enter the valid choice from the menu above! \n";
                std::cout << "Press Enter to continue... \n";

                // Pause the screen so the user can read the result before the menu redraws
                std::cin.ignore(10000, '\n'); // Clear any leftover input
                std::cin.get();// Wait for the user to press Enter
                break;
            }
        }
    }while(choice != 0);
 return 0;
}