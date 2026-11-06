#include <iostream>

//Swap function definition
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "After swap: " << a << " " << b << '\n';
}
//Factor function definiton
void factor(int a) {

    std::cout << "Factors of " << a << ": ";
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            std::cout << i << ", ";
        }
    }
    std::cout << '\n';
}
//isPrime function definition
void isPrime(int a) {
    int count = 0;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            count++;
        }
    }
    if (count == 2) {
        std::cout << a << " is a prime number. \n";
    }
    else {
        std::cout << a << " is not a prime number. \n";
    }
}
//factorial function definition
int factorial(int a) {
    int factorial = 1;
    for (int i = 1; i <= a; i++) {
        factorial *= i;
    }
    return factorial;
}
//isStrong function definition
void isStrong(int a) {
    int sum = 0, copy = a;
    while (a > 0) {
        int lastDigit = a % 10;
        sum += factorial(lastDigit);//calling factorial function
        a = a / 10;
    }
    if (copy == sum) {
        std::cout << copy << " is a Strong number. \n";
    }
    else {
        std::cout << copy << " is not a Strong number. \n";
    }

}
int main() {

    int n, num;

    std::cout << "Before swap: " << 5 << " " << 10 << '\n';
    swap(5, 10);//calling swap function

    std::cout << "Enter the integral number: ";
    std::cin >> n;
    factor(n);//calling factor function

    isPrime(n);//calling isPrime function

    std::cout << "Enter the integral number: ";
    std::cin >> num;
    std::cout << "Factorial of " << num << ": " << factorial(num) << '\n';//calling factorial function

    isStrong(n);

    return 0;
}