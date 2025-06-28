#include <iostream>

using namespace std;

const long long TAMANHO = 10000000000; // até 1 bilhão
bool eh_primo[TAMANHO];      // vetor global para não estourar a stack

void primos(int a , int b){
    if(a==1){a=a+1;}
    // Inicializa todos como primos
    for(int i = a; i < b; i++){
        eh_primo[i] = true;
    }
    

    for(int numeroAtual = a; numeroAtual * numeroAtual <= b; numeroAtual++){
        if(eh_primo[numeroAtual]){
            for(int multiplo = numeroAtual * numeroAtual; multiplo <= b; multiplo += numeroAtual){
                eh_primo[multiplo] = false;
            }
        }
    }

    cout << "Numeros primos de " << a << " até " << b << ":\n";
    for(int i = a; i <= b; i++){
        if(eh_primo[i]){//se for verdade
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main(){
    int a, b;
    cout << "Digite o primeiro numero do intervalo: ";
    cin >> a;
    cout << "Digite o ultimo numero do intervalo: ";
    cin >> b;

    if(b >= TAMANHO){
        cout << "Erro: intervalo muito grande. Use no maximo até " << TAMANHO - 1 << ".\n";
        return 1;
    }

    primos(a, b);
    return 0;
}
