#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/fornecedor.hpp"
#include "../include/estoque.hpp"

Fornecedor::Fornecedor() {

    vector_supermercado <Produto> estoque;

    consultarEstoque();
}

Fornecedor::~Fornecedor() {


}

// Consulta o arquivo "fornecedor.csv" e insere tudo no vector
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

// Lista os produtos do Fornecedor
void Fornecedor::listarProdutos() {

    std::cout << "\nLista dos Produtos disponíveis no fornecedor\n" << std::endl;
    
    for (int i = 0; i < estoque.getSize(); i++) {

        std::cout << "Produto: " << estoque.at(i).nome << " Qntd: " << estoque.at(i).estoqueInicial << std::endl;

    }

}

// Repassa produtos do fornecedor para a loja
void Fornecedor::repassarProdutos(Estabelecimento &loja) {

    int qntd;
    std::string line;
    
    std::cout << "\nProduto para repasse: ";
    getline(std::cin, line);

    std::cout << "Quantidade: ";
    std::cin >> qntd;
    std::cin.ignore();

    for (int i = 0; i < loja.estoque.getSize(); i++) {
        if (loja.estoque.at(i).nome == line) {
            if (estoque.at(i).estoqueInicial >= qntd) {
                loja.estoqueAtual[i]+=qntd;
                alterarEstoque("estoque.csv", line, loja.estoqueAtual[i]);
                alterarEstoque("fornecedor.csv", line, estoque.at(i).estoqueInicial-qntd);
            }
            else 
                std::cout << "\nNão há estoque disponível no fornecedor\n" << std::endl;
        }
    }
    
    consultarEstoque();

}