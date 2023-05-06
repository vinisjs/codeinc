#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
  char name[30];
  float score;
  char validate[30];
} Allums;

int main(int argc, char const *argv[])
{
  system("clear");
  printf("\n\nTHIS PROGRAM RETURN LOGS\n");

  /* Inicialização: Localizar o Arquivo*/
  if (argc < 2)
  {
    printf("\nError to find file\n");
    return -1;
  }
  printf("\nSucess to find file\n");

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
  printf("quantidade: %d\n", qnt);

  // Create "object" allumns.
  Allums *student;

  student = malloc(sizeof(Allums) * qnt);
  if (student == NULL)
  {
    printf("Error to alocate memory\n");
  }
  printf("\nSuccess to create an object Student\n");

  for (int i = 0; i < qnt; i++)
  {
    fscanf(file, "%s", student[i].name);
    fscanf(file, "%f", &student[i].score);
  }

  printf("\n\n");
  for (int i = 0; i < qnt; i++)
  {
    printf("Name: %s\t", student[i].name);
    printf("Score: %.2f\n", student[i].score);
  }

  fclose(file);
  // Create Relatory
  FILE *rel;
  
  rel = fopen("Relatorio.md", "w");

  if (rel == NULL)
  {
    printf("\nError on file of relatory\n");
    return -1;
  }
  printf("\nRelatory Create Sucess\n");
  for (int i = 0; i < qnt; i++)
  {
    fprintf(rel,"Name: %s\t", student[i].name);
    fprintf(rel,"Score: %.2f\n", student[i].score);
  }
  fclose(rel);

  free(student);
  return 0;
}
