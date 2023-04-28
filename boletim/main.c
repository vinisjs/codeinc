#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

typedef struct
{
  char name[SIZE];
  char email[SIZE];

  int age;

} alumn;

void menu();
int main(int argc, char const *argv[])
{
  menu();

  return 0;
}

void menu()
{
  printf("");
}
