#include <fstream>
#include <string>
#include <iostream>

#include "../include/produto.hpp"
#include "../include/estabelecimento.hpp"
#include "../include/estoque.hpp"

Estabelecimento::Estabelecimento() : lucro(0), totalVendido(0) {

    
}

Estabelecimento::~Estabelecimento() {


}

// Gera o arquivo do caixa
void Estabelecimento::gerarCaixa(std::string filename) {

    std::ofstream outfile;
    outfile.open(filename);

    outfile << "Caixa Geral \n" << std::endl;

}

// Imprime as últimas operações do caixa
void Estabelecimento::caixa(vector_supermercado <Produto> vetor) {

    // Pro caso de nada ter sido vendido ainda
    if (totalVendido == 0) {
        std::cout << "Nada foi vendido\n" << std::endl;
        return;
    }

    std::cout << "Foi vendido: \n" << std::endl;

    // Procura na lista do estoque algo com quantidade de vendas maior que zero
    for (int i = 0; i < vetor.getSize(); i++) {

        if (qntdVendida[i] > 0)
            std::cout << qntdVendida[i] << " unidade(s) de " << vetor.at(i).nome << std::endl;

    }

    std::cout << "Lucro total: R$" << lucro << "\n" << std::endl;

}