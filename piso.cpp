#include <iostream>

using namespace std;

int Piso(float alfa){
    int piso = 0;

    if(alfa>0){
        for(int i = alfa;i>0;i--){
            piso++;
            
            if(piso == alfa){
                return piso;
            }
        }
        return piso;
    }
    if(alfa<0){
        for(float i = alfa;i<=0;i++){
            piso--;
            if(piso == alfa){
                return piso;
            }
            
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
