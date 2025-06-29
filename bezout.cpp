#include <iostream>
using namespace std;

// Função para calcular o MDC e os coeficientes de Bézout
int euclidesEstendido(int a, int b, int &s, int &t) {
    int s0 = 1, t0 = 0; // para resto = a
    int s1 = 0, t1 = 1; // para resto = b
    int resto_0 = a, resto_1 = b; //restos iniciais (a e b)

    cout << "Passo a passo:\n";
    //exibe os estados iniciais de s e t
    cout << "resto = " << resto_0 << " | quociente = # | s = " << s0 << " | t = " << t0 << "   => " << resto_0 << " = " << a << " * " << s0 << " + " << b << " * " << t0 << endl;
    cout << "resto = " << resto_1 << " | quociente = # | s = " << s1 << " | t = " << t1 << "   => " << resto_1 << " = " << a << " * " << s1 << " + " << b << " * " << t1 << endl;

    while (resto_1 != 0) {
        int quociente = resto_0 / resto_1; //calcula o quociente da divis0a inteira
        int resto_atual = resto_0 - quociente * resto_1; //calcula o resto pelo algoritmo de euclides a =b*q + r => r = a - b * q
        int s_atual = s0 - quociente * s1; 
        int t_atual = t0 - quociente * t1; 

        cout << "resto = " << resto_atual << " | quociente = " << quociente << " | s = " << s_atual << " | t = " << t_atual << "   => " << resto_atual << " = " << resto_0 << " * " << s_atual << " + " << resto_1 << " * " << t_atual << endl;

        // Atualiza as variaveis para a proxima iteração
        resto_0 = resto_1; resto_1 = resto_atual;
        s0 = s1; s1 = s_atual;
        t0 = t1; t1 = t_atual;
    }

    // s0 e t0 satisfazem: a*s0 + b*t0 = mdc(a,b)
    s = s0; //s0 porque é o anterior ao resto 0
    t = t0; //s1 porque é o anterior ao resto
    return resto_0; //retorna o MDC 
}


int main() {
    int a, b;
    cout << "Digite os valores de a e b:\n";
    cin >> a >> b;

    int s, t;
    int mdc = euclidesEstendido(a, b, s, t);

    cout << "\nMDC(" << a << ", " << b << ") = " << mdc << endl;
    cout << "\nCoeficientes de Bezout:\n";
    cout << "s = " << s << ", t = " << t << endl;
    cout << "De acordo com o algoritmo de Euclides MDC = a * s + b * t" << endl; //explicativo
    cout << mdc << " = " << s << " * " << a << " + " << t << " * " << b << endl;

    return 0;
}
