#pragma once
#include <iostream>

class Entidade {
    private:
        int posX, posY;
        int largura, altura;

    public:
        Entidade(int posX, int posY, int largura, int altura) : posX(posX), posY(posY), largura(largura), altura(altura){}
        Entidade() : posX(0), posY(0), largura(0), altura(0){}
        ~Entidade() {}
        
        void mover(){}
        void execute(){ mover(); }
};