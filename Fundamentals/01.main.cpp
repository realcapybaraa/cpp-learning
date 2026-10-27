#include <iostream>//header file/library, cpp is case sensitive

int main() {
    std::cout << "Meoowwww\n";

    //learning int datatype(4 bytes)
    int _num1{}, $num2, num_3, numFourth, sum = 0;//naming convention and multiple var declaration
    std::cout << "Enter four numbers: " <<std::endl;//insertion operator for printing output, std::endl is slow as it flushes the buffer
    std::cin >> _num1 >> $num2 >> num_3 >> numFourth;//using >> extraction operator to for taking input

    sum = _num1 + $num2 + num_3 + numFourth;
    std::cout << "Sum = " << sum << '\n';//\n is best

    //learning char datatype(1 bytes)
    char letter;
    std::cout << "Enter a character: ";
    std::cin >> letter;
    std::cout << "You entered: " << letter <<'\n';

    //learning float datatype(4 bytes)
    constexpr float pi = 3.14;//defining constant
    float radius, area_circle;
    std::cout << "Enter the value of radius: ";
    std::cin >> radius;

    area_circle = pi * radius * radius;
    std::cout << "Area of circle is: " << area_circle << '\n';
     
    //learning sizeof() operator
    int i;
    std::cout << "Size of int: " << sizeof(i) << '\n';
    return 0;
}
/*Extra notes:
1. Statically typed languages check and enforce variable data types at compile time before execution (e.g., C++, Java), whereas dynamically typed languages assign and verify data types on the fly at runtime while the program is running (e.g., Python, JavaScript).
2. literal vs identifires:
int score = 100;// score is identifier and 100 is integer literal(fixed vallue)
3. Garbage value: is unpredictable, arbitrary data stored in an uninitialized variable, left behind in memory by previous program operations, which is not safe.
*/