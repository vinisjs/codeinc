#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[100];
  int age;
} User;

typedef struct
{
  char title[100];
  char author[100];
  int year;
} Book;

User get_user_data()
{
  User user;
  printf("Digite seu nome: ");
  scanf("%[^\n]s", user.name);
  printf("Digite sua idade: ");
  scanf(" %d", &user.age);
  return user;
}

Book get_book_data()
{
  Book book;
  printf("Digite o título do livro: ");
  scanf(" %[^\n]s", book.title);
  printf("Digite o nome do autor: ");
  scanf(" %[^\n]s", book.author);
  printf("Digite o ano de publicação: ");
  scanf(" %d", &book.year);
  return book;
}

void impress(User user, Book book)
{
  system("clear");
  printf("Relatório:\n");
  printf("Usuário:\n");
  printf("Nome: %s\n", user.name);
  printf("Idade: %d\n", user.age);
  printf("\n");
  printf("Livro:\n");
  printf("Título: %s\n", book.title);
  printf("Autor: %s\n", book.author);
  printf("Ano de publicação: %d\n", book.year);
}

int main()
{
  User user = get_user_data();
  Book book = get_book_data();
  impress(user, book);
  return 0;
}
