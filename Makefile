GCC = g++
OBJECTS = cliente.o estabelecimento.o main.o produto.o fornecedor.o estoque.o
FLAGS = -std=c++11 -g
EXECUTABLE = exe

all: $(EXECUTABLE)

main.o: src/main.cpp
	$(GCC) $(FLAGS) -c src/main.cpp

cliente.o: src/cliente.cpp
	$(GCC) $(FLAGS) -c src/cliente.cpp

estabelecimento.o: src/estabelecimento.cpp
	$(GCC) $(FLAGS) -c src/estabelecimento.cpp

produto.o: src/produto.cpp
	$(GCC) $(FLAGS) -c src/produto.cpp

fornecedor.o: src/fornecedor.cpp
	$(GCC) $(FLAGS) -c src/fornecedor.cpp

estoque.o: src/estoque.cpp
	$(GCC) $(FLAGS) -c src/estoque.cpp

$(EXECUTABLE): $(OBJECTS)
	$(GCC) $(OBJECTS) $(FLAGS) -o $(EXECUTABLE)

clean:
	rm -rf *.o
	rm $(EXECUTABLE)
