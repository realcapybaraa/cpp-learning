#include <iostream>
using namespace std;

int main(){

    //A code to print whether a number is prime or not
    int n, count1 = 0;
    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            count1++;
        }
    }
    if(count1 == 2){
        cout << n << " is a prime number. \n";
    }else{
        cout << n << " is not a prime number. \n";
    }

    //A code to check if a number is armstrong or not
    int num, lastDig, arm = 0, origNum;
    cout << "Enter a multidigit number: ";
    cin >> num;

    int count2 = 0, i = 1, originalNum = num, copy = num;
    while(num > 0){//finds the number of digits
        lastDig = num % 10;
        num = num / 10;
        count2++;
    }
    while(i <= count2){//calculates the armstrong
        lastDig = originalNum % 10;
        arm = arm + pow(lastDig, count2);
        originalNum = originalNum / 10;
        i++;
    }
    if(copy == arm){//checks if armstrong or not
        cout << "Armstrong number \n";
    }else{
        cout << "Not a armstrong number \n";
    }

    //A code to check if a number is strong or not
    int number, last_dig, factSum = 0;
    cout << "Enter a positive integer: ";
    cin >> number;

    int copyNum = number;
    do{//finds individual digits as last digits
        int fact = 1, j = 1;

        last_dig = number % 10;
        number = number / 10;
        //calculates factorial of each digits
        do{
            fact = fact * j;
            j++;
        }while(j <= last_dig);
        factSum += fact;
        
    }while(number > 0);

    if(copyNum == factSum){
        cout << copyNum << " is a strong number. \n";
    }else{
        cout << copyNum << " is not a strong number. \n";
    }

    return 0;
}