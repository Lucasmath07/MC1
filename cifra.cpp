#include <iostream>
#include <string>
using namespace std;

string Cifra(string frase, int chave) {
    int tamanhoDaFrase = frase.size();
    
    for (int i = 0; i < tamanhoDaFrase; i++) {
        char letraAtual = frase[i];  
        
        if(letraAtual == ' '){  //mantem o espaço sem alteração
            continue;
        }
        if (letraAtual >= 'A' && letraAtual <= 'Z') { //cifra para letra maiuscula
            
            frase[i] = (letraAtual - 'A' + chave) % 26 + 'A';
        }
        else if (letraAtual >= 'a' && letraAtual <= 'z') { //cifra para letras minusculas

            frase[i] = (letraAtual - 'a' + chave) % 26 + 'a';
        }
        
    }
    
    return frase;
}

int main() {
    int chave;
    string frase;
    cout << "Digite a mensagem que deseja cifrar (letras maiusculas e minusculas):\n";
    getline(cin, frase);
    cout << "Digite a chave da cifra (entre 0 e 26):\n";
    cin >> chave;

    if (chave < 0) {
        cout << "A chave deve ser positiva.\n";
        return 0;
    }

    cout << "A mensagem cifrada eh: " << Cifra(frase, chave) << endl;

    return 0;
}

