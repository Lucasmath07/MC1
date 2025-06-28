#include <iostream>

using namespace std;

int div_alg(int a, int b){
    int cont=0;
    if(a<0){ a = -a; cont++;}
    if(b<0){ b = -b; cont++;}
    int r = a;

    while(r>=b){
        r=r-b;
    }
    cout<<"O resto  da divisao eh:"<<r<<endl;
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