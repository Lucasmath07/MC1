#include <iostream>

using namespace std;
int MDC(int a, int b){
    if(a == 0 && b == 0){
        cout<<"ERRO! O MDC de 0 e 0 eh indefinido. ERRO!\n";
        return 0;
    }
    
    int mdc;
    int res;
    int valor_a = a;
    int valor_b = b;
    int maior = b; //variaveis para facilitar a construção logica
    int menor = a;

    if(a>b){
        maior = a;
        menor = b;
    }
    
    if(menor < 0){menor = menor * -1;}
    if(maior < 0){maior = maior * -1;}

    if(valor_a < 0){valor_a = -valor_a;}
    if(valor_b < 0){valor_b = -valor_b;}

    if(a == 0){
        cout << "O MDC de " << a << " e " << b << " eh: " << b << endl;
        return 0;
    }
    if(b == 0){
        cout << "O MDC de " << a << " e " << b << " eh: " << a << endl;
    }
    res = maior % menor;
    cout << maior << " / " << menor << " = " << maior / menor << " e o resto eh: " << res << endl;
    while(maior%menor != 0){
        
        res = maior % menor;
        maior = menor;
        menor = res;
        cout << maior << " / " << menor << " = " << maior / menor << " e o resto eh: " << maior % menor << endl;
    }
    if(maior % menor == 0){
        cout << "O MDC de " << a << " e " << b << " eh: " << menor << endl;
    }
    return 0;
    

}
int main(){
    int a,b;

    cout << "Digite os dois numeros que deseja calcular o MDC: ";
    cin >> a;
    cout << "Digite o proximo numero: ";
    cin >> b;
    MDC(a,b);

    return 0;
}
