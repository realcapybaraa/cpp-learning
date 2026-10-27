#include <iostream>
#include <string>

int main(){

    //learning if-else 
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if(age >= 18){
        std::cout << "You are eligible for license. \n";
    }else
        std::cout << "Sorry! You are not eligible for license. \n";

    //A code to find greater among two numbers
    float a, b;
    std::cout << "Enter any two numbers: ";
    std::cin >> a >> b;
    
    if(a > b){
        std::cout << a << " is greater. \n";
    }else{
        std::cout << b << " is greater. \n";
    }

    //learning if ladder(independent)
    float balance, weight, height;
    std::cout << "enter your weight(in kg) , height(in foot) and bank balance:";
    std::cin >> weight >> height >> balance;

    if(weight > 100){
        std::cout << "You are over fat. \n";
    }
    if(height > 5){
        std::cout << "You have good height. \n";
    }
    if(balance > 10000000){
        std::cout << "You are rich. \n";
    }

    //learning else-if ladder(dependent)
    std::string flavor;
    std::cout << "Enter a Ice cream flavor: ";
    std::cin.ignore();//to clear the leftover newline from the previous cin
    std::getline(std::cin, flavor);

    if(flavor == "strawberry"){
        std::cout << "Order this Ice cream. \n";
    }else if(flavor == "vanilla"){
        std::cout << "Order this Ice cream. \n";
    }else{
        std::cout << "I dont need the Ice cream. \n";
    }

    return 0;
}