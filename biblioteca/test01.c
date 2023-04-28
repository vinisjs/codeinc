#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char title[100];
  char author[100];
  char publisher[100];
  int year;
  int pages;
  int id;
  int status;
} Book;

typedef struct
{
  Book books[100];
  int size;
} Biblioteca;

void createBook(Book *book);
void listBooks(Book *book);
void searchBook(Book *book);
void editBook(Book *book);
void deleteBook(Book *book);

int main()
{
  Biblioteca biblioteca;
  biblioteca.size = 0;
  int option;
  int opv;

  Book book;

  printf("Bem-vindo a biblioteca!\n");
  printf("Escolha uma opcao:\n");
  printf("1 - Criar livro\n");
  printf("2 - Listar livros\n");
  printf("3 - Buscar livro\n");
  printf("4 - Editar livro\n");
  printf("5 - Excluir livro\n");
  printf("6 - Sair\n");

  scanf("%d", &option);

  do
  {
    if (option == 1)
    {
      createBook(&book);
    }
    else if (option == 2)
    {
      listBooks(&book);
    }
    else if (option == 3)
    {
      searchBook(&book);
    }
    else if (option == 4)
    {
      editBook(&book);
    }
    else if (option == 5)
    {
      deleteBook(&book);
    }
    else if (option == 6)
    {
      printf("Deseja realmente sair? (1 - Sim, 2 - Nao)\n");
      scanf("%d", &opv);
      exit(0);
    }
    else
    {
      printf("Opcao invalida!\n");
    }
  } while (opv != 1);
}

void createBook(Book *book)
{
  printf(" Digite o titulo do livro: ");
  scanf(" %[^\n]s", (*book).title);
  printf(" Digite o autor do livro: ");
  scanf(" %[^\n]s", (*book).author);
  printf(" Digite o editora do livro: ");
  scanf(" %[^\n]s", (*book).publisher);
  printf(" Digite o ano do livro: ");
  scanf(" %d", &(*book).year);
  printf(" Digite o numero de paginas do livro: ");
  scanf(" %d", &(*book).pages);
  printf(" Digite o status do livro: ");
  scanf(" %d", &(*book).status);

  printf("Criando livro...\n");
}

void listBooks(Book *book)
{
  printf("Listando livros...\n");
  printf("Titulo: %s", (*book).title);
  printf("Autor: %s", (*book).author);
  printf("Editora: %s", (*book).publisher);
  printf("Ano: %d", (*book).year);
  printf("Paginas: %d", (*book).pages);
  printf("Id: %d", (*book).id);
  printf("Status: %d", (*book).status);
}

void searchBook(Book *book)
{
}

void editBook(Book *book)
{
}

void deleteBook(Book *book)
{
}
