#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

class Entidade;

int main(){
    std::vector<Entidade*> vetor;
    std::list<int> lista = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Doubly linked list
    std::stack<int> pilha; // Last In First Out
    std::queue<int> fila; // First In First Out

    for (auto ent : vetor){
        //iterando sobre o vetor
        //Entidade->execute();
    }

    return 0;
}

