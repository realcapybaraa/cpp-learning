#include <iostream>
#include <bitset>//required for displaying binary format

int main(){

    int a = 12;//decimal literal
    std::cout << "Decimal: " << std::dec << a << '\n';//display as decimal
    std::cout << "Octal: " << std::oct << a << '\n';//display as octal
    std::cout << "Hexadecimal: " << std::hex << a << '\n';//display as hexadecimal
    std::cout << "Binary: " << std::bitset<8>(a) << '\n';//display as binary(8 bit)

    int b = 014;//octal literal(12)
    std::cout << "Decimal: " << std::dec << b << '\n';//display as decimal
    std::cout << "Octal: " << std::oct << b << '\n';//display as octal
    std::cout << "Hexadecimal: " << std::hex << b << '\n';//display as hexadecimal
    std::cout << "Binary: " << std::bitset<8>(b) << '\n';//display as binary(8 bit)

    int c = 0xC;//hexadeciaml literal(12)
    std::cout << "Decimal: " << std::dec << c << '\n';//display as decimal
    std::cout << "Octal: " << std::oct << c << '\n';//display as octal
    std::cout << "Hexadecimal: " << std::hex << c << '\n';//display as hexadecimal
    std::cout << "Binary: " << std::bitset<8>(c) << '\n';//display as binary(8 bit)

    int d = 0b00001100;//binary literal(12)
    std::cout << "Decimal: " << std::dec << d << '\n';//display as decimal
    std::cout << "Octal: " << std::oct << d << '\n';//display as octal
    std::cout << "Hexadecimal: " << std::hex << d << '\n';//display as hexadecimal
    std::cout << "Binary: " << std::bitset<8>(d) << '\n';//display as binary(8 bit)


    return 0;
}