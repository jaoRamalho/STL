#include <vector> 
#include <iostream>
using namespace std;

int detecta_sequencia(vector<int> sequencia, vector<int> registrador){
   int state = 0;
   for(int i = 0; i < 7; i++){
        int cont = 0;
        for(int j = 0; j <= i; j++){
            if (sequencia[i] == registrador[j]){
                cont++;
            }
        }
   }
}


int main(){
    std::vector<int> sequencia =  {1, 0, 1, 0, 0, 1, 0};
    std::vector<int> registrador = {0, 0, 0, 0, 0, 0, 0};
    bool exit = false;
    
    
    while(!exit){
        int entrada = 0;
        cin>>entrada;

        std::vector<int> temp = registrador;
        for(int i = 5; i >= 0; i--){
            registrador[i] = temp[i + 1]; 
        }
        registrador[6] = entrada;

        for (auto it : registrador){
            cout<<it<<" ";
        }
        cout<<endl;
        cin >> entrada;
        cout << endl;
        if(entrada == 2){
            cout << detecta_sequencia(sequencia, registrador);
            exit = true;
        }
    }

    return 0;
};