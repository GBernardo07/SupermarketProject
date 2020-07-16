#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/fornecedor.hpp"

Fornecedor::Fornecedor() {

    vector_supermercado <Produto> estoque;

    consultarEstoque();
}

Fornecedor::~Fornecedor() {


}

void Fornecedor::consultarEstoque() {

    std::ifstream infile;
    std::string line;

    infile.open("fornecedor.csv");

    while(!infile.eof()) {

        std::getline(infile, line);

        if (line.substr(0, 3) == "PRO")
            continue;
        
        estoque.push_back(retornarProdutoFornecedor(line));

    }

    estoque.pop_back();
}

void Fornecedor::listarProdutos() {

    std::cout << "\nLista dos Produtos disponíveis no fornecedor\n" << std::endl;
    for (int i = 0; i < estoque.getSize(); i++) {

        std::cout << "Produto: " << estoque.at(i).nome << " Qntd: " << std::endl;

    }

}

void Fornecedor::repassarProdutos(Estabelecimento &loja) {



}