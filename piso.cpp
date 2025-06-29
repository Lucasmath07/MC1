#include <iostream>

using namespace std;

int Piso(float numero) {
    int piso = 0;

    if  (numero >= 0) {
        while (piso <= numero) {
            piso++;
        }
        return piso - 1;
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
