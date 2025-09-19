#include <iostream>
using namespace std;

int main(){
     int i, n, f;

     cin >> n;
     f = 1;
     for(i = 0; i < n; i++){
          f = 1 + f;
          cout << f << endl;
     }

     return 0;
}