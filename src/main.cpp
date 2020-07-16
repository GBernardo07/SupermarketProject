#include <iostream>
#include <string>

#include "../include/estabelecimento.hpp"
#include "../include/cliente.hpp"

// Funcao para imprimir as opcoes do usuário
void imprimirOpcoes() {

    std::cout << "\n- Adicionar saldo" << std::endl;
    std::cout << "- Verificar produtos" << std::endl;
    std::cout << "- Exibir caixa" << std::endl;
    std::cout << "- Ver sacola" << std::endl;
    std::cout << "- Comprar <codigo do produto>" << std::endl;
    std::cout << "- Checkout\n" << std::endl;

}

int main(int argc, char *argv[]) {

    // Declaração das variáveis gerais
    Estabelecimento lojinha;
    Cliente *novoCliente = new Cliente;
    std::string acao, acao2;

    // Recebe nome do cliente
    std::cout << "Insira seu nome: ";
    std::getline (std::cin, novoCliente->nome);

    // Introdução
    std::cout << "\nBem vindo ao supermercado, " << novoCliente->nome << std::endl;
    std::cout << "Voce tem R$" << novoCliente->saldo << " de saldo!\n" << std::endl;
    std::cout << "Escolha uma opcao: " << std::endl;

    imprimirOpcoes();

    // Loop do menu
    while (true) {

        std::cout << "-> ";
        getline(std::cin, acao);

        // Escolha das opções disponíveis
        if (acao == "Adicionar saldo")
            novoCliente->adicionarSaldo();
        else if (acao == "Verificar produtos")
            lojinha.listarProdutos();
        else if (acao == "Exibir caixa")
            lojinha.caixa();
        else if (acao == "Ver sacola")
            novoCliente->verSacola();
        else if (acao.find("Comprar") != std::string::npos) {

            // Procurar na lista do estoque, o código do produto requisitado
            for (auto it = lojinha.estoque.begin(); it != lojinha.estoque.end(); it++) {

                if ((*it).codigo == stoi(acao.substr(8))) {
                    lojinha.venda(stoi(acao.substr(8)));
                    novoCliente->compra(*it);
                }

            }

        }
        else if (acao == "Checkout") {
            std::cout << "Deseja fazer compras com outro cliente? (s/n)" << std::endl;
            std::cout << "-> ";
            getline(std::cin, acao2);
            if (acao2 == "s") {
                delete novoCliente;
                novoCliente = new Cliente;
            }
            else if (acao2 == "n") {
                delete novoCliente;
                return 0;
            }
            else
                std::cout << "Insira uma opcao valida\n" << std::endl;
        }
        else 
            std::cout << "Insira uma opcao valida\n" << std::endl;

    }

    return 0;
}