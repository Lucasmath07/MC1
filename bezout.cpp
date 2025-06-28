#include <iostream>
using namespace std;

// Função para calcular o MDC e os coeficientes de Bézout
int euclidesEstendido(int a, int b, int &s, int &t) {
    int s0 = 1, t0 = 0;
    int s1 = 0, t1 = 1;
    int r0 = a, r1 = b;

    cout << "Passo a passo:\n";
    cout << "r0 = " << r0 << ", r1 = " << r1 << endl;

    while (r1 != 0) {
        int q = r0 / r1;
        int r2 = r0%r1;//r0 - q * r1;
        int s2 = s0 - q * s1;
        int t2 = t0 - q * t1;

        cout << "r = " << r2 << " , q = " << q << " , s = " << s2 << " , t = " << t2 << endl;

        // Avança para o próximo passo
        r0 = r1; r1 = r2;
        s0 = s1; s1 = s2;
        t0 = t1; t1 = t2;
    }

    // s0 e t0 satisfazem: a*s0 + b*t0 = mdc
    s = s0;
    t = t0;
    return r0;
}


int main() {
    int a, b;
    cout << "Digite os valores de a e b:\n";
    cin >> a >> b;

    int s, t;
    int mdc = euclidesEstendido(a, b, s, t);

    cout << "\nMDC(" << a << ", " << b << ") = " << mdc << endl;
    cout << "Coeficientes de Bezout:\n";
    cout << "s = " << s << ", t = " << t << endl;
    cout << mdc << " = " << s << " * " << a << " + " << t << " * " << b << endl;

    return 0;
}
