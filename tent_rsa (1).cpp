#include <iostream>
#include <string>
using namespace std;

const long long MAX = 1000;

long long totiente(long long p, long long q) {
    return (p - 1) * (q - 1);
}

long long N(long long p, long long q) {
    return p * q;
}

long long MDC(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int encontrar_inverso_modular(int base, int modulo_phi) {
    int coef_antigo = 0, coef_atual = 1;
    int resto_antigo = modulo_phi, resto_atual = base;

    while (resto_atual != 0) {
        int quociente = resto_antigo / resto_atual;

        int temporario = coef_atual;
        coef_atual = coef_antigo - quociente * coef_atual;
        coef_antigo = temporario;

        temporario = resto_atual;
        resto_atual = resto_antigo - quociente * resto_atual;
        resto_antigo = temporario;
    }

    if (coef_antigo < 0)
        coef_antigo += modulo_phi;

    return coef_antigo;
}

long long potenciacaoModular(long long b, long long e, long long m) {
    long long x = 1;
    long long potencia = b % m;

    while (e > 0) {
        if (e % 2 == 1) {
            x = (x * potencia) % m;
        }
        potencia = (potencia * potencia) % m;
        e = e / 2;
    }

    return x; // resultado: b^n mod m
}


#include <iostream>
using namespace std;

const int MAX = 1000; // tamanho máximo da mensagem encriptada

// Suponho que você já tem MDC, totiente e potenciacaoModular implementados

void encriptar(string mensagem, long long p, long long q, long long e, long long n, long long encriptados[], int &tam_saida) {
    tam_saida = 0;

    if (MDC(totiente(p, q), e) != 1) {
        cout << "Erro: e não é coprimo com totiente de n.\n";
        return;
    }

    int tam = mensagem.size();
    for (int i = 0; i < tam; i++) {
        char c = mensagem[i];
        if (c == ' ') {
            encriptados[tam_saida++] = -1; // espaço tratado como -1
        } else {
            long long m = (int)c;
            long long c_val = potenciacaoModular(m, e, n);
            encriptados[tam_saida++] = c_val;
        }

        if (tam_saida >= MAX) {
            cout << "Erro: mensagem muito grande para o buffer.\n";
            break;
        }
    }
}





int main() {
    long long p, q, e;
    string mensagem;
    

    cout << "Digite p: ";
    cin >> p;
    cout << "Digite q: ";
    cin >> q;
    Cout << "Digite e: ";
    cin >> e;

    long long n = N(p, q);
    long long phi = totiente(p, q);
    long long d = inverso_modular(e, phi);

    cout << "\nDigite a mensagem que deseja encriptar (sem acento):\n";
    getline(cin, mensagem);

    encriptar(mensagem, encriptados, e, n);
    decriptar(encriptados, mensagem.size(), d, n);

    return 0;
}
