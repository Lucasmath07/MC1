#include <iostream>

using namespace std;

int div_alg(int a, int b){
    int cont=0;
    if(a<0){ a = -a; cont++;}
    if(b<0){ b = -b; cont++;}
    int r = a;
    int quociente = 0;

    while(r>=b){
        quociente++;
        r=r-b;
    }
    if(cont!=1){
        if(r!=0){
            cout<<"A divisao nao eh possivel nos numeros inteiros, pois deixa resto: "<<r<<endl;
            return 0;
        }
        cout<<"O quociente da divisao eh: "<<quociente<<endl;
        return 0;
    }
    else{
        if(r!=0){
            cout<<"A divisao nao eh possivel nos numeros inteiros, pois deixa resto: "<<r<<endl;
            return 0;
        }
        quociente = -quociente;
        cout<<"O quociente da divisao eh: "<<quociente<<endl;
        return 0;

    }
}
int main(){
    int a,b;
    cout<<"Digite o dividendo: ";
    cin>>a;
    cout<<"Digite o divisor: ";
    cin>>b;
    div_alg(a,b);
    return 0;
}