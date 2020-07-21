#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "vecsupermarket.hpp"
#include "supermercado.hpp"

class Fornecedor {

    public:

    vector_supermercado <Produto> estoque;

    Fornecedor();
    ~Fornecedor();

    void consultarEstoque();
    void listarProdutos();
    void repassarProdutos(Supermercado &loja);

};


#endif