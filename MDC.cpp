#include <iostream>
using namespace std;


int MDC(int a, int b) {
    
    if (a == 0 && b == 0) { // MDC(0, 0) é indefinido
        cout << "ERRO! O MDC de 0 e 0 eh indefinido.\n";
        return 0;
    }

    // transforma os numeros em positivos já que o MDC é sempre positivo
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    // caso um dos dois for zero o mdc é o outro (diferente de 0)
    if (a == 0) {
        cout << "O MDC de 0 e " << b << " eh: " << b << endl;
        return b;
    }
    if (b == 0) {
        cout << "O MDC de " << a << " e 0 eh: " << a << endl;
        return a;
    }
    
    while (b != 0) {
        int resto = a % b;
        cout << a << " / " << b << " = " << a / b << " e o resto eh: " << resto << endl;

        // Atualiza os valores
        a = b;
        b = resto;
    }

    // 'a' neste ponto é o MDC, pois a recebe o resto anterior ao resto = 0
    cout << "O MDC eh: " << a << endl;
    return a;
}

int main() {
    int a, b;

   
    cout << "Digite os dois numeros que deseja calcular o MDC:\n";
    cin >> a >> b;

    MDC(a, b);

    return 0;
}

