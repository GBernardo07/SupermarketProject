#include <iostream>
#include <string>

#include "../include/estabelecimento.hpp"
#include "../include/supermercado.hpp"
#include "../include/restaurante.hpp"
#include "../include/cliente.hpp"
#include "../include/fornecedor.hpp"

int main(int argc, char *argv[]) {

    // Declaração das variáveis gerais
    int n;
    Cliente *novoCliente = new Cliente;
    std::string opcao, acao, acao2;

    // Recebe nome do cliente
    std::cout << "Insira seu nome: ";
    std::getline (std::cin, novoCliente->nome);

    std::cout << "\n" << novoCliente->nome << ", escolha uma opcao:" << std::endl;
    std::cout << "- Supermercado" << std::endl;
    std::cout << "- Restaurante" << std::endl;
    std::cout << "-> ";
    std::getline(std::cin, opcao);

    if (opcao == "Supermercado") {

        Fornecedor provedor;
        Supermercado super;

        // Introdução
        std::cout << "\nBem vindo ao supermercado, " << novoCliente->nome << std::endl;
        std::cout << "Voce tem R$" << novoCliente->saldo << " de saldo!\n" << std::endl;
        std::cout << "Escolha uma opcao: " << std::endl;

        super.imprimirOpcoes();

        // Loop do menu
        while (true) {

            std::cout << "-> ";

            getline(std::cin, acao);

            // Escolha das opções disponíveis
            try {

                if (acao == "Adicionar saldo")
                    novoCliente->adicionarSaldo();
                else if (acao == "Verificar produtos")
                    super.listarProdutos();
                else if (acao == "Listar fornecedor")
                    provedor.listarProdutos();
                else if (acao == "Reabastecer estoque")
                    provedor.repassarProdutos(super);
                else if (acao == "Exibir caixa")
                    super.caixa(super.estoque);
                else if (acao == "Ver sacola")
                    novoCliente->verCompras();
                else if (acao.find("Comprar") != std::string::npos) {

                    // Procurar na lista do estoque, o nome do produto requisitado
                    for (int i = 0; i < super.estoque.getSize(); i++) {
                        
                        if (super.estoque.at(i).nome == acao.substr(8)) {
                            super.venda(acao.substr(8));
                            novoCliente->compra(super.estoque.at(i), 1);
                        }
                        
                    }

                    super.consultarEstoque();

                }
                else if (acao == "Checkout") {
                    std::cout << "Deseja fazer compras com outro cliente? (s/n)" << std::endl;
                    std::cout << "-> ";
                    getline(std::cin, acao2);

                    //Muda entre clientes
                    try {
                        if (acao2 == "s") {
                            delete novoCliente;
                            novoCliente = new Cliente;
                        }
                        else if (acao2 == "n") {
                            delete novoCliente;
                            return 0;
                        }
                        else
                            throw("\nInsira uma opcao valida");
                    }
                    catch(const char *S) {
                        std::cout << S << std::endl;
                    }

                }
                else 
                    throw("Insira uma opcao valida\n");

                }

            catch(const char *S) {
                std::cout << S << std::endl;
            }

            super.imprimirOpcoes();
        }

    }

    else if (opcao == "Restaurante") {

        Restaurante rest;

        std::cout << "\nBem vindo ao restaurante, " << novoCliente->nome << std::endl;
        std::cout << "Voce tem R$" << novoCliente->saldo << " de saldo!\n" << std::endl;
        std::cout << "Escolha uma opcao: " << std::endl;

        rest.imprimirOpcoes();

        while (true) {

            std::cout << "-> ";
            getline(std::cin, acao);

            try {

                if (acao == "Adicionar saldo")
                    novoCliente->adicionarSaldo();
                else if (acao == "Verificar cardapio")
                    rest.mostrarCardapio();
                else if (acao == "Exibir caixa")
                    rest.caixa(rest.cardapio);
                else if (acao == "Ver comanda")
                    novoCliente->verCompras();
                else if (acao.find("Pedir") != std::string::npos) {
                    std::cout << "Quantidade: ";
                    std::cin >> n;
                    std::cin.ignore();
                    // Procurar na lista do estoque, o nome do produto requisitado
                    for (int i = 0; i < rest.cardapio.getSize(); i++) {
                        
                        if (rest.cardapio.at(i).nome == acao.substr(6)) {
                            rest.venda(acao.substr(6), n);
                            novoCliente->compra(rest.cardapio.at(i), n);
                        }
                        
                    }

                }
                else if (acao == "Checkout") {
                    std::cout << "Deseja fazer compras com outro cliente? (s/n)" << std::endl;
                    std::cout << "-> ";
                    getline(std::cin, acao2);

                    //Muda entre clientes
                    try {
                        if (acao2 == "s") {
                            delete novoCliente;
                            novoCliente = new Cliente;
                        }
                        else if (acao2 == "n") {
                            delete novoCliente;
                            return 0;
                        }
                        else
                            throw("\nInsira uma opcao valida");
                    }

                    catch(const char *S) {
                        std::cout << S << std::endl;
                    }
                }

                else 
                    throw("Insira uma opcao valida\n");

            }

            catch (const char *S) {
                std::cout << S << std::endl;
            }
            
            rest.imprimirOpcoes();

        }
    }

    return 0;
}