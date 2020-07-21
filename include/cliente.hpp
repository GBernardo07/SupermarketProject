#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "produto.hpp"
#include "vecsupermarket.hpp"

class Cliente {

    public:

    Cliente();
    ~Cliente();

    static int qntdClientes;
    int numeroCliente;
    std::string nome;
    double saldo;
    vector_supermercado <Produto> compras;

    void registro(int numero);
    void adicionarSaldo();
    void compra(Produto item, int qntd);
    void verCompras();

};


#endif