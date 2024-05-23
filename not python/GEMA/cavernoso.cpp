#include <iostream>
using namespace std;

// int("string".size());
// "".push_back(''); adicionar caractere no final
// "aula " + "gema" = "aula gema"
// string s = aula + gema;
// vector<string> s(3);
// getline(cin, s);

int main(){

    int n, maior_frequencia, frequencia, mais_frequente;
    int i, j;
    string pauzinhos;

    cin >> n;
    int * contagemPtr = new int[n];

    cin.ignore();

    for(i = 0; i < n; i++){
        getline(cin, pauzinhos);
        contagemPtr[i] = int(pauzinhos.size());
    }
    
    maior_frequencia = 0;
    frequencia = 0;
    mais_frequente = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(contagemPtr[j] == contagemPtr[i]) frequencia++;
        }
        if(frequencia > maior_frequencia){
            maior_frequencia = frequencia;
            mais_frequente = contagemPtr[i];
        } 
        frequencia = 0;
    }


    cout << mais_frequente << endl;

    /*   
    getline(cin, pauzinhos);
    cout<<int(pauzinhos.size()) << endl; 
    */

    return 0;
}