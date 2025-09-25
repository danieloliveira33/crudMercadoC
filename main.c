#include <stdio.h>
#include "funcoes.h" // Importando o cabeçalho das funções



int main()
{

    // --Declaração de variáveis--
    // arrays para armazenar os nomes, preços e estoques dos produtos
    char nomes[MAX_PRODUTOS][50]; // 
    float precos[MAX_PRODUTOS];
    int estoques[MAX_PRODUTOS];
    // variável para armazenar a quantidade de produtos cadastrados e variáveis auxiliares
    int qtd = 0;
    int escolha;
    int voltarmenu = -1;
    float min, max, media;
    char chr, chrVoltar;

    // Inicio de um loop para manter o menu rodando até que o usuário decida sair
    while (voltarmenu != 0)
    {
    printf("============================================");
    printf("\n                 MENU PRINCIPAL              \n");
    printf("============================================\n");
    printf("  [1]  Inserir produto\n");
    printf("  [2]  Listar produtos\n");
    printf("  [3]  Atualizar produto\n");
    printf("  [4]  Remover produto\n");
    printf("  [5]  Ver estatisticas\n");
    printf("============================================\n");
    printf("\n Escolha uma opcao: ");

    // Leitura da escolha do usuário, a variavel 'escolha' recebe o valor correspondente à opção selecionada
    // Se o usuário digitar um caractere inválido, a variável 'escolha' será definida como -1
    // O loop continuará até que uma opção válida seja selecionada
    escolha = -1; // é igual a -1 para entrar no loop
    scanf(" %c", &chr);
    if(chr >= '0' && chr <= '5')
        escolha = chr - '0';
    else{
        printf("\nOpcao invalida! Por favor digite apenas numeros\n");
        precos = 0;
        continue;}

        // Foi inserido estrutura de controle para informar aonde o usuário está sendo redirecionado 
        // Esta série de 'if's serve apenas para dar um feedback visual ao usuário,
        if (escolha == 1)
        {
        printf("\n============================================\n");
        printf("\n Redirecionando para - Inserir produtos - Opcao: (%d)\n", escolha);
        printf("\n============================================\n");
        }
        if (escolha == 2)
        {
        printf("\n============================================\n");
        printf("\n Redirecionando para - Listar produtos - Opcao: (%d)\n", escolha);
        printf("\n============================================\n");
        }
        if (escolha == 3)
        {
        printf("\n============================================\n");
        printf("\n Redirecionando para - Atualizar produto - Opcao: (%d)\n", escolha);
        printf("\n============================================\n");
        }
        if (escolha == 4)
        {
        printf("\n============================================\n");
        printf("\n Redirecionando para - Remover produto - Opcao: (%d)\n", escolha);
        printf("\n============================================\n");
        }
        if (escolha == 5)
        {
        printf("\n============================================\n");
        printf("\n Redirecionando para - Ver estatisticas - Opcao: (%d)\n", escolha);
        printf("\n============================================\n");
        }

        // Chamada das funções correspondentes à opção selecionada pelo usuário

        if (escolha == 1)
        {
            inserirProduto(nomes, precos, estoques, &qtd);
        }
        else if (escolha == 2)
        {
            listarProdutos(nomes, precos, estoques, qtd);
        }
        else if (escolha == 3)
        {
            atualizarProduto(nomes, precos, estoques, qtd);
        }
        else if (escolha == 4)
        {
            removerProduto(nomes, precos, estoques, &qtd);
        }
        else if (escolha == 5)
        {
            estatisticasProdutos(precos, qtd, &min, &max, &media); //o & é usado para passar o endereço de memória das variáveis min, max e media, permitindo que a função modifique seus valores diretamente.
            printf("\nPreco minimo: %.2f | Preco maximo: %.2f | Media: %.2f\n", min, max, media);
        }

        // Trecho que é executado após a finalização de uma das opções do menu
        printf("\nSelecione uma opcao: \n");
        printf("\n1 - Voltar ao menu inicial\n");
        printf("\n0 - Finalizar tarefa\n");

        // Leitura da opção de voltar ao menu ou finalizar a tarefa, caso o usuário digite um caractere inválido, a variável 'voltarmenu' será definida como -1
        voltarmenu = -1; // é igual a -1 para entrar no loop
        scanf(" %c", &chrVoltar);
        if (chrVoltar == '0')
            voltarmenu = 0;
        else if (chrVoltar == '1'){
            voltarmenu = 1;}
        else{
            printf("\nOpcao invalida! Voltando ao menu\n"), voltarmenu = 1;
        }
    }

    return 0;
}
