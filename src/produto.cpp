#include <sstream>
#include <iostream>
#include <vector>

#include "../include/produto.hpp"

Produto::Produto() : codigo(0), qntdDisponivel(0), qntdVendida(0), preco(0),
    nome(""), unidadeMedida("") {
    
}

Produto::~Produto() {


}

// Funcao que recebe uma linha do arquivo de estoque e retorna um produto
Produto retornarProduto(std::string linha) {

    int counter = 0;
    char trash;
    std::stringstream stream(linha);
    std::string word;
    Produto aux;

    // Retira cada palavra que está entre vírgulas e insere no lugar correto do objeto Produto
    while(getline(stream, word, ',')) {

        switch (counter) {
            case 0:
                aux.codigo = std::stoi(word);
                break;
            case 1:
                aux.nome = word;
                break;
            case 2:
                aux.unidadeMedida = word;
                break;

            // Como há uma vírgula no preço do arquivo, foi necessario dividir em duas partes:
            // A inteira,
            case 3:
                aux.preco += stod(word.erase(0,4));
                break;
            // E a decimal
            case 4:
                aux.preco += stod(word) / 100;
            case 5:
                aux.qntdDisponivel = stoi(word);
            default:
                break;
        }
        /* O contador conta quantas vírgulas já se passaram, 
            e assim definimos com que informação
            estamos lidando no momento */
        counter++;
    }

    return aux;
}