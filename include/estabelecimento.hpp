#ifndef ESTABELECIMENTO_HPP
#define ESTABELECIMENTO_HPP

#include <list>

#include "produto.hpp"

class Estabelecimento {

    public:

    Estabelecimento();
    ~Estabelecimento();

    std::list <Produto> estoque;
    double lucro;
    int totalVendido;

    void consultarEstoque();
    void gerarCaixa();
    void listarProdutos();
    void venda(int codigo);
    void registrarVenda(Produto vendido);
    void caixa();
    void encerrarCaixa();

};


#endif