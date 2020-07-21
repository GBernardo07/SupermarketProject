#include <iostream>
#include <fstream>

#include "../include/restaurante.hpp"

Restaurante::Restaurante() {

    vector_supermercado <Produto> cardapio;

    // Recebe os produtos do arquivo csv
    consultarMenu();

    // Definição de array simples que armazena as quantidades vendidas
    setarArrayVendas();

    // Gera o arquivo do caixa final
    gerarCaixa("caixaRestaurante.csv");

}

Restaurante::~Restaurante() {

    encerrarCaixa();
}

void Restaurante::consultarMenu() {

    std::ifstream infile;
    std::string line;

    infile.open("menu.csv");

    cardapio.clear();

    // Para cada linha do arquivo, insere na lista do estoque um produto
    while(!infile.eof()) {

        std::getline(infile, line);

        if (line.substr(0, 3) == "ITE")
            continue;
        
        cardapio.push_back(retornarProdutoRestaurante(line));

    }

    // Por algum motivo ele adiciona um produto a mais do que deveria
    cardapio.pop_back();

}

void Restaurante::setarArrayVendas() {

    qntdVendida = new int[cardapio.getSize()];
    
    for (int i = 0; i < cardapio.getSize(); i++)
        qntdVendida[i] = 0;
}

void Restaurante::mostrarCardapio() {

    std::cout << "\nCardapio\n" << std::endl;

    // Imprime todos os alimentos disponíveis no cardapio
    for (int i = 0; i < cardapio.getSize(); i++) {

        std::cout << cardapio.at(i).nome << std::endl;
        std::cout << "Preço: R$" << cardapio.at(i).preco << "\n" << std::endl;
    }

}

void Restaurante::registrarVenda(Produto vendido) {

    std::ofstream outfile;
    outfile.open("caixaRestaurante.csv", std::ofstream::app);

    outfile << vendido.nome << " vendido" << std::endl;
}

void Restaurante::venda(std::string nome, int qntd) {

    // Procura na lista produto com o codigo requisitado
    for (int i = 0; i < cardapio.getSize(); i++) {
    
        // Achou o produto e verifica se tem estoque suficiente para compra
        if (cardapio.at(i).nome == nome) {
            
            qntdVendida[i]+=qntd;
            totalVendido+=qntd;
            lucro+=(cardapio.at(i).preco)*qntd;

            registrarVenda(cardapio.at(i));
            std::cout << "\nPedido feito\n" << std::endl;
            return;
        }
    }

}

void Restaurante::encerrarCaixa() {

    std::ofstream outfile;
    outfile.open("caixaRestaurante.csv", std::ofstream::app);

    // Registra no arquivo todos os produtos com quantidade vendida maior que zero e o lucro total
    outfile << "\nRelatorio:\n" << std::endl;
    outfile << "Nome, Quantidade vendida" << std::endl;

    for (int i = 0; i < cardapio.getSize(); i++) {

        if (qntdVendida[i] > 0)
            outfile << cardapio.at(i).nome << "," << qntdVendida[i] << std::endl;

    }

    outfile << "\nLucro total:," << lucro << std::endl;

    delete[] qntdVendida;
}

void Restaurante::imprimirOpcoes() {

    std::cout << "\n- Adicionar saldo" << std::endl;
    std::cout << "- Verificar cardapio" << std::endl;
    std::cout << "- Exibir caixa" << std::endl;
    std::cout << "- Ver comanda" << std::endl;
    std::cout << "- Pedir <Nome do alimento>" << std::endl;
    std::cout << "- Checkout\n" << std::endl;

}