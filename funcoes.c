#include <stdio.h>
#include <string.h>
#include "funcoes.h"



/*
 * Esta função é responsável por ADICIONAR UM NOVO PRODUTO ao sistema.
 * Ela primeiro verifica se o limite de produtos foi atingido. Se houver espaço,
 * ela pede ao usuário para digitar o nome, o preço e a quantidade em estoque.
 * Ao final, armazena essas informações nos arrays e aumenta a contagem total de
 * produtos ('qtd') em 1.
 */
void inserirProduto(char nomes[][50], float precos[], int estoques[], int *qtd) { // o *qtd é usado para passar o endereço de memória da variável qtd, permitindo que a função modifique seu valor diretamente.
    if (*qtd >= 100) { 
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomes[*qtd]); // %[^\n] permite ler uma string com espaços até encontrar uma nova linha e nomes[*qtd] é usado para armazenar o nome do produto no índice atual de qtd.
    printf("Digite o preco: ");
    scanf("%f", &precos[*qtd]);
    printf("Digite o estoque: ");
    scanf("%d", &estoques[*qtd]);

    *qtd = *qtd + 1; // incrementa a quantidade de produtos cadastrados
    printf("Produto cadastrado!\n");
    printf(" \n");
}


/*
 * A função 'listarProdutos' tem o objetivo de EXIBIR TODOS OS PRODUTOS
 * que estão atualmente cadastrados. Ela verifica se existem produtos na lista.
 * Se houver, ela percorre os arrays e imprime na tela uma linha formatada para
 * cada produto, mostrando seus dados.
 */
void listarProdutos(char nomes[][50], float precos[], int estoques[], int qtd) { 
    int i;
    if (qtd == 0) {
        printf("Nao ha produtos cadastrados.\n");
        return;
    }

    for (i = 0; i < qtd; i++) { // percorre o array de produtos
        printf("ID: %d | Nome: %s | Preco: %.2f | Estoque: %d | Endereco: %p\n", // Exibe os detalhes de cada produto, incluindo o ID, nome, preço, estoque
               i + 1, nomes[i], precos[i], estoques[i], &precos[i]);
    }
}


/*
 * Esta função permite ao usuário MODIFICAR AS INFORMAÇÕES de um produto que já existe.
 * Primeiro, ela lista os produtos para que o usuário saiba qual escolher.
 * Depois, pergunta qual o ID do produto a ser atualizado e, em seguida, pede
 * que o usuário insira os novos dados (nome, preço e estoque), substituindo os antigos.
 */
void atualizarProduto(char nomes[][50], float precos[], int estoques[], int qtd) {
    int id;
    int i;
    
    for (i = 0; i < qtd; i++) {
    printf("ID: %d | Nome: %s\n", i + 1, nomes[i]);
}
    printf("\nDigite o ID do produto para atualizar: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) { 
        printf("Produto nao encontrado!\n");
        return;
    }

    id = id - 1; // Ajusta o ID para o índice do array (começa em 0)

    printf("Novo nome: ");
    scanf(" %[^\n]", nomes[id]);
    printf("Novo preco: ");
    scanf("%f", &precos[id]); // &precos[id] é usado para acessar o endereço de memória do preço do produto selecionado
    printf("Novo estoque: ");
    scanf("%d", &estoques[id]); // &estoques[id] é usado para acessar o endereço de memória do estoque do produto selecionado

    printf("Produto atualizado!\n");
}

/*
 * A função 'removerProduto' serve para APAGAR UM PRODUTO do sistema.
 * Após o usuário escolher o ID do produto a ser deletado, a função remove o item
 * e "reorganiza" o array, movendo todos os produtos seguintes uma posição para frente
 * para não deixar um espaço vazio na lista. Ao final, diminui a contagem total de produtos.
 */
void removerProduto(char nomes[][50], float precos[], int estoques[], int *qtd) { //

    int id, i , j;


    for (i = 0; i < *qtd; i++) { // percorre o array de produtos, *qtd é usado para acessar a quantidade de produtos cadastrados
    printf("ID: %d | Nome: %s\n", i + 1, nomes[i]); 
}

    printf("Digite o ID do produto para remover: ");
    scanf("%d", &id);

    //
    if(id < 1 || id > *qtd){ 
        printf("Produto nao encotrado\n");
        return;
    }
    // Ajusta o ID para o índice do array (começa em 0)
    id = id - 1;
    // Move os produtos seguintes uma posição para frente
    for ( i = id; i < *qtd - 1; i++)    // Isso é feito para evitar deixar um espaço vazio na lista após a remoção
    {
        j = 0; 
        while(nomes[i + 1][j] != '\0'){ // "/0" é um comando que não permite a alocação de espaços desnecessários na memória 
            nomes[i][j] = nomes[i + 1][j]; // nomes[i][j] recebe o valor de nomes[i + 1][j], ou seja, o nome do produto seguinte é movido para a posição atual
            j++;
        }
        nomes[i][j] = '\0'; // nome[i][j] recebe o valor de '\0', que é o caractere nulo que indica o fim da string
        precos[i] = precos[i + 1];
        estoques[i] = estoques[i + 1];
    }
    *qtd = *qtd - 1; // Decrementa a quantidade de produtos cadastrados
    printf("Produto removido!\n");
}


/*
 * Esta função CALCULA ESTATÍSTICAS DE PREÇOS de todos os produtos cadastrados.
 * Ela percorre o array de preços para encontrar o valor mais baixo (min), o valor
 * mais alto (max) e a média de todos os preços. Os resultados são "retornados"
 * para a função main através de ponteiros.
 */
void estatisticasProdutos(float precos[], int qtd, float *min, float *max, float *media) { // o *min, *max e *media são usados para passar os endereços de memória das variáveis min, max e media, permitindo que a função modifique seus valores diretamente.
    int i;
    float soma = 0;

    if (qtd == 0) {
        *min = 0;
        *max = 0;
        *media = 0;
        return;
    } // Se não houver produtos, define min, max e media como 0

    *min = precos[0]; // Inicializa min com o primeiro preço
    *max = precos[0]; // Inicializa max com o primeiro preço

    for (i = 0; i < qtd; i++) {
        if (precos[i] < *min) *min = precos[i];
        if (precos[i] > *max) *max = precos[i];
        soma = soma + precos[i];
    } // Percorre o array de preços para encontrar min, max e calcular a soma

    *media = soma / qtd; // Calcula a média dividindo a soma pelo número de produtos
}