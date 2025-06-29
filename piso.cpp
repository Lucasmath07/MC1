#include <iostream>

using namespace std;

int Piso(float alfa) {
    int piso = 0;

    if (alfa >= 0) {
        while (piso <= alfa) {
            piso++;
        }
        return piso - 1;
    } else {
        while (piso > alfa) {
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
