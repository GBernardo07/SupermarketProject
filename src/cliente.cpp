#include "../include/cliente.hpp"

#include <iostream>
#include <fstream>

Cliente::Cliente() : saldo(300) {

    vector_supermercado <Produto> compras;
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
void Cliente::compra(Produto item, int qntd) {

    if (saldo >= (item.preco)*qntd) {
        saldo-=(item.preco)*qntd;

        for (int i = 0; i < qntd; i++)
            compras.push_back(item);
            
        //std::cout << "\nComprado com sucesso!\n" << std::endl;
    }
    else
        std::cout << "\nNão há saldo suficiente.\n" << std::endl;


}

// Exibe a sacola completa
void Cliente::verCompras() {

    if (compras.getSize() == 0) {
        std::cout << "Nada foi comprado\n" << std::endl;
        return;
    }

    std::cout << "Compras: " << std::endl;

    for (int i = 0; i < compras.getSize(); i++)
        std::cout << "- " << compras.at(i).nome << std::endl;

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
    for (int i = 0; i < compras.getSize(); i++)
        outfile << "- " << compras.at(i).nome << std::endl;

    outfile << "\n";

}