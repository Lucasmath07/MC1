#include <iostream>

using namespace std;

int resto(int dividendo, int divisor){
    
    int res;
    
    if(dividendo < 0){dividendo = dividendo*(-1);}//deixa o dividendo positivo
    if(divisor < 0){divisor = divisor*(-1);}//deixa o divisor positivo

    int divi_dendo = dividendo; //variavel auxiliar para ajudar na divisao
        for(int i = 0;i<divi_dendo/2;i++){
            divi_dendo = divi_dendo - divisor; //usa a definição de divisão a|b se Exite um c t.q. a*c=b.
            if(divi_dendo<divisor){//o resto é obtido quando o dividendo é menor que o divisor
                return divi_dendo;
                break;
            }
        }
    
     
  return 0;
}
int main(){
    int dividendo;
    int divisor;
    cout<<"Digite o dividendo:";
    cin>>dividendo;
    cout<<"Digite o divisor:";
    cin>>divisor;
    
    cout<<resto(dividendo, divisor)<<endl;
    
    return 0;
}
