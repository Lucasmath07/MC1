#include <iostream>

using namespace std;

int divisao(int dividendo,int divisor){
    
        if((dividendo >= 0 && divisor >0) ){
            for(int c = 1;c<=dividendo;c++){
                if(divisor*c==dividendo){
                    return c;
                }
        
            }
        }
        if((dividendo < 0 && divisor <0) ){
            for(int c = 1;c<=dividendo*-1;c++){
                if(divisor*c==dividendo){
                    return c;
                }
        
            }
        }
        if(dividendo < 0 && divisor > 0){
            for(int c = -1;c>=dividendo;c--){
                if(divisor*c==dividendo){
                    return c;
                }
            }
        }   
         if(dividendo > 0 && divisor < 0){
            for(int c = -1;c>=dividendo*-1;c--){
                if(divisor*c==dividendo){
                    return c;
                }
            }
        }
    return 0;
    
}

int main(){
    int divisor,dividendo;
    cin>>dividendo;
    cin>>divisor;
    if(divisor != 0){
    cout<<divisao(dividendo,divisor)<<endl;
    }
    else{
        cout<<"Nao e possivel dividir por zero! \n";
    }
    return 0;
}
