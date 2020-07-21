#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {

    public:

    Produto();
    ~Produto();

    int codigo, estoqueAtual;
    double preco;
    std::string nome, unidadeMedida;

};

Produto retornarProdutoSupermercado(std::string linha);
Produto retornarProdutoRestaurante(std::string linha);
Produto retornarProdutoFornecedor(std::string linha);


#endif