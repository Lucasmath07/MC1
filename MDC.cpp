#include <iostream>

using namespace std;
int MDC(int a, int b){
    if(a == 0){
        cout<<"ERRO! O MDC de "<<b<<" e 0 eh indefinido. ERRO!\n";
        return 0;
    }
    if(b == 0){
        cout<<"ERRO! O MDC de "<<a<<" e 0 eh indefinido. ERRO!\n";
        return 0;
    }
    int mdc;
    int res;

   

    int maior = b;
    int menor = a;

    if(a>b){
        maior=a;
        menor=b;
    }
    if(menor<0){menor = menor*-1;}
    if(maior<0){maior = maior*-1;}
    res = maior%menor;
    cout<<maior<<" / "<<menor<<" = "<<maior/menor<<" e o resto eh: "<<res<<endl;
    while(maior%menor != 0){
        
        res = maior%menor;
        maior=menor;
        menor = res;
        cout<<maior<<" / "<<menor<<" = "<<maior/menor<<" e o resto eh: "<<maior%menor<<endl;
    }
    if(maior%menor==0){
        cout<<"O MDC de "<<a<<" e "<<b<< " eh: "<<menor<<endl;
    }
    return 0;
    

}
int main(){
    int a,b;
    cout<<"Digite os dois numeros que deseja calcular o MDC: ";
    cin>>a;
    cin>>b;
    MDC(a,b);

    return 0;
}