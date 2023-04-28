#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SETORES 10
#define MAX_ARVORES 10

// Definindo a struct para árvore
typedef struct
{
  char especie[50];
  char porte[20];
  int ano_plantio;
  char nome_plantador[50];
} Arvore;

// Definindo a struct para setor
typedef struct
{
  char nome[50];
  float altura;
  float largura;
  int arv_qnt;
  int constr_qnt;
  Arvore arvores[MAX_ARVORES];
} Setor;

// Protótipos das funções
void cadastrarSetor(Setor *setores, int *qnt_setores);
void cadastrarArvore(Setor *setores, int qnt_setores);
void listarSetores(Setor *setores, int qnt_setores);
void listarArvores(Setor *setores, int qnt_setores);

int main()
{
  Setor setores[MAX_SETORES];
  int qnt_setores = 0;
  int opcao = 0;

  while (opcao != 5)
  {
    printf("\n1 - Cadastrar Setor\n");
    printf("2 - Cadastrar Árvore\n");
    printf("3 - Listar Setores\n");
    printf("4 - Listar Árvores por Setor\n");
    printf("5 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      cadastrarSetor(setores, &qnt_setores);
      break;

    case 2:
      cadastrarArvore(setores, qnt_setores);
      break;

    case 3:
      listarSetores(setores, qnt_setores);
      break;

    case 4:
      listarArvores(setores, qnt_setores);
      break;

    case 5:
      printf("Saindo...\n");
      break;

    default:
      printf("Opção inválida.\n");
      break;
    }
  }

  return 0;
}
