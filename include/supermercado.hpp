#ifndef SUPERMERCADO_HPP
#define SUPERMERCADO_HPP

#include "vecsupermarket.hpp"
#include "estabelecimento.hpp"

class Supermercado : public Estabelecimento {

    public: 

    Supermercado();
    ~Supermercado();

    vector_supermercado <Produto> estoque;

    void consultarEstoque();
    void setarArrayVendas();
    void listarProdutos();
    void registrarVenda(Produto vendido);
    void venda(std::string nome);
    void encerrarCaixa();

    void imprimirOpcoes();

};

#endif