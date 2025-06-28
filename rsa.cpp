#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;

int totiente(int p, int q) {
    return (p - 1) * (q - 1);
}

int N(int p, int q) {
    return p * q;
}

int MDC(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int coprimo(int tot_n) {
    for (int e = 2; e < tot_n; e++) {
        if (MDC(e, tot_n) == 1)
            return e;
    }
    return -1;
}

int inverso_modular(int e, int phi) {
    int t = 0, new_t = 1;
    int r = phi, new_r = e;

    while (new_r != 0) {
        int q = r / new_r;
        int temp = new_t;
        new_t = t - q * new_t;
        t = temp;

        temp = new_r;
        new_r = r - q * new_r;
        r = temp;
    }

    if (t < 0)
        t += phi;

    return t;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

void encriptar(string mensagem, long long encriptados[], int e, int n) {
    cout << "\nMensagem encriptada:\n";
    for (int i = 0; i < mensagem.size(); i++) {
        char c = mensagem[i];
        if (c == ' ') {
            cout << ' ';
            encriptados[i] = -1;
            continue;
        }

        long long m = (int)c;
        long long c_val = mod_exp(m, e, n);
        encriptados[i] = c_val;

        char pseudo = (c_val % 26) + 'a';
        cout << pseudo;
    }
}

void decriptar(long long encriptados[], int tamanho, int d, int n) {
    cout << "\n\nMensagem decriptada:\n";
    for (int i = 0; i < tamanho; i++) {
        if (encriptados[i] == -1) {
            cout << ' ';
            continue;
        }

        long long m_dec = mod_exp(encriptados[i], d, n);
        cout << (char)m_dec;
    }
    cout << endl;
}

int main() {
    int p, q;
    string mensagem;
    long long encriptados[MAX];

    cout << "Digite p: ";
    cin >> p;
    cout << "Digite q: ";
    cin >> q;
    cin.ignore();

    int n = N(p, q);
    int phi = totiente(p, q);
    int e = coprimo(phi);
    int d = inverso_modular(e, phi);

    cout << "\nDigite a mensagem que deseja encriptar (sem acento):\n";
    getline(cin, mensagem);

    encriptar(mensagem, encriptados, e, n);
    decriptar(encriptados, mensagem.size(), d, n);

    return 0;
}
