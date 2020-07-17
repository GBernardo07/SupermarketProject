#include <fstream>
#include <string>
#include <iostream>

#include "../include/produto.hpp"
#include "../include/estabelecimento.hpp"
#include "../include/estoque.hpp"

Estabelecimento::Estabelecimento() : lucro(0), totalVendido(0) {

    vector_supermercado <Produto> estoque;

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
    estoqueAtual = new int[estoque.getSize()];

    for (int i = 0; i < estoque.getSize(); i++)
        estoqueAtual[i] = estoque.at(i).estoqueInicial;
}

void Estabelecimento::listarProdutos() {

    std::cout << "\nLista dos Produtos disponíveis\n" << std::endl;

    // Imprime todos os produtos disponíveis no estoque e seus atributos
    for (int i = 0; i < estoque.getSize(); i++) {

        std::cout << "Produto " << estoque.at(i).codigo << std::endl;

        std::cout << "Nome: " << estoque.at(i).nome << std::endl;
        std::cout << "Preço: R$" << estoque.at(i).preco << std::endl;
        std::cout << "Unidade de Medida: " << estoque.at(i).unidadeMedida << std::endl;
        std::cout << "Quantidade disponível: " << estoqueAtual[i] << "\n" << std::endl;
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

    outfile << estoque.at(vendido.codigo-1).codigo << " " << vendido.nome << " vendido" << std::endl;

}

// Operacao de venda para o sistema do estabelecimento
void Estabelecimento::venda(std::string nome) {

    // Procura na lista produto com o codigo requisitado
    for (int i = 0; i < estoque.getSize(); i++) {
    
        // Achou o produto e verifica se tem estoque suficiente para compra
        if (estoque.at(i).nome == nome && estoqueAtual[i] > 0) {
            
            estoqueAtual[i]--;
            totalVendido++;
            lucro+=estoque.at(i).preco;
            alterarEstoque("estoque.csv", nome, estoqueAtual[i]);
            registrarVenda(estoque.at(i));
            std::cout << "\nMercadoria retirada do estoque com sucesso!\n" << std::endl;
            return;
        }
    }

    std::cout << "\nNão há estoque para compra.\n" << std::endl;
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
    for (int i = 0; i < estoque.getSize(); i++) {

        if (estoque.at(i).estoqueInicial - estoqueAtual[i] > 0)
            std::cout << estoque.at(i).estoqueInicial - estoqueAtual[i] << " unidade(s) de " << estoque.at(i).nome << std::endl;

    }

    std::cout << "Lucro total: R$" << lucro << "\n" << std::endl;

}

void Estabelecimento::encerrarCaixa() {

    std::ofstream outfile;
    outfile.open("caixa.csv", std::ofstream::app);

    // Registra no arquivo todos os produtos com quantidade vendida maior que zero e o lucro total
    outfile << "\nRelatorio:\n" << std::endl;
    outfile << "Codigo, Nome, Quantidade vendida" << std::endl;

    for (int i = 0; i < estoque.getSize(); i++) {

        if (estoque.at(i).estoqueInicial - estoqueAtual[i] > 0)
            outfile << estoque.at(i).codigo << "," << estoque.at(i).nome << "," << estoque.at(i).estoqueInicial - estoqueAtual[i] << std::endl;

    }

    outfile << "\nLucro total:," << lucro << std::endl;

}