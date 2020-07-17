#include <iostream>
#include <fstream>

#include "../include/estoque.hpp"

// Função que altera o arquivo, no produto e na quantidade especificadas
void alterarEstoque(std::string filename, std::string nome, int qntd) {

    int counter1, counter2;
    std::ifstream infile, incache;
    std::ofstream outfile, outcache;
    std::string line, aux;

    infile.open(filename);
    outcache.open("cache.csv");

    while(!infile.eof()) {
        counter1 = 0;
        counter2 = 0;
        std::getline(infile, line);
        
        //Caso for achado o nome do produto na linha
        if (line.find(nome) != std::string::npos) {
            aux = line;

            //Itera uma string auxiliar até achar a última vírgula
            for (auto it = aux.begin(); it != aux.end(); it++) {
                counter2++;
                if ((*it) == ',')
                    counter1++;

                //Remove o último valor (QntdAtual)
                if (filename == "estoque.csv") {
                    if (counter1 >= 5)
                        aux.erase(counter2);
                }
                else if (filename == "fornecedor.csv") {
                    if (counter1 >= 1)
                        aux.erase(counter2);
                }
            }

            //Insere o novo valor
            aux.append(std::to_string(qntd));
            line = aux;
        }

        outcache << line;
        outcache << "\n";
    }

    infile.close();
    outcache.close();

    //Inverte a abertura dos arquivos
    outfile.open(filename);
    incache.open("cache.csv");

    //Copia do arquivo cache para o definitivo
    while(!incache.eof()) {
        std::getline(incache, line);

        //Limpa as linhas vazias
        if (!line.empty()) {
            outfile << line;
            outfile << "\n";
        }
    }

    outfile.close();
    incache.close();

    remove("cache.csv");

}