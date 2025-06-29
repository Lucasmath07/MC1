#include <iostream>

using namespace std;

int Teto(float alfa){
    int teto = 0;

    if(alfa>0){
        for(int i = alfa;i>=0;i--){
            ++teto;
            //cout<<teto<<endl;
            if(teto == alfa){
                return teto;
            }
        }
    }
    if(alfa<0){
        for(int i = alfa;i<0;i++){
            teto--;
            if(teto == alfa){
                return teto;
            }
            
        }
        return teto;
    }
    
    return teto;
}
int main(){
    float a;
    cout<<"Digite o numero para implementar a funcao teto: ";
    cin>>a;
    cout<<"O teto de "<<a<<" eh: "<<Teto(a);
    return 0;

}
