#include <iostream>
using namespace std;

int main(){

     //do-while-loop is an exit-control loop, used when no.of iterations is unknown and runs at least one time independept of condition provided.
     int n = 5, i = 1;
     do{
        cout << "Meooooow \n";
        i++;
     }while(n < 0);

     //learning jump statements like break and continue
     int x = 6, j = 1;
     do{
      if(j == 3){
         j++;
         continue;//skips that part of loop
      }
      cout << j << '\n';
      if(j == 5){
         break;//ends the loop from there
      }
      j++;
     }while(j <= x);

    return 0;
}