#include <fstream>
#include <iostream>

#include "../include/supermercado.hpp"
#include "../include/estoque.hpp"

Supermercado::Supermercado() {

    vector_supermercado <Produto> estoque;

    // Recebe os produtos do arquivo csv
    consultarEstoque();

    // Definição de array simples que armazena as quantidades vendidas
    setarArrayVendas();

    // Gera o arquivo do caixa final
    gerarCaixa("caixaSupermercado.csv");
}

Supermercado::~Supermercado() {

    // Encerra o caixa e termina o arquivo caixa.csv
    encerrarCaixa();

}

void Supermercado::consultarEstoque() {

    std::ifstream infile;
    std::string line;

    infile.open("estoque.csv");

    estoque.clear();

    // Para cada linha do arquivo, insere na lista do estoque um produto
    while(!infile.eof()) {

        std::getline(infile, line);

        if (line.substr(0, 3) == "COD")
            continue;
        
        estoque.push_back(retornarProdutoSupermercado(line));

    }

    // Por algum motivo ele adiciona um produto a mais do que deveria
    estoque.pop_back();

}

void Supermercado::setarArrayVendas() {

    qntdVendida = new int[estoque.getSize()];
    
    for (int i = 0; i < estoque.getSize(); i++)
        qntdVendida[i] = 0;

}

void Supermercado::listarProdutos() {

    std::cout << "\nLista dos Produtos disponíveis\n" << std::endl;

    // Imprime todos os produtos disponíveis no estoque e seus atributos
    for (int i = 0; i < estoque.getSize(); i++) {

        std::cout << "Produto " << estoque.at(i).codigo << std::endl;

        std::cout << "Nome: " << estoque.at(i).nome << std::endl;
        std::cout << "Preço: R$" << estoque.at(i).preco << std::endl;
        std::cout << "Unidade de Medida: " << estoque.at(i).unidadeMedida << std::endl;
        std::cout << "Quantidade disponível: " << estoque.at(i).estoqueAtual << "\n" << std::endl;
    }
}

// Registra no arquivo do caixa um "log" de vendas
void Supermercado::registrarVenda(Produto vendido) {

    std::ofstream outfile;
    outfile.open("caixaSupermercado.csv", std::ofstream::app);

    outfile << estoque.at(vendido.codigo-1).codigo << " " << vendido.nome << " vendido" << std::endl;

}

// Operacao de venda para o sistema do estabelecimento
void Supermercado::venda(std::string nome) {

    // Procura na lista produto com o codigo requisitado
    for (int i = 0; i < estoque.getSize(); i++) {
    
        // Achou o produto e verifica se tem estoque suficiente para compra
        if (estoque.at(i).nome == nome && estoque.at(i).estoqueAtual > 0) {
            
            qntdVendida[i]++;
            totalVendido++;
            lucro+=estoque.at(i).preco;

            //Funcao que mexe no respectivo arquivo
            alterarEstoque("estoque.csv", nome, estoque.at(i).estoqueAtual-1);
            registrarVenda(estoque.at(i));
            std::cout << "\nMercadoria retirada do estoque com sucesso!\n" << std::endl;
            return;
        }
    }

    std::cout << "\nNão há estoque para compra.\n" << std::endl;
}

void Supermercado::encerrarCaixa() {

    std::ofstream outfile;
    outfile.open("caixaSupermercado.csv", std::ofstream::app);

    // Registra no arquivo todos os produtos com quantidade vendida maior que zero e o lucro total
    outfile << "\nRelatorio:\n" << std::endl;
    outfile << "Codigo, Nome, Quantidade vendida" << std::endl;

    for (int i = 0; i < estoque.getSize(); i++) {

        if (qntdVendida[i] > 0)
            outfile << estoque.at(i).codigo << "," << estoque.at(i).nome << "," << qntdVendida[i] << std::endl;

    }

    outfile << "\nLucro total:," << lucro << std::endl;

    delete[] qntdVendida;
}

// Funcao para imprimir as opcoes do usuário
void Supermercado::imprimirOpcoes() {

    std::cout << "\n- Adicionar saldo" << std::endl;
    std::cout << "- Verificar produtos" << std::endl;
    std::cout << "- Listar fornecedor" << std::endl;
    std::cout << "- Reabastecer estoque" << std::endl;
    std::cout << "- Exibir caixa" << std::endl;
    std::cout << "- Ver sacola" << std::endl;
    std::cout << "- Comprar <Nome do Produto>" << std::endl;
    std::cout << "- Checkout\n" << std::endl;

}