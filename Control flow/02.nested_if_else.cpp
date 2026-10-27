#include <iostream>

int main(){

     //learning nested if-else
     //A code to find greated among three numbers
    float a, b, c;
    std::cout << "Enter any three numbers: ";
    std::cin >> a >> b >> c;

    if(a > b){
        if(a > c){
            std::cout << a << " is the greatest. \n";
        }else{
            std::cout << c << " is the greatest. \n";
        }
    }else{
        if(b > c){
            std::cout << b << " is the greatest. \n";
        }else{
            std::cout << c << " is the greatest. \n";
        }
    }

    //A code to check whether inputed year is leap year or not
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;

    if(year % 100 == 0){
        if(year % 400 == 0){
            std::cout << year << " is a leap year. \n";
        }else{
            std::cout << year << " is not a leap year. \n";
        }
    }
    else{
        if(year % 4 == 0){
            std::cout << year << " is a leap year. \n";
        }else{
            std::cout << year << " is not a leap year. \n";
        }
    }

    
    return 0;
}