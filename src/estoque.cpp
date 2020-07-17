#include <iostream>
#include <fstream>

#include "../include/estoque.hpp"

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
        
        if (line.find(nome) != std::string::npos) {
            aux = line;
            for (auto it = aux.begin(); it != aux.end(); it++) {
                counter2++;
                if ((*it) == ',')
                    counter1++;
                if (filename == "estoque.csv") {
                    if (counter1 >= 5)
                        aux.erase(counter2);
                }
                else if (filename == "fornecedor.csv") {
                    if (counter1 >= 1)
                        aux.erase(counter2);
                }
            }
            aux.append(std::to_string(qntd));
            line = aux;
        }

        outcache << line;
        outcache << "\n";
    }

    infile.close();
    outcache.close();

    outfile.open(filename);
    incache.open("cache.csv");

    while(!incache.eof()) {
        std::getline(incache, line);

        outfile << line;
        outfile << "\n";
    }

    outfile.close();
    incache.close();

    remove("cache.csv");

}