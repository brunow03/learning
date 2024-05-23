#include <iostream>
using namespace std;

int main(){

     int n, i, res;

     cin >> n;

     int * listaPtr = new int[n];

     res = 0;
     for(i = 0; i < n; i++){
          cin >> listaPtr[i];
          if((listaPtr[i] > 0 && listaPtr[i]%2 == 0) || (listaPtr[i] < 0 && (-1)*listaPtr[i]%2 == 0)){
               res++;
          }
     }

     cout << res << endl;

     return 0;
}