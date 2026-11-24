 <div align="center">

# Estrutura de Árvore AVL

### Estruturas de dados, algoritmos e balanceamento em C.

**Implementação de uma Árvore AVL utilizando a linguagem C, explorando inserção, rotações e mecanismos de balanceamento automático em árvores binárias de busca.**

![C](https://img.shields.io/badge/C-Linguagem-00599C?style=flat-square&logo=c&logoColor=white)
[![GCC](https://img.shields.io/badge/GCC-Compiler-233B6E?style=flat-square&logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Make](https://img.shields.io/badge/Make-Build%20Tool-427819?style=flat-square&logo=gnu&logoColor=white)](https://www.gnu.org/software/make/)

</div>

---

## Visão geral

O **Estrutura de Árvore AVL** é um projeto desenvolvido em linguagem C com o objetivo de implementar e compreender o funcionamento de uma árvore binária de busca auto-balanceável.

A implementação utiliza ponteiros, estruturas e recursividade para organizar os elementos, mantendo a árvore balanceada durante as operações de inserção.

O balanceamento é realizado por meio de quatro casos de rotação (LL, RR, LR e RL), utilizando a altura dos nós e o fator de balanceamento para identificar e corrigir possíveis desequilíbrios.

## Funcionalidades

| Recurso | Descrição |
| --- | --- |
| **Criação de nós** | Alocação dinâmica e inicialização dos nós da árvore. |
| **Inserção** | Inserção de valores seguindo as regras de uma árvore binária de busca. |
| **Cálculo de altura** | Controle da altura de cada nó da árvore. |
| **Fator de balanceamento** | Identificação do nível de equilíbrio dos nós. |
| **Rotações** | Correção automática de desequilíbrios por meio de rotações. |
| **Percurso em ordem** | Exibição dos elementos em ordem crescente. |
| **Percurso pré-ordem** | Exibição dos elementos começando pela raiz. |
| **Visualização da árvore** | Representação da estrutura da árvore no terminal. |

## Tecnologias

### Linguagem e compilação

- **C:** linguagem utilizada para implementar as estruturas e operações da árvore.
- **GCC:** compilador utilizado para gerar o executável.
- **Make:** automatização do processo de compilação por meio de um Makefile.

## Arquitetura do projeto

O projeto utiliza uma organização simples, separando as declarações das funções, suas implementações e o código responsável pela execução dos testes.

### Arquivo — `avl.h`

Responsável pela declaração da estrutura do nó e dos protótipos das funções utilizadas na implementação.

### Arquivo — `avl.c`

Contém a implementação das operações da árvore AVL, incluindo criação de nós, inserção, cálculo de altura, fator de balanceamento e rotações.

### Arquivo — `main.c`

Responsável pela execução do programa, definição dos valores de teste e visualização dos resultados no terminal.

## Casos de balanceamento

A implementação contempla os quatro casos de desequilíbrio de uma árvore AVL:

| Caso | Descrição | Rotação |
| --- | --- | --- |
| **LL (Left-Left)** | Inserção na subárvore esquerda do filho esquerdo. | Rotação à direita. |
| **RR (Right-Right)** | Inserção na subárvore direita do filho direito. | Rotação à esquerda. |
| **LR (Left-Right)** | Inserção na subárvore direita do filho esquerdo. | Rotação à esquerda e depois à direita. |
| **RL (Right-Left)** | Inserção na subárvore esquerda do filho direito. | Rotação à direita e depois à esquerda. |

## Estrutura de diretórios

```text
estrutura-arvore-AVL/
│
├── include/
│   └── avl.h
│
├── src/
│   ├── avl.c
│   └── main.c
│
├── Makefile
└── README.md
```

## Como executar

### Pré-requisitos

- GCC instalado.
- Make instalado.

### 1. Clonar o repositório

```bash
git clone URL_DO_REPOSITORIO
cd estrutura-arvore-AVL
```

### 2. Compilar o projeto

```bash
make
```

### 3. Executar

```bash
make run
```

### 4. Limpar o executável

```bash
make clean
```

## Objetivo

O projeto tem finalidade acadêmica e busca consolidar conhecimentos sobre estruturas de dados, alocação dinâmica de memória, ponteiros e recursividade.

A implementação também permite compreender como as árvores AVL mantêm sua estrutura balanceada, explorando na prática os mecanismos de rotação e organização dos elementos.

---

<div align="center">

## Desenvolvedor

**Geovane Neves**

[GitHub](https://github.com/geovane-nves)

<sub>Estruturas de Dados · Linguagem C · Árvore AVL</sub>

</div>