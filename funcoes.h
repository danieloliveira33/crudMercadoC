#ifndef FUNCOES_H
#define FUNCOES_H // Define um marcador para evitar inclusões múltiplas deste arquivo.
#define MAX_PRODUTOS 100 // Define a capacidade máxima de produtos que o programa pode ter

void inserirProduto(char nomes[][50], float precos[], int estoques[], int *qtd); // Declaração da função que adiciona um novo produto.
void listarProdutos(char nomes[][50], float precos[], int estoques[], int qtd); // Declaração da função que exibe todos os produtos na tela.
void atualizarProduto(char nomes[][50], float precos[], int estoques[], int qtd); // Declaração da função que edita um produto existente
void removerProduto(char nomes[][50], float precos[], int estoques[], int *qtd); // Declaração da função que apaga um produto do sistema.
void estatisticasProdutos(float precos[], int qtd, float *min, float *max, float *media); // Declaração da função que calcula estatísticas dos preços dos produtos.

#endif