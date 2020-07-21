#ifndef RESTAURANTE_HPP
#define RESTAURANTE_HPP

#include "vecsupermarket.hpp"
#include "estabelecimento.hpp"

class Restaurante : public Estabelecimento {

    public:

    Restaurante();
    ~Restaurante();

    vector_supermercado <Produto> cardapio;

    void consultarMenu();
    void setarArrayVendas();
    void mostrarCardapio();
    void registrarVenda(Produto vendido);
    void venda(std::string nome, int qntd);
    void encerrarCaixa();

    void imprimirOpcoes();

};

#endif