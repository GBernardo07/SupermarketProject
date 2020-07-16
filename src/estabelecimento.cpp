#include <fstream>
#include <string>
#include <iostream>

#include "../include/produto.hpp"
#include "../include/estabelecimento.hpp"

Estabelecimento::Estabelecimento() : lucro(0), totalVendido(0) {

    std::list <Produto> estoque;

    // Recebe os produtos do arquivo csv
    consultarEstoque();

    // Gera o arquivo do caixa final
    gerarCaixa();
}

Estabelecimento::~Estabelecimento() {

    // Encerra o caixa e termina o arquivo caixa.csv
    encerrarCaixa();

}

void Estabelecimento::consultarEstoque() {

    std::ifstream infile;
    std::string line;

    infile.open("estoque.csv");

    // Para cada linha do arquivo, insere na lista do estoque um produto
    while(!infile.eof()) {

        std::getline(infile, line);

        if (line.substr(0, 3) == "COD")
            continue;
        
        estoque.push_back(retornarProduto(line));

    }

    // Por algum motivo ele adiciona um produto a mais do que deveria
    estoque.pop_back();
}

void Estabelecimento::listarProdutos() {

    std::cout << "\nLista dos Produtos disponíveis\n" << std::endl;

    // Imprime todos os produtos disponíveis no estoque e seus atributos
    for (auto it = estoque.begin(); it != estoque.end(); it++) {

        std::cout << "Produto " << (*it).codigo << std::endl;

        std::cout << "Nome: " << (*it).nome << std::endl;
        std::cout << "Preço: R$" << (*it).preco << std::endl;
        std::cout << "Unidade de Medida: " << (*it).unidadeMedida << std::endl;
        std::cout << "Quantidade disponível: " << (*it).qntdDisponivel << "\n" << std::endl;
    }
}

// Gera o arquivo do caixa
void Estabelecimento::gerarCaixa() {

    std::ofstream outfile;
    outfile.open("caixa.csv");

    outfile << "Caixa Geral \n" << std::endl;

}

// Registra no arquivo do caixa um "log" de vendas
void Estabelecimento::registrarVenda(Produto vendido) {

    std::ofstream outfile;
    outfile.open("caixa.csv", std::ofstream::app);

    outfile << vendido.qntdVendida << " " << vendido.nome << " vendido" << std::endl;

}

// Operacao de venda para o sistema do estabelecimento
void Estabelecimento::venda(int codigo) {

    // Procura na lista produto com o codigo requisitado
    for (auto it = estoque.begin(); it != estoque.end(); it++) {

        // Achou o produto e verifica se tem estoque suficiente para compra
        if ((*it).codigo == codigo && (*it).qntdDisponivel > 0) {

            (*it).qntdDisponivel--;
            (*it).qntdVendida++;
            totalVendido++;
            lucro+=(*it).preco;
            
            registrarVenda((*it));
            std::cout << "\nMercadoria retirada do estoque com sucesso!\n" << std::endl;
            return;
        }
    }

    std::cout << "\nNao há estoque para compra.\n" << std::endl;
}

// Imprime as últimas operações do caixa
void Estabelecimento::caixa() {

    // Pro caso de nada ter sido vendido ainda
    if (totalVendido == 0) {
        std::cout << "Nada foi vendido\n" << std::endl;
        return;
    }

    std::cout << "Foi vendido: \n" << std::endl;

    // Procura na lista do estoque algo com quantidade de vendas maior que zero
    for (auto it = estoque.begin(); it != estoque.end(); it++) {

        if ((*it).qntdVendida > 0)
            std::cout << (*it).qntdVendida << " unidade(s) de " << (*it).nome << std::endl;

    }

    std::cout << "Lucro total: R$" << lucro << "\n" << std::endl;

}

void Estabelecimento::encerrarCaixa() {

    std::ofstream outfile;
    outfile.open("caixa.csv", std::ofstream::app);

    // Registra no arquivo todos os produtos com quantidade vendida maior que zero e o lucro total
    outfile << "\nRelatorio:\n" << std::endl;
    outfile << "Codigo, Nome, Quantidade vendida" << std::endl;

    for (auto it = estoque.begin(); it != estoque.end(); it++) {

        if ((*it).qntdVendida > 0)
            outfile << (*it).codigo << "," << (*it).nome << "," << (*it).qntdVendida << std::endl;

    }

    outfile << "\nLucro total:," << lucro << std::endl;

}