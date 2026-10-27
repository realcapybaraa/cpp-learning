#include <iostream>
using namespace std;

int main(){

    //while-loop is an entry-control loop, used when no.of iterations is unknown.
    int n = 5, i = 1;
    while(i <= n){
        cout << "Hello \n";
        i++;
    }

    //print digits of number, sum of the digits and reverse of number
    int num, lastDigit, sum = 0, rev = 0;
    cout << "Enter a multidigit number: ";
    cin >> num;
    int originalNum = num;
    int count = 0;

    cout << "Digits: " << '\n';
    while(num > 0){
        lastDigit = num % 10;//gives last digit as remainder
        cout << lastDigit << "\n";
        sum += lastDigit;//sum logic
        rev = rev * 10 + lastDigit;//reverse logic
        num = num / 10;//outthrows the last digit
        i++;
    }
    cout << "Sum = " << sum << '\n';
    cout << "Reverse = " << rev << '\n';
    //palindrome check
    if(originalNum == rev){
        cout << "Palindrome number \n";
    }else{
        cout << "Not a Palindrome number \n";
    }

    return 0;
}