#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  char name[30];
  int id;
  int points;
} allumn;

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    printf("Error on open\n");
    return -1;
  }
  printf("Sucess to find file\n");

  FILE *file;

  file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Error on open file\n");
    return -1;
  }
  printf("Sucess to open file\n");

  allumn *alunos;

  
  

  return 0;
}
