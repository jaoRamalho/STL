/*---------------------- SET, UNORDERED_SET, MULTISET E UNORDERED_MULTISET ------------------------------------------
    (Link para a referencia da microsoft) -
       set - https://learn.microsoft.com/pt-br/cpp/standard-library/set-class?view=msvc-170
       unordered_set - https://learn.microsoft.com/pt-br/cpp/standard-library/unordered-set-class?view=msvc-170
       multiset - https://learn.microsoft.com/pt-br/cpp/standard-library/multiset-class?view=msvc-170
       unordered_multiset - https://learn.microsoft.com/pt-br/cpp/standard-library/unordered-multiset-class?view=msvc-170

        A estrutura de dados "set" em C++ é uma estrutura de dados do tipo contêiner
        que armazena elementos únicos em nenhuma ordem específica. Cada elemento deve
        ser único porque os valores no conjunto "set" são como chaves em um mapa onde 
        cada chave é única.

    - set:
        - Os elementos em um "set" são sempre ordenados (por padrão, em ordem crescente).
        - Todos os elementos em um "set" são sempre únicos.
        - Inserir e remover elementos em um set tem uma complexidade de O(long(n)), pois 
        são organizado em uma arvore red-black.
    
    - unordered_set :
        - Possui a maioria das caracteristicas do set. Diferenças a seguir.
        - Inserir e remover elementos em um unordered_set tem uma complexidade de O(1), pois
        são organizado em uma tabela hash.
        - Os elementos em um unordered_set não são ordenados.
    
    - multiset:
        - Todas as caracteristicas do set, porém os elementos em um multiset podem ser repetidos.
    
    - unordered_multiset:
        - Todas as caracteristicas do unordered_set, porém os elementos em um unordered_multiset podem ser repetidos.
*/

//------------------------------ EXEMPLO DE UTILIZAÇÃO --------------------------------------------------------

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    set<int> s;
    unordered_set<int> us;
    multiset<int> ms;
    unordered_multiset<int> ums;

    //Inserindo elementos no set, unordered_set, multiset e unordered_multiset.
    s.insert(1);
    us.insert(2);
    ms.insert(3);
    ums.insert(4);

    int x = 0;
    //Exibindo o elemento na posição x do set (serve para todos). 
    auto it = s.find(x);
    if( it != s.end() ) { cout << *it << endl; }
    else { cout << "Elemento não encontrado" << endl; }
    
    //Removendo o elemento x do set (serve para todos, para os casos do mset e umset ele remove todas as ocorrencias)
    s.erase(x);
}

