#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
  char name[30];
  int qnt;
} Book;

typedef struct
{
  Book books;
  int qnt;
  int date;
} Library;

typedef struct
{
  char name[30];
  int age;
  char email[100];
} Person;

void createUser(Person *US, Library *Biblioteca, Book *Livro);
void createBook(Person *USC, Library *Biblioteca, Book *Livro);
void createLibrary(Person *USC, Library *Biblioteca, Book *Livro);
void menu(Person *USC, Library *Biblioteca, Book *Livro);

void impress();

int main()
{

  Person Usuario;
  Library Biblioteca;
  Book Livros;

  system("cls");
  setlocale(LC_ALL, "Portuguese");
  printf("\nSISTEMA DE GERÊNCIAMENTO DE LEITURA\n\n");
  createUser(&Usuario, &Biblioteca, &Livros);
}

void createUser(Person *US, Library *Biblioteca, Book *Livro)
{
  printf("### Criação de Usuário ###\n\n");

  printf("Digite seu nome: ");
  scanf(" %[^\n]s", (*US).name);

  printf("Digite sua idade: ");
  scanf(" %d", &(*US).age);

  printf("Digite seu e-mail: ");
  scanf(" %[^\n]s", (*US).email);

  printf("Sucesso\n\n");
  menu(US, Biblioteca, Livro);
}

void menu(Person *USC, Library *Biblioteca, Book *Livro)
{
  int op;
  do
  {
    printf("## Menu ## \n\n ");
    printf("1 - Criar Registro\n ");
    printf("0 - Sair\n");
    scanf(" %d", &op);

    if (op == 1)
      createLibrary(USC, Biblioteca, Livro);
    else
      printf("Invalid Option, try again\n");
  } while (op != 0);
}

void createLibrary(Person *USC, Library *Biblioteca, Book *Livro)
{
  int t;
  printf("Cadastro Biblioteca\n\n");

  printf("Quantos dias de leitura: ");
  scanf(" %d", &(*Biblioteca).qnt);

  t = (*Biblioteca).qnt;

  printf("tempo: %d", t);
}