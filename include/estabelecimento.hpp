#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "produto.hpp"
#include "vecsupermarket.hpp"

class Estabelecimento {

    public:

    Estabelecimento();
    ~Estabelecimento();

    double lucro;
    int totalVendido, *qntdVendida;

    void gerarCaixa(std::string filename);
    void caixa(vector_supermercado <Produto> vetor);

};

#endif