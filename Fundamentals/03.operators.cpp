#include <iostream>

int main(){
   
    //unary operators
    int a = 5;
    std::cout << "prefix increment: " << ++a << '\n';//prefx: changes the value first and then uses the updated value in the expression
    std::cout << "postfix increment: " << a++ << '\n';//postfix: uses the current value first and then changes the value afterward
    std::cout << "current value: " << a << '\n';

    std::cout << "prefix decrement: " << --a << '\n';
    std::cout << "postfix decrement: " << a-- << '\n';
    std::cout << "current value: " << a << '\n';

    //arithmetic operators
    int x = 10, y = 3;
    std::cout << "sum = " << x + y << '\n';
    std::cout << "product = " << x * y << '\n';
    std::cout << "subtraction = " << x - y << '\n';
    std::cout << "Division = " << static_cast<double>(x) / y << '\n';
    std::cout << "Remainder = " << x % y << '\n';

    //relational operators(0 = fale & 1 = true) and bool datatype(1 byte)
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    bool isEqual = (num1 == num2);//is equal to operator
    std::cout << "Given numbers are equal: " << isEqual << '\n';
    bool isNotEqual = (num1 != num2);//is not equal to operator
    std::cout << "Given numbers are not equal: " << isNotEqual << '\n';
    bool isGreater = (num1 > num2);//is greater than operator
    std::cout << "num1 > num2: " << isGreater << '\n';
    bool isLesser = (num1 < num2);//is lesser than operator
    std::cout << "num1 < num2: " << isLesser << '\n';
    bool isGreaterOrEqual = (num1 >= num2);//is greater than or equal operator
    std::cout << "num1 >= num2: " << isGreaterOrEqual << '\n';
    bool isLesserOrEqual = (num1 <= num2);//is lesser than or equal operator
    std::cout << "num1 <= num2: " << isLesserOrEqual << '\n';

    //assignment operators
    int value = 10;//simple assignment operator
    value += 5;//add and asign operator
    std::cout << "After += 5: " << value << '\n';
    value -= 5;//subtract and assign operator
    std::cout << "After -= 5: " << value << '\n';
    value *= 5;//multiply and assign operator
    std::cout << "After *= 5: " << value << '\n';
    value /= 5;//divide and assign operator
    std::cout << "After /= 5: " << value << '\n';
    value %= 5;//modulus and assign operator
    std::cout << "After %= 5: " << value << '\n';

    //logical operators
    int room1, room2, room3;
    std::cout << "Enter three rooms numbers: ";
    std::cin >> room1 >> room2 >> room3;

    std::cout << "are same room: " << ((room1 == room2) && (room2 == room3)) << '\n';//true only if both conditions are true
    std::cout << "atleast two rooms are same room: " << ((room1 == room2) || (room2 == room3) || (room1 == room3)) << '\n';//true if atleast one condition is true
    std::cout << "NO room are same: " << !((room1 == room2) && (room2 == room3)) << '\n';//reverses the boolean value
    
    return 0;
}