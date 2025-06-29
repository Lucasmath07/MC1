#include <iostream>
#include <string>

using namespace std;

void cifra(string frase, int chave){
    string alfabeto_M = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfabeto_m = "abcdefghijklmnopqrstuvwxyz";

    string encriptados = frase;  // Inicializa com o mesmo tamanho da frase original

    for(int i = 0; i < frase.size(); i++){ 
        if(frase[i] == ' '){
            encriptados[i] = ' ';
            continue;
        }

        for(int j = 0; j < 26; j++){
            if(frase[i] == alfabeto[j]){
                encriptados[i] = alfabeto[(j + chave) % 26];
                break;  // Pare depois de encontrar a letra
            }
        }
    }

    cout << "Mensagem encriptada: " << encriptados << endl;
}

int main(){
    string frase;
    int chave;

    cout << "Digite a frase que deseja encriptar (apenas MAIÚSCULAS e MINÙSCULAS): ";
    getline(cin, frase);
    cout << "Digite a chave (0 a 25): ";
    cin >> chave;

    if (chave < 0 || chave > 26) {
        cout << "Chave inválida. Use um valor entre 0 e 25.\n";
        return 0;
    }

    cifra(frase, chave);

    return 0;
}
