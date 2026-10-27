#include <iostream>

int main(){

    //A code to check whether a number is odd or even
    int n1;
    std::cout << "Enter a number: ";
    std::cin >> n1;

    if(n1 % 2 == 0){
        std::cout << n1 << " is even. \n";
    }else
        std::cout << n1 << " is odd. \n";

    //A code to check whether a number is +ve or -ve or zero
    int n2;
    std::cout << "Enter a number: ";
    std::cin >> n2;

    if(n2 < 0){
        std::cout << " Negative integer. \n";
    }else if(n2 > 0){
        std::cout << " Positive integer. \n";
    }else{
        std::cout << " It is Zero. \n";
    }

    //A code to apply discounts and print final amount based on inputed purchase amount
    float purAmount, discount, finAmount;
    std::cout << "Enter the purchase amount: ";
    std::cin >> purAmount;

    if(purAmount >= 0 && purAmount <= 5000){
        discount = 0;
        finAmount = purAmount * ((100 - discount) / 100);
    }
    if(purAmount >= 5001 && purAmount <= 7000){
        discount = 5;
        finAmount = purAmount * ((100 - discount) / 100);
    }
    if(purAmount >= 7001 && purAmount <= 9000){
        discount = 10;
        finAmount = purAmount * ((100 - discount) / 100);
    }
    if(purAmount >= 9001){
        discount = 20;
        finAmount = purAmount * ((100 - discount) / 100);
    }
    std::cout << "Final amount = " << finAmount << '\n';

    //A code to create electricity bill based on the no.of units consumed
    float unit, uAmount, totalAmount = 0;
    std::cout << "Enter the consumed units: ";
    std::cin >> unit;

    if(unit > 400){
        unit -= 400;
        uAmount = unit * 13;
        totalAmount += uAmount;
        unit = 400;
    }
    if(unit >= 201 && unit <= 400){
        unit -= 200;
        uAmount = unit * 8;
        totalAmount += uAmount;
        unit = 200;
    }
    if(unit >= 101 && unit <= 200){
        unit -= 100;
        uAmount = unit * 6;
        totalAmount += uAmount;
        unit = 100;
    }
    if(unit >= 0 && unit <= 100){
        uAmount = unit * 4.2;
        totalAmount += uAmount;
    }
    std::cout << "Total amount: " << totalAmount << '\n';

    //A code to check whether inputed character is vowel or consonant(using switch)
    char ch;
    std::cout << "Enter an alphabet(small letter) from keyboard: ";
    std::cin >> ch;

    switch(ch){

        case 'a': {
            std::cout << ch << " is a vowel. \n";
            break;
        }
        case 'e': {
            std::cout << ch << " is a vowel. \n";
            break;
        }
        case 'i': {
            std::cout << ch << " is a vowel. \n";
            break;
        }
        case 'o': {
            std::cout << ch << " is a vowel. \n";
            break;
        }
        case 'u': {
            std::cout << ch << " is a vowel. \n";
            break;
        }
        default: {
            std::cout << ch << " is a consonant. \n";
            break;
        }
    }

    return 0;
}