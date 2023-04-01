#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[50];
  float width;
  float heigth;
  int arv_qnt;
  int const_qnt;
} Setores;

typedef struct
{
  char especie[250];
  int age;
  int name[250];
  int porte;
} Arvores;

void cadSetore(Setores *setore, int *u);
void cadArvore(Arvores *arvore, int *u);
void menu(Setores *setore[], Arvores *arvore[], int *u);
void listagem(Setores *setore[], Arvores *arvore[], int *u);

int main()
{
  int u = 3;
  int i = 0;

  Setores setore[u];
  Arvores arvores[u];

  for (i = 0; i < u; i++)
  {
    menu(&setore[i], &arvores[i], &u);
  }

  printf("\n\n");
  // for (i = 0; i < u; i++)
  // {
  //   printf("O nome do setor: %s\n", setore[i].name);
  //   printf("A altura: %.2f\n", setore[i].heigth);
  //   printf("A largura: %.2f\n", setore[i].width);
  //   printf("A quantidade de árvores: %d\n", setore[i].arv_qnt);
  // }
}

void menu(Setores *setore[], Arvores *arvore[], int *u)
{

  int op;
  printf("\n########### SISTEMA DE CADASTRO - IFMSTREE ###########");
  printf("\n\n[0] - Cadastrar Setores");
  printf("\n[1] - Cadastrar Arvore");
  printf("\n[2] - Listar dados");
  printf("\n:");
  scanf(" %d", &op);

  switch (op)
  {
  case 0:

    cadSetore(setore, u);
    break;
  case 1:
    cadArvore(arvore, u);
    break;
  case 2:
    listagem(setore, arvore, u);
    break;
  default:
    menu(setore, arvore, u);
    break;
  }
}

void listagem(Setores *setore[], Arvores *arvore[], int *u)
{
  // listagem de setores
  int i;
  for (i = 0; i < *u; i++)
  {
    printf("id: [%d]", i);
    printf("O nome do setor: %s\n", setore[i]->name);
    printf("A altura: %.2f\n", setore[i]->heigth);
    printf("A largura: %.2f\n", setore[i]->width);
    printf("A quantidade de árvores: %d\n", setore[i]->arv_qnt);
  }
  // listagem de arvores
  for (i = 0; i < *u; i++)
  {
    printf("id: [%d]", i);
    printf("Especie: %s\n", arvore[i]->especie);
    printf("Idade: %d\n", arvore[i]->age);
    printf("Nome: %s\n", arvore[i]->name);
    printf("Porte: %d\n", arvore[i]->porte);
  }
}

void cadSetore(Setores *setore, int *u)
{
  int i;

  for (i = 0; i < *u; i++)
  {
    printf("Digite o nome do setor [%d]: ", *u);
    scanf(" %[^\n]", setore[i].name);

    printf("Digite a altura: ");
    scanf(" %f", &setore[i].heigth);

    printf("Digite a largura: ");
    scanf(" %f", &setore[i].width);

    printf("Digite a quantidade de árvores: ");
    scanf(" %d", &setore[i].arv_qnt);
  }
}

void cadArvore(Arvores *arvore, int *u)
{
  int i;
  for (i = 0; i < *u; i++)
  {
    printf("\nID [%d]\n", i);
    printf("Digite o nome da especie: ");
    scanf(" %[^\n]", arvore[i].especie);

    printf("Digite a idade: ");
    scanf(" %d", &arvore[i].age);

    printf("Selecione o porte:");
    printf("\n1 - Pequeno ");
    printf("\n2 - Medio ");
    printf("\n3 - Grande ");
    printf("\n:");
    scanf(" %d", &arvore[i].porte);

    printf("Digite o nome de quem plantou: ");
    scanf(" %[^\n]s", arvore[i].name);
  }
}
