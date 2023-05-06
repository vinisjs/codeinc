#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a
{
  char name[30];
  float score;
  char validate[30];
  int id;
} Allums;

void findFile(int *argc)
{
  system("clear");
  printf("\n\nTHIS PROGRAM RETURN LOGS\n");

  /* Inicialização: Localizar o Arquivo*/
  if (*argc < 2)
  {
    printf("\nError to find file\n");
    exit(0);
  }
  printf("\nSucess to find file\n");
}

int main(int argc, char const *argv[])
{
  findFile(&argc);
  /* Inicialização: Abrir o Arquivo*/
  FILE *file;

  file = fopen(argv[1], "r");

  if (file == NULL)
  {
    printf("\nError to Open file\n");
    return -1;
  }

  printf("\nSucess to open file\n");

  // Variable Declaretions
  int qnt;

  // First Reader (primeira linha)
  fscanf(file, "%d", &qnt);
  printf("\nQNT Students: %d\n", qnt);

  // Create "object" allumns.
  Allums *student;

  student = malloc(sizeof(Allums) * qnt);
  if (student == NULL)
  {
    printf("Error to alocate memory\n");
  }
  printf("Success to create an object Student\n");

  int i = 0;

  while (!feof(file))
  {
    student[i].id = i;

    fscanf(file, "%s", student[i].name);

    if (feof(file))
    {
      break;
    }

    fscanf(file, "%f", &student[i].score);

    i++;
  }

  int total;

  total = i;

  printf("\nTotal on File: %d\n", total);

  printf("\t The File \t\n");

  for (i = 0; i < total; i++)
  {
    printf("id[%d]\t", student[i].id);
    printf("Name: %s\t", student[i].name);
    printf("Score: %.2f\n", student[i].score);
  }

  printf("\n");

  int j;

  for (i = 0; i < total; i++)
  {
    for (j = i + 1; j < total; j++)
    {
      if (strcmp(student[i].name, student[j].name) == 0)
      {
        strcpy(student[j].validate, student[i].name);
      }
    }

    if (strcmp(student[i].name, student[i].validate) == 0)
    {
      printf("[%d] \tDuplicated: %s\n", i, student[i].name);
    }
    else
    {
      strcpy(student[i].validate, student[i].name);
    }
  }

  fclose(file);
  free(student);

  return 0;
}
