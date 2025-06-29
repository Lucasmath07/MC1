#include <iostream>

using namespace std;

int Piso(float numero) {
    int piso = 0;

    if  (numero >= 0) {
        while (piso <= numero) { 
            piso++;
        }
        return piso - 1; //quando numero tem parte decimal piso termina uma unidade maior na parte inteira (ex.:3.7 piso termina 4)
    } else {
        while(piso > numero) {
            piso--;
        }
        return piso; 
    }
}

int main(){
    float a;
    cout<<"Digite o numero para implementar a funcao piso: ";
    cin>>a;
    cout<<"O piso de "<<a<<" eh: "<<Piso(a);

    return 0;

}
