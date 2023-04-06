#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[25];
  float height, width;
  int tree, constructions;

} Sectors;

typedef struct
{
  char species[25];
  int yearOfPlanting;
  char nameOfWhoPlanted[25];

} Tree;

void menu(Sectors *sectors, Tree *tree);
void createSectors(Sectors *sectors);
void retSectors(Sectors *sectors);
void createTree(Tree *tree);
void retTree(Tree *tree);

int main()
{
  Sectors sectors;
  Tree tree;

  menu(&sectors, &tree);
}

void menu(Sectors *sectors, Tree *tree)
{
  int op;
  int opv;
  do
  {
    printf("######### MENU #########\n");
    printf("########################\n");
    printf("[1]Cadastrar Setor      \n");
    printf("[2]Cadastrar Arvore     \n");
    printf("[3]Listar Setores       \n");
    printf("[4]Listar Arvore        \n");
    printf("[5]Sair\n");
    scanf(" %d", &op);

    if (op == 1)
      createSectors(sectors);
    else if (op == 2)
      createTree(tree);
    else if (op == 3)
      retSectors(sectors);
    else if (op == 4)
      retTree(tree);
    else if (op == 5)
    {
      system("cls");
      printf("Deseja Realmente sair?\n");
      printf("[0] - Nao | [1] - Sim\n");
      printf(": ");
      scanf(" %d", &opv);
    }
  } while (opv != 1);
}

void createSectors(Sectors *sectors)
{
  printf("### Cadastro de Setor ###\n\n");
  printf("Digite o nome do Setor: ");
  scanf(" %[^\n]s", (*sectors).name);

  printf("Digite a Altura do Setor: ");
  scanf(" %f", &(*sectors).height);

  printf("Digite a Largura do Setor: ");
  scanf(" %f", &(*sectors).width);

  printf("Digite a Quantidade de Construções: ");
  scanf(" %d", &(*sectors).constructions);
}

void createTree(Tree *tree)
{
  printf("### Cadastro de Arvore ###\n\n");
  printf("Digite a Especie: ");
  scanf(" %[^\n]s", (*tree).species);

  printf("Digite o Ano de Plantio: ");
  scanf(" %d", &(*tree).yearOfPlanting);

  printf("Digite o nome do Plantador: ");
  scanf(" %[^\n]s", (*tree).nameOfWhoPlanted);
}

void retSectors(Sectors *sectors)
{
  printf("\n\n");
  printf("Lista de Setores:\n\n");
  printf("Nome: %s\n", (*sectors).name);
  printf("Altura: %.2f\n", (*sectors).height);
  printf("Largura: %.2f\n", (*sectors).width);
  printf("\n\n");
}

void retTree(Tree *tree)
{
  printf("\n\n");
  printf("Lista de Arvores:\n\n");
  printf("Especie: %s\n", (*tree).species);
  printf("Ano de Plantio: %d\n", (*tree).yearOfPlanting);
  printf("Plantador: %s\n", (*tree).nameOfWhoPlanted);
  printf("\n\n");
}