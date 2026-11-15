#include <iostream>

int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    //a code to find length of string without using strlen() function
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    std::cout << "Length of string: " << count << "\n";
    //a code to reverse a string normally
    std::cout << "Reversed string1: ";
    for (int i = count - 1; i >= 0; i--) {
        std::cout << name[i];
    }
    std::cout << "\n";
    //a code to reverse a string using two pointer algorithm
    std::string name1;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name1);
    int s = 0, e = name1.size() - 1;
    while (s < e) {
        std::swap(name1[s++], name1[e--]);
    }
    std::cout << "Reversed string2: " << name1 << "\n";
    //a code to reverse a string reverse(str.begin(), str.end()) function
    std::string name2;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name2);
    reverse(name2.begin(), name2.end());
    std::cout << "Reversed string3: " << name2 << "\n";
    //a code to check if string is palindrome, normally
    std::string name3;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name3);
    std::string copy = name3;

    reverse(name3.begin(), name3.end());
    if (name3 == copy) {
        std::cout << "Palindrome\n";
    }
    else {
        std::cout << "Not palindrome\n";
    }
    //a code to check if string is palindrome, using two pointer algorithm
    int count1 = 0;
    for (int i = 0; copy[i] != '\0'; i++) {
        count1++;
    }
    s = 0, e = count - 1;
    bool isPalindrome = false;
    while (s < e) {
        if (copy[s] == copy[e]) {
            isPalindrome = true;
        }
        s++;
        e--;
    }
    std::cout << ((isPalindrome) ? "Palindrome\n" : "Not palindrome\n");
    //a code to count vowels and consonant in given string
    int vowel = 0, conso = 0;
    for (int i = 0; copy[i] != '\0'; i++) {
        if (copy[i] >= 'A' && copy[i] <= 'Z') {//converts all upercase character into lowercase
            copy[i] += 32;
        }
        if (copy[i] == 'a' || copy[i] == 'e' || copy[i] == 'i' || copy[i] == 'o' || copy[i] == 'u') {
            vowel++;
        }
        else {
            conso++;
        }
    }
    std::cout << "Vowels: " << vowel << "\tConsonants: " << conso << "\n";
    //a code to toggle each character
    std::string myName = "CapyBara";
    for (int i = 0; i < myName.size(); i++) {
        if (myName[i] >= 'a' && myName[i] <= 'z') {
            myName[i] -= 32;
        }
        else if (myName[i] >= 'A' && myName[i] <= 'Z') {
            myName[i] += 32;
        }
    }
    std::cout << "Toggled string: " << myName << '\n';
    return 0;
}