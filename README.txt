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
        Exibir caixa: Essa opção imprime na tela todas as vendas que já ocorreram durante a execução do programa
        Ver sacola: Essa opção imprime na tela todos os itens comprados pelo cliente.
        Comprar <codigo do produto>: Essa opção permite a compra de produtos pelo cliente, utilizando o código.
        Checkout: Essa opção pergunta se um novo cliente quer ser definido, se sim, desaloca o atual e gera um novo, para novas transações. Se não, desaloca o atual e encerra o programa.

    Vale lembrar que o usuário deve inserir as opções exatamente do modo como são apresentadas no menu.

Classes

    O programa Supermercado foi dividido em 3 classes: Estabelecimento, Cliente e Produto, cada uma dessas com seus devidos métodos e atributos.

    Estabelecimento

        É a principal classe, que gerencia os produtos disponíveis e contabiliza os lucros e vendas.
        
        Na sua construção, é declarada a lista de produtos, ou seja, o estoque, e as funções para preenchimento do estoque e geração do arquivo do caixa são chamadas.
        Além disso, os lucros e total de vendas são definidos para zero.

        Na destruição, esses dados são impressos no arquivo do caixa.

        Seus métodos:

            Consultar estoque: É chamado na construção da classe, procura no arquivo estoque.csv todos os produtos e adiciona-os à lista de produtos.
            Gerar caixa: É chamado também na construção da classe, e gera um arquivo caixa.csv para registro do fluxo das compras, e, no final, inserir o relatório de tudo o que foi comprado e o lucro total.
            Listar produtos: Imprime na tela todos os produtos do estoque e seus devidos atributos.
            Venda: Recebe o código de um produto e verifica se tem estoque suficiente para compra. Se sim, faz as atribuições necessárias nas características dos produtos e no estoque na loja. Caso contrário, imprime uma mensagem de erro. O controle de quantidade de produtos é feito apenas nos atributos dos objetos, nenhuma alteração é feita no arquivo estoque.csv.
            Registrar venda: Registra no arquivo caixa.csv a última venda feita, inserindo a quantidade vendida e o nome do produto.
            Caixa: Imprime na tela as vendas feitas e o lucro total.
            Encerrar caixa: É chamado na destruição da classe, termina o arquivo caixa.csv inserindo todo o relatório de vendas durante a execução.

    Produto

        É a classe que define e caracteriza os produtos. 

        Na construção, todos os valores são inicializados como nulos ou zeros.

        Possui apenas um método:

            Retornar produto: Recebe uma string, mais especificamente a linha atual do arquivo de estoque, e retorna um obejeto do tipo produto, que vai ser adicionado na lista do estoque. Muitas dificuldades foram encontradas para fazer a formatação do texto em partes, mas foram contornadas da seguinte forma:

                Contabilizando a quantidade de vírgulas, o programa vai saber onde inserir cada dado. A função getline() retira palavra por palavra entre as vírgulas, e usa o contador no switch para saber onde encaixar cada uma delas. Por exemplo, caso o contador esteja em zero, sabemos que nenhuma vírgula foi encontrada e assim, como o primeiro dado é o código, sabemos onde atribuir o inteiro.
                O problema chegou na parte do preço, onde há uma vírgula no meio, e nesse caso foi dividido o processo em duas partes. Somamos a primeira parte ao preco do produto como inteiro, e a segunda parte como decimal.
                Desse modo cada produto teve sua especificação atribuída corretamente.

    Cliente

        É a classe que define os clientes e registra os dados relativos à individualidade de cada um.

        Na construção é dado um saldo de R$300,00 e uma sacola (vector de produtos).
        Além disso, é contabilizada a quantidade de clientes numa variável estática, que pode ser compartilhada entre objetos do mesmo tipo. Desse modo, quando cada cliente é construído, usamos a quantidade para atribuir um número de identificação a cada um.

        A classe possui os seguintes métodos: 

            Adicionar saldo: Adiciona um valor requisitado ao saldo do cliente.
            Compra: Recebe um produto e o adiciona à sacola do cliente, diminuindo seu saldo, caso seja suficiente. Caso contrário, exibe uma mensagem de erro.
            Ver sacola: Imprime a sacola completa do cliente, com os produtos inseridos.
            Registro: Chamado na destruição, recebe o número identificador do cliente, e gera um arquivo cliente_x para todo x < quantidade de clientes. Esse arquivo contém a sacola de cada cliente construído durante a execução do programa.

Compilação e execução

    A compilação pode ser feita usando o Makefile produzido.
    Para rodar bem, o programa precisa do arquivo estoque.csv na pasta de execução.
