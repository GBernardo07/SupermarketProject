Atividade Estabelecimentos

Visão geral

    O programa foi feito quase que completamente de acordo com as especificações da atividade.
    Tudo aquilo que não pôde ser feito igual será exposto nesse texto.

    A exposição será feita de acordo com os arquivos e classes do programa, explicando seus métodos e atributos, bem como possíveis complicações encontradas no decorrer do desenvolvimento.

Main

    O main foi utilizado principalmente para realizar a interação com o usuário.
    Ele apresenta a interface e exibe as opções disponíveis, de acordo com a escolha do usuário.
    Primeiro é pedido seu nome, depois pode-se escolher utilizar o restaurante ou o supermercado.
    
    No supermercado, as opções são as seguintes:
    
        Adicionar saldo: Essa opção pede o valor a ser inserido no saldo do cliente.
        Verificar produtos: Essa opção imprime todos os produtos disponíveis no estoque.
        Listar fornecedor: Essa opção imprime o estoque do fornecedor, disponível para reabastecimento.
        Reabastecer estoque: Essa opção permite reabastecer o estoque na loja, removendo do estoque do fornecedor.
        Exibir caixa: Essa opção imprime na tela todas as vendas que já ocorreram durante a execução do programa
        Ver sacola: Essa opção imprime na tela todos os itens comprados pelo cliente.
        Comprar <Nome do Produto>: Essa opção permite a compra de produtos pelo cliente, utilizando o nome.
        Checkout: Essa opção pergunta se um novo cliente quer ser definido, se sim, desaloca o atual e gera um novo, para novas transações. Se não, desaloca o atual e encerra o programa.

    Vale lembrar que o usuário deve inserir as opções, bem como o nome do produto exatamente do modo como são apresentadas no menu.

    No restaurante, as opções são as seguintes:

        Verificar cardapio: Exibe o cardápio disponível para compra.
        Exibir caixa: Imprime na tela as últimas compras feitas.
        Ver comanda: Exibe os pedidos já feitos pelo cliente.
        Pedir <Nome do alimento>: Permite fazer pedidos de acordo com o nome do alimento. Depois, é pedida a quantidade.

        Adicionar saldo e Checkout fazem exatamente a mesma coisa.
 

Classes

    O programa Estabelecimentos foi dividido nas classes: Estabelecimento, Supermercado, Restaurante, Cliente, Produto, Fornecedor e VecSupermarket, cada uma dessas com seus devidos métodos e atributos.

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

        É a classe que contabiliza os lucros e vendas, e gera os arquivos de caixa.
        É a classe mãe para Restaurante e Supermercado.
        
        Na sua construção, os lucros e total de vendas são definidos para zero.

        Seus métodos:

            Gerar caixa: Gera um arquivo de caixa para registro do fluxo das compras, e, no final, inserir o relatório de tudo o que foi comprado e o lucro total.
            Encerrar caixa: Termina o arquivo de caixa inserindo todo o relatório de vendas durante a execução.

    Restaurante e Supermercado

        São duas classes semelhantes, filhas de Estabelecimento, mas que diferem em alguns aspectos.

        Na construção, definem um vector_supermercado, inserem os produtos de seus respectivos arquivos nesse vector, alocam um array para controle de quantidade de vendas e geram um arquivo de caixa.

        Na destruição, encerram o caixa.

        Têm alguns métodos em comum, isto é, que fazem a mesma coisa mas de forma diferente.
        São eles:

            Consultar menu/Consultar estoque: Insere os produtos dos arquivos nos vectors.
            Setar array de vendas: Aloca o array para controle das vendas.
            Mostrar cardapio/Listar produtos: Exibe na tela todos os produtos disponíveis para compra.
            Registrar venda: Escreve no arquivo do caixa a última venda feita.
            Venda: Faz as operações necessárias para processar a venda internamente.
            Encerrar caixa: Termina o arquivo do caixa exibindo um relatório completo das vendas.

    Produto
	 
        É a classe que define e caracteriza os produtos. 

        Na construção, todos os valores são inicializados como nulos ou zeros.

        Possui os seguintes métodos:

            Retornar produto pro supermercado: Recebe uma string, mais especificamente a linha atual do arquivo de estoque, e retorna um obejeto do tipo produto, que vai ser adicionado no vector do estoque. Muitas dificuldades foram encontradas para fazer a formatação do texto em partes, mas foram contornadas da seguinte forma:

                Contabilizando a quantidade de vírgulas, o programa vai saber onde inserir cada dado. A função getline() retira palavra por palavra entre as vírgulas, e usa o contador no switch para saber onde encaixar cada uma delas. Por exemplo, caso o contador esteja em zero, sabemos que nenhuma vírgula foi encontrada e assim, como o primeiro dado é o código, sabemos onde atribuir o inteiro.
                O problema chegou na parte do preço, onde há uma vírgula no meio, e nesse caso foi dividido o processo em duas partes. Somamos a primeira parte ao preco do produto como inteiro, e a segunda parte como decimal.
                Desse modo cada produto teve sua especificação atribuída corretamente.

            Retornar produto pro restaurante: Processa da mesma forma como para o supermercado, com a particularidade de que os produtos no restaurante possuem apenas nome e preço.

            Retornar produto do fornecedor: Processa os dados exatamente da mesma forma da anterior, com a exceção de que como no arquivo do fornecedor são apenas 2 informações, considera apenas uma vírgula para diferenciá-las.

    Cliente

        É a classe que define os clientes e registra os dados relativos à individualidade de cada um.

        Na construção é dado um saldo de R$300,00 e um vector de produtos (Compras).
        Além disso, é contabilizada a quantidade de clientes numa variável estática, que pode ser compartilhada entre objetos do mesmo tipo. Desse modo, quando cada cliente é construído, usamos a quantidade para atribuir um número de identificação a cada um.

        A classe possui os seguintes métodos: 

            Adicionar saldo: Adiciona um valor requisitado ao saldo do cliente.
            Compra: Recebe um produto e uma quantidade, e adiciona essa quantidade de produtos às compras do cliente, diminuindo seu saldo, caso seja suficiente. Caso contrário, exibe uma mensagem de erro.
            Ver compras: Imprime as compras do cliente, com os produtos inseridos.
            Registro: Chamado na destruição, recebe o número identificador do cliente, e gera um arquivo cliente_x para todo x < quantidade de clientes. Esse arquivo contém as compras de cada cliente construído durante a execução do programa.

    Fornecedor

        É a classe que define o fornecedor, de onde serão removidos produtos para abastecimento dos supermercados apenas.

        Tem apenas um vector_supermercado para armazenar os produtos internamente.

        Seus métodos:

            Consultar estoque: Consulta o arquivo "fornecedor.csv" e insere no vector os produtos com suas quantidades.
            Listar produtos: Lista os produtos disponíveis para abastecimento.
            Repassar produtos: Recebe o endereço de um supermercado e insere os produtos na quantidade pedida.

Outros
    
    Estoque

        É a biblioteca responsável por manipular os arquivos.

        Tem apenas um método:

            Alterar estoque: Recebe o nome do arquivo, o nome do produto e a nova quantidade a ser inserida.
                Para isso, são utilizados 2 arquivos de texto. O conteúdo do arquivo original é transferido para o cache, alterando a quantidade do produto definido no momento adequado. Depois, o conteúdo do cache volta para o arquivo original, removendo linhas em branco e apagando o cache.

Compilação e execução

    A compilação pode ser feita usando o Makefile produzido.
    Para rodar bem, o programa precisa dos arquivos estoque.csv (com vírgulas nos preços), menu.csv e fornecedor.csv na pasta de execução.
