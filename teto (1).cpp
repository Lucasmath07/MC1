#include <iostream>

using namespace std;

float Teto(float alfa){
    int teto = 0;
    float a = alfa;

//Descobre qual é o valor da parte inteira do alfa e soma +1
    
    while(a>=1){
       a--;
       teto++;
    }
    if(teto==alfa){
            return teto;
        }
    if(teto != alfa){
            return teto+1;
        }
    return 0;
}
int main(){
    float a;
    cout<<"Digite o numero para aplicar a funçao teto: ";
    cin >> a;
    cout<<"O teto de "<<a<<" eh: "<<Teto(a)<<endl;
    return 0;
}