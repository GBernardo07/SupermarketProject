Atividade Supermercado

Visão geral

    O programa foi feito quase que completamente de acordo com as especificações da atividade.
    Tudo aquilo que não pôde ser feito igual será exposto nesse texto.

    A exposição será feita de acordo com os arquivos e classes do programa, explicando seus métodos e atributos, bem como possíveis complicações encontradas no decorrer do desenvolvimento.

Main

    O main foi utilizado principalmente para realizar a interação com o usuário.
    Ele apresenta a interface e exibe as opções disponíveis. São elas:
    
        Adicionar saldo: Essa opção pede o valor a ser inserido no saldo do cliente.
        Verificar produtos: Essa opção imprime todos os produtos disponíveis no estoque.
        Listar fornecedor: Essa opção imprime o estoque do fornecedor, disponível para reabastecimento.
        Reabastecer estoque: Essa opção permite reabastecer o estoque na loja, removendo do estoque do fornecedor.
        Exibir caixa: Essa opção imprime na tela todas as vendas que já ocorreram durante a execução do programa
        Ver sacola: Essa opção imprime na tela todos os itens comprados pelo cliente.
        Comprar <Nome do Produto>: Essa opção permite a compra de produtos pelo cliente, utilizando o nome.
        Checkout: Essa opção pergunta se um novo cliente quer ser definido, se sim, desaloca o atual e gera um novo, para novas transações. Se não, desaloca o atual e encerra o programa.

    Vale lembrar que o usuário deve inserir as opções, bem como o nome do produto exatamente do modo como são apresentadas no menu.

Classes

    O programa Supermercado foi dividido nas classes: Estabelecimento, Cliente, Produto, Fornecedor e VecSupermarket, cada uma dessas com seus devidos métodos e atributos.

    VecSupermarket

        É a classe que define a estrutura de dados que vai armazenar os produtos no decorrer do programa.

        Tem os atributos inteiros capacity e size, para manipulação dos tamanhos, e o ponteiro para elementos *elements;

        O construtor define capacity como 1 e size como 0. Capacity guarda a quantidade disponível de armazenamento, e size guarda a quantidade de elementos no momento. Além disso, o array de elementos do tipo definido é alocado de acordo com capacity.

        Os métodos julgados convenientes a serem implementados são:

            Double Capacity: Dobra a capacidade do vector quando atinge seu limite.
            Get Size: Retorna o tamanho do vector, dado que é um atributo privado.
            At: Recebe um inteiro e retorna o elemento, naquela posição.
            Push Back: Recebe um elemento e insere no final do vector.
            Pop Back: Remove o último elemento do vector.
            Clear: Limpa o vector (Apenas define size para 0).

    Estabelecimento

        É a principal classe, que gerencia os produtos disponíveis e contabiliza os lucros e vendas.
        
        Na sua construção, é declarado um vector_supermercado de produtos, ou seja, o estoque, e as funções para preenchimento do estoque e geração do arquivo do caixa são chamadas.
        Além disso, os lucros e total de vendas são definidos para zero.

        Na destruição, esses dados são impressos no arquivo do caixa.

        Seus métodos:

            Setar Array Vendas: Chamado na construção da classe, define um array para controlar a quantidade de produtos vendidos, para cada produto.
            Consultar estoque: É chamado na construção da classe, procura no arquivo estoque.csv todos os produtos e adiciona-os ao vector de produtos.
            Gerar caixa: É chamado também na construção da classe, e gera um arquivo caixa.csv para registro do fluxo das compras, e, no final, inserir o relatório de tudo o que foi comprado e o lucro total.
            Listar produtos: Imprime na tela todos os produtos do estoque e seus devidos atributos.
            Venda: Recebe o nome de um produto e verifica se tem estoque suficiente para compra. Se sim, faz as atribuições necessárias nas características dos produtos e no estoque na loja. Caso contrário, imprime uma mensagem de erro.
            Registrar venda: Registra no arquivo caixa.csv a última venda feita, inserindo a quantidade vendida e o nome do produto.
            Caixa: Imprime na tela as vendas feitas e o lucro total.
            Encerrar caixa: É chamado na destruição da classe, termina o arquivo caixa.csv inserindo todo o relatório de vendas durante a execução.

    Produto
	 
        É a classe que define e caracteriza os produtos. 

        Na construção, todos os valores são inicializados como nulos ou zeros.

        Possui dois métodos:

            Retornar produto: Recebe uma string, mais especificamente a linha atual do arquivo de estoque, e retorna um obejeto do tipo produto, que vai ser adicionado no vector do estoque. Muitas dificuldades foram encontradas para fazer a formatação do texto em partes, mas foram contornadas da seguinte forma:

                Contabilizando a quantidade de vírgulas, o programa vai saber onde inserir cada dado. A função getline() retira palavra por palavra entre as vírgulas, e usa o contador no switch para saber onde encaixar cada uma delas. Por exemplo, caso o contador esteja em zero, sabemos que nenhuma vírgula foi encontrada e assim, como o primeiro dado é o código, sabemos onde atribuir o inteiro.
                O problema chegou na parte do preço, onde há uma vírgula no meio, e nesse caso foi dividido o processo em duas partes. Somamos a primeira parte ao preco do produto como inteiro, e a segunda parte como decimal.
                Desse modo cada produto teve sua especificação atribuída corretamente.

            Retornar produto do fornecedor: Processa os dados exatamente da mesma forma da anterior, com a exceção de que como no arquivo do fornecedor são apenas 2 informações, considera apenas uma vírgula para diferenciá-las.

    Cliente

        É a classe que define os clientes e registra os dados relativos à individualidade de cada um.

        Na construção é dado um saldo de R$300,00 e uma sacola (vector de produtos).
        Além disso, é contabilizada a quantidade de clientes numa variável estática, que pode ser compartilhada entre objetos do mesmo tipo. Desse modo, quando cada cliente é construído, usamos a quantidade para atribuir um número de identificação a cada um.

        A classe possui os seguintes métodos: 

            Adicionar saldo: Adiciona um valor requisitado ao saldo do cliente.
            Compra: Recebe um produto e o adiciona à sacola do cliente, diminuindo seu saldo, caso seja suficiente. Caso contrário, exibe uma mensagem de erro.
            Ver sacola: Imprime a sacola completa do cliente, com os produtos inseridos.
            Registro: Chamado na destruição, recebe o número identificador do cliente, e gera um arquivo cliente_x para todo x < quantidade de clientes. Esse arquivo contém a sacola de cada cliente construído durante a execução do programa.

    Fornecedor

        É a classe que define o fornecedor, de onde serão removidos produtos para abastecimento dos estabelecimentos.

        Tem apenas um vector_supermercado para armazenar os produtos internamente.

        Seus métodos:

            Consultar estoque: Consulta o arquivo "fornecedor.csv" e insere no vector os produtos com suas quantidades.
            Listar produtos: Lista os produtos disponíveis para abastecimento.
            Repassar produtos: Recebe o endereço de uma loja e insere os produtos na quantidade pedida.

Outros
    
    Estoque

        É a biblioteca responsável por manipular os arquivos.

        Tem apenas um método:

            Alterar estoque: Recebe o nome do arquivo, o nome do produto e a nova quantidade a ser inserida.
                Para isso, são utilizados 2 arquivos de texto. O conteúdo do arquivo original é transferido para o cache, alterando a quantidade do produto definido no momento adequado. Depois, o conteúdo do cache volta para o arquivo original, removendo linhas em branco e apagando o cache.

Compilação e execução

    A compilação pode ser feita usando o Makefile produzido.
    Para rodar bem, o programa precisa dos arquivos estoque.csv e fornecedor.csv na pasta de execução.
