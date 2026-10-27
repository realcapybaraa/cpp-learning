#include <iostream>
#include <string>//required for using std::string

int main(){

    //A code to take name and age as inputs and display it
    std::string name;
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cin.ignore();//using cin.ignore() to clear the trailing newline character from the buffer after reading numeric input, ensuring subsequent string inputs arent skipped.
    std::cout << "Enter your name: ";
    //std::cin >> name; cin stops taking input as soon as it finds space or newline
    std::getline(std::cin, name);//hence used getline as it accepts whitespaces too

    std::cout << "Your name is " << name << " and you are " << age << " years old." << '\n';

    //A code to print Hello, "Capy" as it is
    std::cout << "Hello, \"Capy\"" << '\n';//same as \t for tab and \n for newline

    //A code to take 3 numbers as input and print theri average
    int num1, num2, num3;
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;

    double avg = static_cast<double>(num1 + num2 + num3) / 3;//explicitly type casting so that answer doesnt get truncated
    
    std::cout << "Average: " << avg << '\n';

    //A code to take two numbers as input and swap their value
    int x, y;
    std::cout << "Enter value of x and y: ";
    std::cin >> x >> y;

    int temp = x;//for swapping
    x = y;
    y = temp;

    std::cout << "After swapping, x = " << x << " and y = " << y << '\n';

    //A code to take length and breadth of rectangle as input as print area and perimeter of rectangle
    float length, breadth;
    std::cout << "Enter length and breadth of rectangle: ";
    std::cin >> length >> breadth;

    float area = length * breadth;
    float perimeter = 2 * (length + breadth);

    std::cout << "Area of rectangle is " << area << " and perimeter of rectangle is " << perimeter << '\n';

    //A code to take temperature in Celsius and convert it to Fahrenheit
    double tempCelsius, tempFahrenheit;
    std::cout << "Enter the temperature in Celsius degree: ";
    std::cin >> tempCelsius;

    tempFahrenheit = (tempCelsius * ((double)9 / 5)) + 32;

    std::cout << "Given temperature in Fahrenheit degree: " << tempFahrenheit << '\n';

    //A code to take a character as input and print its ASCII value
    char letter;
    std::cout << "Enter a character: ";
    std::cin >> letter;

    int asciiValue = letter;
    std::cout << "ASCII value: " << asciiValue << '\n';

    return 0;
}