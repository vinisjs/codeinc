#include <stdio.h>
#include <stdlib.h>
/*
  O sistema deve permitir:
 [ ] - cadastrar setores do campus, 
 [ ] - onde cada setor terá um nome, 
 [ ] - tamanho (altura e largura), 
 [ ] - quantidade de árvores já plantadas, 
 [ ] - quantidade de construções nesse setor 
 [ ] - e a lista de árvores plantadas.

 [ ] - Para cada árvore, o sistema deve ser capaz de armazenar: a espécie, 
 [ ] - o porte, 
 [ ] - o ano de plantio e 
 [ ] - o nome de quem a plantou.

 [ ] - Deve ser possível cadastrar até 10 setores, 
 [ ] - e cada setor pode ter até 10 árvores. 

  O programa não deve ter variáveis globais. 

  Deve haver um: 
  [ ] - menu para cadastrar setores e 
  [ ] - árvores em um setor, 
  [ ] - e deve ser possível listar os setores 
  [ ] - e as árvores em cada setor.

*/

typedef struct a
{
  char name[50];
  float width;
  float heigth;
  int arv_qnt;
  int const_qnt;
} setores;

typedef struct b
{
  char especie[250];
  int age;
  int name[250];
} arvores;

void menu ();
void Cad_Set ();

int main(void){
  system("cls");
  menu();
}

void menu () {
  int op = 0;
  printf("############### MENU ############### \n");
  printf("# 1 - CADASTRO DE SETORES \n");
  printf("# 2 - CADASTRO DE ARVORE \n");
  printf("# 3 - RELATORIO \n");
  printf("# 0 - SAIR \n");
  scanf("%i",&op);

  switch (op)
  {
  case 1:
    Cad_Set();
    break;
  case 2:
    /* code */
    break;
  case 3:
    /* code */
    break;
  case 0:
    // exit();
    break;
  
  default:
    printf("Opcao Invalida \n");
    menu();
    break;
  }
}

void Cad_Set () {
  setores a;

  printf("Nome do Setor: ");
  scanf("%[^\n]s", &a.name);
  printf("O que foi Registrado: %s", a.name);
  menu();
}

