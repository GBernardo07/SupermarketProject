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
    int totalVendido, *qntdVendida;

    void consultarEstoque();
    void gerarCaixa();
    void listarProdutos();
    void venda(std::string nome);
    void registrarVenda(Produto vendido);
    void caixa();
    void encerrarCaixa();
    void reabastecer();
    void setarArrayVendas();

};


#endif