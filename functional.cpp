/*-------------------------------------- FUNCTIONAL -----------------------------------------------------------
    (Link para a referencia da microsoft) - https://learn.microsoft.com/pt-br/cpp/standard-library/functional-functions?view=msvc-170
    
    - std::function é um tipo para usar funções como objetos, abaixo vemos coisas
    que podemos faser com essa estrutura:
        
        [1] - Armazenar funções em uma variavel.
                (Utilidade) - Flexibilidade: Você pode decidir em tempo de execução
                qual função executar. Por exemplo, você pode ter várias funções que
                realizam operações diferentes e escolher qual delas executar com base
                em alguma condição.
                 
        [2] - Passar funções como argumentos de outras funções.
                (Utilidade) - Se você armazenar uma função em uma variável, pode passá-la
                como argumento para outra função. Isso é útil em muitos cenários, como 
                funções de ordem superior, callbacks, etc.

        [3] - Retornar funções como resultado de outras funções.
                (Utilidade) - Você pode ter uma função que retorna diferentes funções com base
                em algum parâmetro. Isso permite que você configure o comportamento de um pedaço 
                de código em tempo de execução (Function factories).

        [4] - Usar funções em uma estrutura de dados. Exemplo um vetor de funções. 
                (Utilidade) - Permite melhor legibilidade do código. Por exemplo, tenho 
                uma lista de funções e eu quero executar cada uma dessas funções. Exemplo 2, 
                tenho um conjunto de funcoes mapeadas (map) e dependendo do meu conjunto de chaves
                chamo funções diferentes. 

*/
//---------------------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include <map>

/*-------------------------------------------------- [ 1 ] -------------------------------------------

    Abaixo existe a "funcao1" que retorna void e não recebe nada, nela declarei uma 
    variavel chamada "var" do tipo function<void(void)> e atribui a funcao1. Agora
    eu posso usar a variavel "var" como se fosse a funcao1.

    Para declararmos uma variavel do tipo function precisamos estabelecer o retorno e
    os parametros que a funcao recebe, fazemos isso dentro dos "< >" -> "<retorno<parametro1, parametro2>.  
*/

void funcao1(){
    std::function<void(void)> var = funcao1;

    //podemos usar tbm funcoes lambdas.  
    std::function<int(int, int)> soma = [](int a, int b){ return a + b; };
    std::cout<< soma(8, 10) << std::endl; // exibe a soma de 8 + 10   
};
//---------------------------------------------------------------------------------------------------

/*------------------------------------- [ 2 ] ------------------------------------------------------ 
    Na programação a funcao2 é uma função de  ordem superior, ou seja, 
    uma função que recebe outra função como parâmetro.
*/

void funcao2(std::function<int(int, int)> operacao){
    std::vector<int> listaNumeros = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int resultado = 0; 
    for(auto n : listaNumeros){
        resultado = operacao(resultado, n); //estou usando a funcao passada como parametro para fazer a operacao
    }

    std::cout<< resultado << std::endl; // se for a funcao soma ele soma todos os numeros da lista
};

//---------------------------------------------------------------------------------------------------

/*----------------------------------------- [ 3 ] --------------------------------------------------- 
    COLOQUEI MOTIVOS PARA USAR O [3]

    Manipulação de estado: Se você tem um sistema com vários estados possíveis e cada
    estado requer um tratamento diferente, você pode usar uma função como essa para obter
    a função de tratamento apropriada para cada estado. Isso torna o código mais modular
    e fácil de manter.

    Encapsulamento de lógica: Cada função retornada encapsula a lógica para lidar com um estado
    específico. Isso mantém a lógica para cada estado bem separada e organizada.

    Retardo da execução: A função retornada não é executada imediatamente, mas apenas quando
    é chamada. Isso permite que você prepare a resposta para um estado específico, mas retarde
    sua execução até que seja realmente necessário.
*/

std::function<void(void)> funcao3(int estado, std::vector<int> vetor3pos){

    if(estado == 0) { return [](){ std::cout<<"FUNCAO QUE TRATA ESTADO 0"<<std::endl; }; }
    else if(estado == 1) { return [](){ std::cout<<"FUNCAO QUE TRATA ESTADO 1"<<std::endl; }; }
    else if(estado == 2) { return [](){ std::cout<<"FUNCAO QUE TRATA ESTADO 2"<<std::endl; }; }
    
    return [](){ std::cout<<"FUNCAO QUE TRATA ESTADO DIVERSO"<<std::endl; };
};

//---------------------------------------------------------------------------------------------------

/* --------------------------------------------- [ 4 ] ---------------------------------------------
    
    Obbs : Usei no meu jogo para mapear funções e devia ter usado para executar varias funcoes em vector. 
*/

// Declarando uma entidade a fim de exemplo;    
class Entidade{ 
    public:
        Entidade(){} 
        std::string getTipo() { 
            int n = rand()%3;
            if(n == 0) return "Jogador";
            else if (n == 1) return "Projetil";
            else return "Inimigo";
        }
};

void funcao4(){
    std::vector<std::function<void(void)>> listaFuncoes;

    for(auto funcao : listaFuncoes){
        funcao();    // estou executando todas as funcoes da lista sem ter que chamar uma por uma.
    }

    //posso usar em um map tbm, estou mapeando os tipos de colisoes 
    std::map<std::string, std::function<void(Entidade*, Entidade*)>> mapColisoes;
    mapColisoes["Projetil e Plataforma"] = [](Entidade* proj, Entidade* plat) { std::cout << "Colisao pp" << std::endl; };
    mapColisoes["Projetil e Inimigo"] = [](Entidade* proj, Entidade* ini) { std::cout << "Colisao pi" << std::endl; };
    mapColisoes["Projetil e Jogador"] = [](Entidade* proj, Entidade* jog) { std::cout << "Colisao pj" << std::endl; };

    Entidade ent1, ent2;
    std::string tipo_de_colisao =  ent1.getTipo() + " e " + ent2.getTipo(); //tipo de colisao aleatória;
    mapColisoes[tipo_de_colisao](&ent1, &ent2); //em vez de fazer um bloco de if's para achar a colisao apenas boto no map; 
};
//------------------------------------------------------------------------------------------------------
