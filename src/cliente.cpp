#include "../include/cliente.hpp"

#include <iostream>
#include <fstream>

Cliente::Cliente() : saldo(300) {

    vector_supermercado <Produto> sacola;
    qntdClientes++;
    numeroCliente = qntdClientes;
}

Cliente::~Cliente() {
    
    // Recebe o numero do cliente de acordo com a ordem como foi construído
    // e gera um arquivo com esse número
    registro(numeroCliente);
}

int Cliente::qntdClientes {0};

// Recebe um produto como parâmetro, insere na sacola e diminui o saldo do cliente
void Cliente::compra(Produto item) {

    if (saldo >= item.preco) {
        saldo-=item.preco;
        sacola.push_back(item);
        std::cout << "\nMercadoria adicionada à sacola com sucesso!\n" << std::endl;
    }
    else
        std::cout << "\nNão há saldo suficiente.\n" << std::endl;


}

// Exibe a sacola completa
void Cliente::verSacola() {

    if (sacola.getSize() == 0) {
        std::cout << "Nao ha itens na sacola\n" << std::endl;
        return;
    }

    std::cout << "Sacola: " << std::endl;

    for (int i = 0; i < sacola.getSize(); i++)
        std::cout << "- " << sacola.at(i).nome << std::endl;

    std::cout << "\n";

}

// Adiciona mais saldo para o cliente
void Cliente::adicionarSaldo() {

    double aumento;
    std::cout << "Insira a quantidade: ";
    std::cin >> aumento;
    std::cin.ignore();
    saldo+=aumento;
    std::cout << "Novo saldo: R$" << saldo << "\n" << std::endl;
}

// Registra num txt as sacolas dos clientes
void Cliente::registro(int numero) {

    std::ofstream outfile;
    std::string filename, newfilename;

    filename = "cliente_";
    filename.append(std::to_string(numero));
    filename.append(".txt");

    outfile.open(filename);
        
    outfile << "Registro do cliente " << numero << "\n" << std::endl;
    for (int i = 0; i < sacola.getSize(); i++)
        outfile << "- " << sacola.at(i).nome << std::endl;

    outfile << "\n";

}