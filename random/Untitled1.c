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
} Arvores;


void cadSetores(Setores *setore);

int main()
{
  Setores setore;
  cadSetores(&setore);
}

void cadSetores(Setores *setore){

  printf("Digite a o nome do setor: ");
  scanf(" %[^\n]", *setore.name);

  printf("Digite a altura: ");
  scanf(" %f", &*setore.heigth);

  printf("Digite a largura: ");
  scanf(" %f", &*setore.width);

  printf("Digite a quantidade de construcao: ");
  scanf(" %d", &*setore.const_qnt);

  printf("Digite a quantidade de Arvore: ");
  scanf(" %d", &*setore.arv_qnt);

  printf("\n\n");
  printf("a o nome do setor: %s\n", *setore.name);
  printf("a altura: %.2f\n", *setore.heigth);
  printf("a largura: %.2f\n", *setore.width);
  printf("a quantidade de Arvore: %d\n", *setore.arv_qnt);
  printf("a quantidade de construcao: %d\n", *setore.const_qnt);
}
