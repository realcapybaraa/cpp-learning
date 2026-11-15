#include <iostream>

int main() {

    //a code to reverse prefix of word using inbuild methods
    std::string word1 = "hello";
    char ch1 = 'l';

    int index1 = word1.find(ch1);//finds index of first appereance of 'l' in string
    std::reverse(word1.begin(), word1.begin() + index1 + 1);
    std::cout << "After reversing prefix: " << word1 << "\n";

    //a code to reverse prefix of word logically
    std::string word2 = "meooow";
    int n = word2.length();
    int index;
    char ch2 = 'o';
    for (int i = 0; i < n; i++) {//finds the index of first appearence of 'o'
        if (word2[i] == ch2) {
            index = i;
            break;
        }
    }
    int s = 0, e = index;
    while (s <= e) {
        std::swap(word2[s++], word2[e--]);
    }
    std::cout << "After reversing prefix: " << word2 << "\n";

    //a code to remove all spaces from a sentence, logically
    std::string sentence = "hello every meoww!\t how are you?\n";
    std::cout << "After removing white spaces: ";
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n') {
            std::cout << sentence[i];
        }
    }
    std::cout << "\n";

    //a code to find the first repeating character
    std::string word3 = "abcda";
    char ch;
    bool found = false;
    for (int i = 0; i < word3.length(); i++) {
        for (int j = i + 1; j < word3.length(); j++) {
            if (word3[i] == word3[j]) {
                ch = word3[i];
                found = true;
                break;
            }
        }
    }
    if (found) {
        std::cout << "First repeating character: " << ch << "\n";
    }
    else {
        std::cout << "No repeating characters found.\n";
    }
    return 0;
}