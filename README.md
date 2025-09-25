# Trabalho-Estrutura-de-Dados

# Cadastro de Produtos em C

Sistema simples em C para cadastro de produtos de mercado.  
Permite inserir, listar, atualizar, remover e calcular estatísticas (mínimo, máximo e média dos preços).  
Mostra também os endereços de memória dos produtos no vetor.

## Compilação

```sh
gcc -Wall -Wextra -std=c11 main.c funcoes.c -o mercado
```

## Execução

```sh
./mercado
```

## Funcionalidades

- Inserir produto
- Listar produtos (com endereços de memória)
- Atualizar produto
- Remover produto
- Estatísticas (mínimo, máximo e média via ponteiros)

## Estrutura

- main.c → menu e chamadas
- funcoes.c → implementação das funções
- funcoes.h → protótipos das funções || Biblioteca

# Demonstração (Telas do Código)

Abaixo estão algumas capturas de tela de trechos do código.

## Tela do Menu Principal

O usuário é apresentado a um menu limpo com todas as opções disponíveis.

<img width="50%" alt="code" src="https://github.com/user-attachments/assets/f52418d9-cec8-41ea-86b4-02da8a7245ec" />  <img width="50%" alt="Menu" src="https://github.com/user-attachments/assets/8914c7e0-d761-402f-9370-e4d41ee574e6" />


## 1. Inserindo um Produto

O sistema solicita as informações do novo produto (nome, preço e estoque) e confirma o cadastro.
<img width="50%" alt="inserir" src="https://github.com/user-attachments/assets/9ff568df-e9ef-4279-8aec-c0ecc03d0307" />

## 2. Listando os Produtos Cadastrados

A opção de listar exibe todos os produtos em um formato tabular, incluindo um ID gerado sequencialmente.
<img width="50%" alt="listar" src="https://github.com/user-attachments/assets/2248b928-ee7b-4736-bb03-1e46e7773b9b" />

## 3. Atualizando um Produto

O usuário seleciona o ID do produto que deseja alterar e insere as novas informações.

<img width="50%" alt="atualizar" src="https://github.com/user-attachments/assets/adf3b93a-cbb7-475c-a17a-117950641f92" /> <img width="50%" alt="atualizar" src="https://github.com/user-attachments/assets/dfa724ac-02a4-4b08-9342-a93be1799ec3" />


## 4. Removendo um Produto

Após listar os produtos disponíveis, o sistema pede o ID do item a ser removido e confirma a exclusão.

<img width="50%" alt="remover" src="https://github.com/user-attachments/assets/52bb18b5-8f00-41ce-a3c5-8a3f0b4f5dbd" /> <img width="50%" alt="remover" src="https://github.com/user-attachments/assets/c3c2284e-1d5c-40b0-bf33-f5e6bd368f74" />



## 5. Exibindo as Estatísticas

A função de estatísticas analisa todos os produtos cadastrados e exibe:
- Menor preço
- Maior preço
- Média de preços

<img width="50%" alt="estatisticas" src="https://github.com/user-attachments/assets/660f1d93-aac4-408f-aba4-4b75cd6379d8" />
