#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include "produto.hpp"
#include "vecsupermarket.hpp"

class Estabelecimento {

    public:

    Estabelecimento();
    ~Estabelecimento();

    vector_supermercado <Produto> estoque;
    double lucro;
    int totalVendido, *estoqueAtual;

    void consultarEstoque();
    void gerarCaixa();
    void listarProdutos();
    void venda(int codigo);
    void registrarVenda(Produto vendido);
    void caixa();
    void encerrarCaixa();
    void reabastecer();

};


#endif