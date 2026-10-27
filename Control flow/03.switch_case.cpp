#include <iostream>

int main(){

    int day;
    std::cout << "Enter a number between 1 and 7: ";
    std::cin >> day;

    /*Note: each case should be unique and constant(int, char) not floating points. Break stops the swtich there. If break is not used then it will keep going to next cases, which ika "fall through"*/
    switch(day){

        case 1: std::cout << "Sunday\n";
        //break; here, switch fall through from case1 to case2.
        case 2: std::cout << "Monday\n";
        break;
        case 3: std::cout << "Tuesday\n";
        break;
        case 4: std::cout << "Wednesday\n";
        break;
        case 5: std::cout << "Thursday\n";
        break;
        case 6: std::cout << "Firday\n";
        break;
        case 7: std::cout << "Satuarday\n";
        break;
        default: std::cout << "Enter a valid number. \n";
        break;

    }

    //learning ternary operator
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    (n % 2 == 0)? std::cout << "Even \n": std::cout << "odd \n";//condition? truecase: falsecase;

    std::cout << ((n % 2 == 0)? "Even \n": "odd \n");//ternary operator inside cout

return 0;
}