#include <iostream>

//function declaration
int sum(int a = 0, int b = 0);//parameters, assigned values are default values
void swap(int a, int b);

int main() {

    int n1, n2;
    std::cout << "Enter two integer numbers: ";
    std::cin >> n1 >> n2;

    //Sum function calling
    std::cout << "Sum = " << sum(n1, n2) << '\n';//arguments

    std::cout << "Before: " << n1 << " " << n2 << '\n';
    swap(n1, n2);//function call by value, where only copy of arguments goes to parameters not he actual arguments
    std::cout << "After: " << n1 << " " << n2 << '\n';

    return 0;
}
//Sum function definition
int sum(int a, int b) {
    return a + b;
}
//Swap function definition
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "Inside: " << a << " " << b << '\n';
}