#include <iostream>

using namespace std;
bool eh_primo(int a){
    int cont = 0;
    if(a<2){return false;}//caso base se um número é  negativo ele não é primo e se for 0 ou 1 tbm não
    for(int i = 1;i<=a;i++){//conta quantos divisores o numero tem
        if(a%i==0){cont++;}
    }
    if(cont==2){return true;}//se o numero só tem dois divisores significa que ele é primo
    else{return false;}
}
void Primos(int a,int b){
    
    for(int i=a;i<=b;i++){   //define o intervalo
        if(eh_primo(i)){cout<<i<<" ";} //faz a checagem um numero por vez para ver se ele é primo

}

}
int main(){
    int a,b;
    cout<<"Digite o primeiro numero do intervalo: ";
    cin>>a;
    cout<<"Digite o ultimo numero do intervalo: ";
    cin>>b;

    Primos(a,b);
    return 0;
}