#include <iostream>

using namespace std;

int div_alg(int a, int b){
    int cont=0;
    
    if(a<0){ a = -a; cont++;}
    if(b<0){ b = -b; cont++;}
    
    int resto = a;
    int quociente = 0;

    while(resto >= b){
        quociente++;
        resto = resto - b;
    }
    if(cont != 1){
        return quociente;
    }
    else{
        quociente = -quociente;
        return quociente;
    }
}
int main(){
    int a,b;
    cout << "Digite o dividendo: ";
    cin >> a;
    cout << "Digite o divisor: ";
    cin >> b;
    if(b != 0){
        cout << "Resultado da divisao: " << div_alg(a,b);
    }
    else{
        cout << "A divisao por zero eh indefinida use outro divisor.\n";
    }
    return 0;
}
