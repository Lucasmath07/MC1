#include <iostream>
#include <string>
using namespace std;

string Cifra(string a, int chave) {
    int tam = a.size();
    for (int i = 0; i < tam; i++) {
        char c = a[i];

        
        // Mantém caracteres especiais de 33 a 47 inalterados
        /*if (c >= '!' && c <= '/') {
            continue;
        }*/
        if(c == ' '){
            continue;
        }
        // Letras maiúsculas
        if(c+chave < 'Z'){
            a[i]=c+chave;
        }
        if(c+chave > 'Z'){
            a[i]=(c-'A'+chave)%26+'A';
        }
       
        
        //if (c >= 'A' && c <= 'Z') {
          //  a[i] = (c + chave) % 26;
        //}

        // Letras minúsculas
        /*else if (c >= 'a' && c <= 'z') {
            a[i] = (c - 'a' + chave) % 26 + 'a';
        }

        // Números
        else if (c >= '0' && c <= '9') {
            a[i] = (c - '0' + chave) % 10 + '0';
        }*/

        // Outros caracteres permanecem inalterados (inclusive espaços, acentos, etc.)
    }
    return a;
}

int main() {
    int chave;
    string a;
    cout << "Digite a mensagem que deseja cifrar:\n";
    getline(cin, a);
    cout << "Digite a chave da cifra (positiva):\n";
    cin >> chave;

    if (chave < 0) {
        cout << "A chave deve ser positiva.\n";
        return 1;
    }

    cout << "A mensagem cifrada é: " << Cifra(a, chave) << endl;

    return 0;
}
