#include <iostream>
#include <string>

using namespace std;

// Função que aplica a cifra de César
void cifra(string frase, int chave){
    string alfabeto_M = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alfabeto_m = "abcdefghijklmnopqrstuvwxyz";

    string encriptados = frase;  // inicializa com a mesma frase

    for(int i = 0; i < frase.size(); i++){ 
        if(frase[i] == ' '){
            encriptados[i] = ' '; // mantém os espaços
            continue;
        }

        
        for(int j = 0; j < 26; j++){
            if(frase[i] == alfabeto_M[j]){ // verifica se a letra é maiúscula
                encriptados[i] = alfabeto_M[(j + chave) % 26]; //aplica a formula da vifra de cesar
                break;
            }

            
            if(frase[i] == alfabeto_m[j]){ // Verifica se a letra é minúscula
                encriptados[i] = alfabeto_m[(j + chave) % 26]; //aplica a formula da cifra de cesar
                break;
            }
        }
    }

    cout << "Mensagem encriptada: " << encriptados << endl;
}

int main(){
    string frase;
    int chave;

    cout << "Digite a frase que deseja encriptar (apenas letras): ";
    getline(cin, frase); //lê a linha inteira

    cout << "Digite a chave (0 a 26): ";
    cin >> chave;

    if (chave < 0 || chave > 26) {
        cout << "Chave inválida. Use um valor entre 0 e 25.\n";
        return 0;
    }

    cifra(frase, chave);

    return 0;
}
