#include <iostream>
using namespace std;

//for-loop is an entry-control loop, used when no.of iterations is known.
int main(){

    int n = 5;
    for(int i = 1; i <= 5; i++){//start; stop; step
        cout << "Hello. \n";
    } 
    //print n natural numbers
    int num;
    cout << "Enter a natural number: ";
    cin >> num;

    cout << "Numbers: ";
    for( int i = 1; i<= num; i++){
        cout << i << " ";
    }
    cout << '\n';

    //print sum of n natural numbers
    int sum = 0;
    for( int i = 1; i<= num; i++){
        sum += i;
    }
    cout << "Sum = " << sum << '\n';

    //print factorial of n natural naumbers
    int fact = 1;
    for(int i = 1; i <= num; i++){
        fact = fact * i;
    }
    cout << "Factorial = " << fact << '\n';

    //print factors of a number
    cout << "Factors: ";
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            cout << i << ", ";
        }
    }
    cout << '\n';

    return 0;
}
/*example of an infinite loop: 
for(i = 1; ; i++){
    cout << i << '\n';
   }
*/