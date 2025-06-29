#include <iostream>
using namespace std;

int Teto(float alfa) {
    int teto = 0;

    if (alfa > 0) {
        while (teto < alfa) {
            teto++;
        }
        return teto;
    } else {
        while (teto >= alfa) {
            teto--;
        }
        return teto + 1;
        
    }
}

int main() {
    float a;
    cout << "Digite o numero para implementar a funcao teto: ";
    cin >> a;
    cout << "O teto de " << a << " eh: " << Teto(a);
    return 0;
}
