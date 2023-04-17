#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char title[30];
  char days[11]; // um dia tem até 10 caracteres, incluindo a barra
} book;

typedef struct
{
  int qnt;
  book books[31];
} library;

void menu();
void createBook(library *livros, int *ps);

int main()
{
  int i, op, day;

  system("cls");
  printf("\n\n # Sistema de Registro de Leitura # \n\n");

  printf("Quantos dias de Leitura: ");
  scanf(" %d", &day);

  library *Library = malloc(sizeof(library) * day);

  if (Library == NULL)
  {
    printf("Erro de memoria\n");
    free(Library);
    return -1;
  }

  do
  {
    menu();
    scanf(" %d", &op);

    if (op == 1)
      for (i = 0; i < day; i++)
      {
        printf("a) posicao: %i\n", i);
        createBook(&Library[i], &i);
        printf("df)posicao: %i\n\n", i);
      }
    else if (op == 2)
    {
      printf("\n\nRegistros\n\n");
      for (i = 0; i < day; i++)
      {
        printf("Titulo: %s\n", Library[i].books[i].title);
        printf("Data: %s\n", Library[i].books[i].days);
      }
    }
    else if (op == 0)
    {
      free(Library);
      exit(0);
    }
  } while (op != 0);
}

void menu()
{
  printf("\nMenu\n\n");
  printf("1 - Cadastrar Livros\n");
  printf("2 - Relatorio\n");
  printf("0 - Sair\n");
}

void createBook(library *livros, int *ps)
{
  printf("## Registro de Livro ## \n\n");
  printf("[%d] - Titulo de Livro: ", *ps + 1);
  scanf(" %[^\n]s", livros->books[*ps].title);
  printf("[%d] - Data de Leitura (dia,mes,ano): ", *ps + 1);
  scanf(" %[^\n]s", livros->books[*ps].days);
  (*ps)++;
}
