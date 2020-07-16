#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <vector>

#include "produto.hpp"

class Cliente {

    public:

    Cliente();
    ~Cliente();

    static int qntdClientes;
    int numeroCliente;
    std::string nome;
    double saldo;
    std::vector <Produto> sacola;

    void registro(int numero);
    void adicionarSaldo();
    void compra(Produto item);
    void verSacola();

};


#endif