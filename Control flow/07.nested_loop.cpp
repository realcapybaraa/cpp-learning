#include <iostream>
using namespace std;

int main(){

    //learning pattern priting using nested loops
    int n = 5;
    for(int i = 1; i <= n; i++){//outerloop(no.of rows)
        for(int j = 1; j <= n; j++){//innerloop(no.of columns)
            cout << "* ";
        }
      cout << '\n';
    }
    cout << '\n';

    //Right angled traingle star pattern and its mirror pattern
    cout << "Right angled traingle star pattern: " << '\n';
    int a = 5;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
    cout << "its mirror pattern: \n";
    for(int i = 1; i <= a; i++){
        //for printing spaces
        for(int space = (a - i); space > 0; space-- ){
        cout << "  ";
    }  //for printing stars
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }
        cout << '\n';
    }
    cout << '\n';

    //Inverted right angled traingle and its mirror pattern
    cout << "Inverted right angled traingle star pattern: " << '\n';
    int b = 5;
    for(int i = 1; i <= b; i++){
        for(int j = b; j >= i; j--){
            cout << "* ";
        }
        cout << '\n';
    }
    cout << "its mirror pattern: \n";
    for(int i = 1; i <= b; i++){
        //for printing spaces
        for(int space = 1; space < i; space++ ){
        cout << "  ";
    }  //for printing stars
        for(int j = 0; j <= (b - i); j++){
            cout << "* ";
        }
        cout << '\n';
    }
    cout << '\n';

    //V-shape star pattern and its mirror pattern
    cout << "V-shape star pattern: \n";
    int c = 5;
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= (2*c -1); j++){
            if((i == j) || (i + j) == (2 * c)){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << '\n';
    }
    cout <<"its mirror pattern: \n";
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= (2*c -1); j++){
            if((i + j) == (c + 1) || (j - i) == (c - 1)){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << '\n';
    }

    //X-shape star pattern
    cout << "X-shape star pattern: \n";
    int d = 7;
    for(int i = 1; i <= d; i++){
        for(int j = 1; j <= d; j++){
            if((i == j) || (i + j) == (d + 1)){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << '\n';
    }
     
    return 0;
}