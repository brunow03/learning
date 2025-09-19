#include <iostream>
using namespace std;

int main(){
    
    long int N, menor, diff;
    long int i;

    cin >> N;

    long int * valoresPtr = new long int[N];

    cin >> valoresPtr[0];
    menor = valoresPtr[0];
    for(i = 1; i < N; i++){
        cin >> valoresPtr[i];
        if(valoresPtr[i] < menor) menor = valoresPtr[i];
    }

    //fabs() modulo de um numero
    diff = 0;
    for(i = 0; i < N; i++){
        
        if(valoresPtr[i] - menor > diff){
            diff = valoresPtr[i] - menor;
        }

    }

    cout << diff << endl;
    
    return 0;
}

/*
Deselegante e lento:
    
    maior = 0;
    for(i = 0; i < N-1; i++){
        for (j = i+1; j < N; j++)
        { 
            diff = valoresPtr[j] - valoresPtr[i];
            if(diff < 0) diff = (-1)*diff;

            if (diff > maior)
            {
                maior = diff;
            }
        }
    }
*/