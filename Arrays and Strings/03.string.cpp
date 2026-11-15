/*Every string is terminated by "\0" null character at the end of string. Compiler automatically sets the null character by default at the end. */
#include <iostream>
#include <string>

int main() {

    //learning C-style string(character array)
    //Note: the main problem with C-style string is it's fixed size
    char name[100];
    std::cout << "Enter your name: ";
    //std::cin >> name;//cin stops taking input as soon as it finds spaces or tabs or \n
    std::cin.getline(name, 100);//it is better alternative of cin if string contains white spaces
    std::cout << "You entered: " << name << "\n";

    std::cout << "Length of string: " << strlen(name) << "\n";//used to find the length of given string

    char str1[100] = "Hello", str2[100] = "Mello";
    strcpy(str1, str2);//used to copy/assign one string into another
    std::cout << str1 << "\n";

    strcat(str1, str2);//used to concatinate one string with another
    std::cout << str1 << "\n";

    char str3[100] = "Bello", str4[100] = "Aello";
    std::cout << strcmp(str3, str4) << "\n";//used to compare each letter between two strings using their ASCII value(+ve, -ve, 0)

    //learning String Class, which has dynamic size(ie. not fixed)
    //Note: we dont have to handle null character in string class as in character array
    std::string name1;
    std::cout << "Enter your name: ";
    //std::cin >> name1;
    std::getline(std::cin, name1);
    std::cout << "You entered: " << name1 << "\n";

    std::cout << "Length of string: " << name1.length() << "\n";//or we can use name1.size() too

    std::string color1 = "blue", color2 = "green";
    color1 = color2;//we can normally assign one string into another, which wasnt allowed in character array
    std::cout << color1 << "\n";

    color1 += color2;//we can do concatenation between two strings easily with simple using +
    std::cout << color1 << "\n";

    std::string color3 = "yellow", color4 = "mellow";
    std::cout << (color3 == color4) << "\n";//easy comparison(==, !=, <, >, >=, <=) between two strings too(either 0 or 1)
    //there are alot of common inbuild methods in string class in cpp, such as,
    std::string game;
    std::cout << "Enter your fav game: ";
    std::getline(std::cin, game);

    std::cout << "Length of string: " << game.length() << "\n";//.length() to find length of string

    std::string game1 = "pubg", game2 = "minecraft";
    std::cout << game1.append(game2) << "\n";//.append(stringToAdd) to concatinate one string with another

    std::string game3 = "lud";
    game3.push_back('o');//.push_back(character) has a void return type, meaning it returns nothing. std::cout cannot print void because there is no value to display.
    std::cout << game3 << "\n";

    game3.pop_back();//removes the last character from the string
    std::cout << game3 << "\n";

    std::cout << game2.insert(4, "hero") << "\n";//.insert(index, stringToAdd) adds a string in given index of another string

    std::cout << color3.compare(color4) << "\n";//.compare(anotherString) compares two string using their ASCII value

    std::cout << game2.erase(5, 4) << "\n";//output: minehraft

    std::cout << color3.substr(0, 3) << "\n";//subtracts part of string which is out of given range

    std::cout << game.find("bile") << "\n";//finds the index from which substr starts in main string

    std::cout << game.replace(0, 6, "phone") << "\n";//.replace(startIndex, count, stringToReplace) replaces new string in given string

    game1.swap(game2);
    std::cout << game1 << "\n";
    return 0;
}