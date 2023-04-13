#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char title[30];
  int qnt;
} Book;

typedef struct
{
  int date;
  Book book;
} Library;

void menu(Library *books);
void createBook(Library *books);

int main()
{
  system("cls");
  Library livro;

  printf("SISTEMA DE GERENCIAMENTO DE LEITURA\n\n");
  menu(&livro);

  printf(":%s\n", livro.book.title);
  printf(":%d", livro.date);
  return 0;
}

void menu(Library *books)
{
  int op;
  do
  {
    printf("Menu\n\n");
    printf("1 - Cadastrar Livros\n");
    printf("2 - Relatorio Mensal\n");
    printf("0 - Sair\n");
    printf(":");
    scanf(" %i", &op);

    if (op == 1)
    {
      createBook(books);
    }
  } while (op != 0);
}

void createBook(Library *books)
{

  printf("Criar Registro\n\n");

  printf("Digite a quantidade de livros lidos: ");
  scanf(" %d", &(*books).book.qnt);

  printf("Titulo do livro: ");
  scanf(" %[^\n]s", (*books).book.title);

  printf("Creating...\n");
}
