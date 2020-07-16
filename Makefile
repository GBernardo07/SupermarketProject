GCC = g++
OBJECTS = cliente.o estabelecimento.o main.o produto.o
FLAGS = -std=c++11
EXECUTABLE = exe

all: $(EXECUTABLE)

main.o: src/main.cpp
	$(GCC) $(CFLAGS) -c src/main.cpp

cliente.o: src/cliente.cpp
	$(GCC) $(CFLAGS) -c src/cliente.cpp

estabelecimento.o: src/estabelecimento.cpp
	$(GCC) $(CFLAGS) -c src/estabelecimento.cpp

produto.o: src/produto.cpp
	$(GCC) $(CFLAGS) -c src/produto.cpp

$(EXECUTABLE): $(OBJECTS)
	$(GCC) $(OBJECTS) $(CFLAGS)-o $(EXECUTABLE)

clean:
	rm -rf *.o
	rm $(EXECUTABLE)
