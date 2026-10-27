#include <iostream>
#include <cstdlib>// Header for functions like rand() and srand()
#include <ctime>// Header providing time functions used to seed the random generator
using namespace std;

int main(){

    //Guess the number(1 to 100) game
     srand(time(0));// Seeds the random number generator with the current time for unique numbers each run
     int random = rand() % 100 + 1;// Generates a pseudo-random integer value
     //cout << random << '\n';

     int num, count = 1;
     do{
     cout << "Enter the number from 1 to 100: ";
     cin >> num;

     if(num > random){
      cout << "too high, try lower. \n";
     }else if(num < random){
      cout << "too low, try higher. \n";
     }else{
      cout << "congrats you guessed it in " << count << " attempts! \n";
     }
     //i++;
     count++;
   }while(num != random);

   return 0;
}