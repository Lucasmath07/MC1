#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000; // tamanho máximo da mensagem encriptada

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

long long encontrar_inverso_modular(long long base, long long modulo_phi) {
    long long coef_antigo = 0, coef_atual = 1;
    long long resto_antigo = modulo_phi, resto_atual = base;

    while (resto_atual != 0) {
        long long quociente = resto_antigo / resto_atual;
        long long temporario = coef_atual;
        coef_atual = coef_antigo - quociente * coef_atual;
        coef_antigo = temporario;

        temporario = resto_atual;
        resto_atual = resto_antigo - quociente * resto_atual;
        resto_antigo = temporario;
    }

    if (coef_antigo < 0){
        coef_antigo += modulo_phi;
    }
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

    return x; // resultado: b^e mod m
}

void encriptar(string mensagem, long long p, long long q, long long e, long long n, long long encriptados[], int &tam_saida) {
    tam_saida = 0;
    char alfa;
    if (MDC(totiente(p, q), e) != 1) {
        cout << "Erro: e não é coprimo com totiente de n.\n";
        return;
    }

    int tam = mensagem.size();
    for (int i = 0; i < tam; i++) {
        char c = mensagem[i];
        if (c == ' ') {
            encriptados[tam_saida++] = ' '; // espaço tratado como -1
        } else {
            long long m = (int)c;
            long long c_valor = potenciacaoModular(m, e, n);
            encriptados[tam_saida++] = c_valor;
        }

        if (tam_saida >= MAX) {
            cout << "Erro: mensagem muito grande para o buffer.\n";
            break;
        }
    }
     cout << "\nMensagem criptografada (em números):\n";
    for (int i = 0; i < tam_saida; i++) {
        if (encriptados[i] == -1)
            cout << "-1 ";
        else
            cout << encriptados[i] << " ";
    }
    cout << endl;
    cout << "\nMensagem criptografada (em letras):\n";
        for (int i = 0; i < tam; i++) {
        char c = encriptados[i];

        
        if (c >= '!' && c <= '/') {
            encriptados[i]= (c % 14) + '!';
        }

        // Letras maiúsculas
        if (c >= 'A' && c <= 'Z') {
            encriptados[i] = (c % 26) + 'A';
        }

        // Letras minúsculas
        else if (c >= 'a' && c <= 'z') {
            encriptados[i] = (c % 26) + 'a';
        }

        // Números
        else if (c >= '0' && c <= '9') {
            encriptados[i] = (c % 10) + '0';
        }
        cout<< encriptados[i];
        // Outros caracteres permanecem inalterados (inclusive espaços, acentos, etc.)
    } 
    cout << endl;


}
void decriptar(long long encriptados[], int tamanho, long long d, long long n) {
    cout << "\nMensagem decriptada:\n";
    for (int i = 0; i < tamanho; i++) {
        if (encriptados[i] == -1) {
            cout << ' ';
        } else {
            long long m_dec = potenciacaoModular(encriptados[i], d, n);
            cout << (char)m_dec;
        }
    }
    cout << endl;
}


int main() {
    long long p, q, e;
    string mensagem;
    long long encriptados[MAX];
    int tam_saida;

    cout << "Digite p: ";
    cin >> p;
    cout << "Digite q: ";
    cin >> q;
    cout << "Digite e: ";
    cin >> e;

    cin.ignore(); // limpa buffer para ler getline corretamente

    long long n = N(p, q);
    long long phi = totiente(p, q);
    long long d = encontrar_inverso_modular(e, phi);

    cout << "\nDigite a mensagem que deseja encriptar:\n";
    getline(cin, mensagem);

    encriptar(mensagem, p, q, e, n, encriptados, tam_saida);
    decriptar(encriptados, tam_saida, d, n);

    return 0;
}

