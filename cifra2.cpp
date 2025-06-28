#include <iostream>
#include <string>

using namespace std;

void cifra(string frase, int chave){
    string alfabeto={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string encriptados;
    for(int i = 0; i < frase.size();i++){ 
        if(encriptados[i]==' '){
            continue;
        }   
        for(int j = 0;j < 26;j++){
            if(frase[i] == alfabeto[j]){
                if(j+chave>26){
                    encriptados[i]=alfabeto[(j+chave)%26];
                }
                else{
                    encriptados[i] = alfabeto[j+chave];
                }
            }
            
        }
    }
    for(int i=0;i<frase.size();i++){
        cout<<encriptados[i];
    }
    

}
int main(){
    string frase;
    int chave;

    cout<<"Digite a frase que deseja encriptar: ";
    getline(cin,frase);
    cout<<"Digite a chave de encriptação: ";
    cin>>chave;
    cifra(frase,chave);
    

    return 0;
}