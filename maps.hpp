/*------------------------- MAP, UNORDERED_MAP E MULTMAP ------------------------------------------
    (Link para a referencia da microsoft) -
        unordered_map - https://learn.microsoft.com/pt-br/cpp/standard-library/unordered-map?view=msvc-170
        multmap - https://learn.microsoft.com/pt-br/cpp/standard-library/multimap-class?view=msvc-170
        map - https://learn.microsoft.com/pt-br/cpp/standard-library/map-class?view=msvc-170
    O unordered_map em C++ é uma estrutura que armazena pares de chave-valor, 
    assim como o map padrão. A diferença principal é que o unordered_map usa uma 
    tabela hash para armazenar os elementos, enquanto o map usa uma árvore rubro-negra.
    
    Map e unordered_map, não permitem chaves duplicadas. Ou seja, cada chave tem 
    apenas um valor associado, já um multimap cada chave pode estar associada a múltiplos 
    valores. Isso é útil em situações onde você precisa armazenar múltiplos valores 
    para uma única chave.

    - O unordered_map é mais rápido do que o map, mas não é tão flexível quanto o map e multmap. 
    - O unordered_map não mantem os dados ordenados por ordem de incersão igual ao os outros dois.
    - O tempo médio de busca e incersão do unorderead_map é O(1) em quanto no map e multmap é O(log(n)).

    - Os três tem suas vantagens e desvantagens e você que decide qual e onde usa-los.

*/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    unordered_map<int, string> uMap;
    map<int, string> map;
    multimap<int, string> mMap;
    
    //no map e umap pode inserir usando o operador "[]", igual um vetor o multmap não tem esse operador sobrecarregado
    map[1] = "Um";
    uMap[1] = "Um";

    //podemos tbm inserir usando o pair<tipo, tipo> do c++, o "pair" representa um par de valores
    map.insert(pair<int, string>(2, "Dois"));
    uMap.insert(pair<int, string>(2, "Dois"));
    mMap.insert(pair<int, string>(2, "Dois"));

    //para remover chaves 
    map.erase(1);
    uMap.erase(1);
    mMap.erase(1);

    //para retornar os valores da representados pela chave
    cout << map[1] << endl;
    cout << uMap[1] << endl;

    //para retornar os valores representados pela chave
    cout << map.find(1)->second << endl;
    cout << uMap.find(1)->second << endl;
    cout << mMap.find(1)->second << endl;

}