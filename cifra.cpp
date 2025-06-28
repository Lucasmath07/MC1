#include <iostream>
#include <string>
using namespace std;

string Cifra(string frase, int chave) {
    int tamanhoDaFrase = frase.size();
    for (int i = 0; i < tamanhoDaFrase; i++) {
        char letraAtual = frase[i];

        
        // Mantém caracteres especiais de 33 a 47 inalterados
        /*if (c >= '!' && c <= '/') {
            continue;
        }*/
        if(letraAtual == ' '){
            continue;
        }
        // Letras maiúsculas
        if(letraAtual + chave < 'Z'){
            frase[i] = letraAtual + chave;
        }
        if(letraAtual + chave > 'Z'){
            frase[i] = (letraAtual - 'A' + chave) % 26 + 'A';
        }
        if(letraAtual + chave < 'z'){
            frase[i] = letraAtual + chave;
        }
        if(letraAtual + chave > 'z'){
            frase[i] = (letraAtual - 'a' + chave) % 26 + 'a';
        }

       
    }
    return frase;
}

int main() {
    int chave;
    string frase;
    cout << "Digite a mensagem que deseja cifrar:\n";
    getline(cin, frase);
    cout << "Digite a chave da cifra:\n";
    cin >> chave;

    if (chave < 0) {
        cout << "A chave deve ser positiva.\n";
        return 0;
    }

    cout << "A mensagem cifrada eh: " << Cifra(frase, chave) << endl;

    return 0;
}

