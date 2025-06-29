#include <iostream>
using namespace std;


int mod(int a, int b) {

    if (b < 0) { //por definição no calculo do mod sempre usamos |b| t.q. 0 <= r < |b|
        b = -b;
    }

    int resto = a;

    while(resto < 0) {
        resto = resto + b; //se o "a" for negativo, somamos "b" até resto ser maior que zero
    }

    while(resto >= b) { // caso o resto seja maior ou igual a b, subtraimos b do resto até que o resto seja menor que b
        resto = resto - b;
    }

    return resto;
}

int main() {
    int a, b;
    cout << "Digite o dividendo: ";
    cin >> a;
    cout << "Digite o divisor: ";
    cin >> b;
    if (b == 0) {
        cout << "Divisao por zero eh indefinida. Digite outro valor para o denominador" << endl;
        return 0;
    }
    cout << a << " mod " << b <<" = "<< mod(a, b) << endl;

    return 0;
}

