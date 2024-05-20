/*---------------------- MAP, UNORDERED_MAP, MULTMAP E UNORDERED MULTMAP ------------------------------------------
    (Link para a referencia da microsoft) -
        unordered_map - https://learn.microsoft.com/pt-br/cpp/standard-library/unordered-map?view=msvc-170
        multmap - https://learn.microsoft.com/pt-br/cpp/standard-library/multimap-class?view=msvc-170
        map - https://learn.microsoft.com/pt-br/cpp/standard-library/map-class?view=msvc-170
        unorderead_multmap - https://learn.microsoft.com/pt-br/cpp/standard-library/unordered-multimap?view=msvc-170
    
        O que é a estrutura map em geral (todas as estruturas acima)? 
            - A estrutura map é uma estrutura de dados que armazena pares de chave-valor. 
            - A chave é usada para indexar o valor associado. 
            - Os valores podem ser acessados, inseridos ou removidos usando a chave correspondente. 

        Qual as caracteristicas do:
            - Map classico (map):
                - Cada chave possui apenas um valor associado.
                - Ela é organizada no formato de arvore red-black.
                - Tempo de busca, incerção e remoção é de O(log(n)); (Para fins de comparacão o vector de o tempo de busca de O(n)).

            - Multmap classico (multmap):
                - Cada chave pode ter um ou mais valores associados.
                - Ela é organizada no formato de arvore red-black.
                - Tempo de busca, incerção e remoção é de O(log(n));

            - Map não ordenado (unordered_map):
                - Cada chave possui apenas um valor associado;
                - Ela é organizada no formato de tabela hash;
                - Tempo de busca, incerção e remoção é de O(1); (Tempo constante);
            
            - Multmapa não ordenado (unordered_map):
                - Cada chave pode ter um ou mais valores associados;
                - Ela é organizada no formato de tabela hash;
                - Tempo de busca, incerção e remoção é de O(1); (Tempo constante); 
            

        Quando usar cada um?
            Consta a você decidir quando e onde usá-los, todos tem suas vantagens e desvantagens dependendo do seu uso.  

            Nota joão - "Olha, pessoalmente no jogo do simão eu usei o unorderead_map, pois ele é mais rapido e cumpria o meu objetivo."
*/

//------------------------------ EXEMPLO DE UTILIZAÇÃO --------------------------------------------------------

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    unordered_map<int, string> uMap;
    map<int, string> map;
    multimap<int, string> mMap;
    unordered_multimap<int, string> uMMap;

    //no map e umap pode inserir usando o operador "[]", igual um vetor. (MAP E UNORDERED_MAP)
    map[1] = "Um";
    uMap[1] = "Um";

    //podemos tbm inserir usando o pair<tipo, tipo> do c++, o "pair" representa um par de valores (TODOS)
    map.insert(pair<int, string>(2, "Dois"));
    uMap.insert(pair<int, string>(2, "Dois"));
    mMap.insert(pair<int, string>(2, "Dois"));
    uMMap.insert(pair<int, string>(2, "Dois"));

    //para remover chaves (TODOS) 
    map.erase(1);
    uMap.erase(1);
    mMap.erase(1);
    uMMap.erase(1);

    //para retornar os valores da representados pela chave (MAP E UNORDERED_MAP)
    cout << map[1] << endl;
    cout << uMap[1] << endl;

    //para retornar os valores representados pela chave (TODOS)
    cout << map.find(1)->second << endl;
    cout << uMap.find(1)->second << endl;
    cout << mMap.find(1)->second << endl;
    cout << uMMap.find(1)->second << endl;
}