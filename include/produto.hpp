#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {

    public:

    Produto();
    ~Produto();

    int codigo, estoqueInicial;
    double preco;
    std::string nome, unidadeMedida;

};

Produto retornarProduto(std::string linha);
Produto retornarProdutoFornecedor(std::string linha);


#endif