#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[30];
  float score;
} Student;

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

  // Variable Declarations
  int qnt;
  fscanf(file, "%d", &qnt);
  printf("Quantidade: %d\n", qnt);

  // Create array of students
  Student *students;
  students = malloc(sizeof(Student) * qnt);
  if (students == NULL)
  {
    printf("Error to alocate memory\n");
    return -1;
  }

  int i = 0;
  char name[30];
  float score;
  while (fscanf(file, "%s %f", name, &score) == 2)
  {
    int found = 0;
    for (int j = 0; j < i; j++)
    {
      if (strcmp(name, students[j].name) == 0)
      {
        students[j].score += score;
        found = 1;
        break;
      }
    }
    if (!found)
    {
      strcpy(students[i].name, name);
      students[i].score = score;
      i++;
    }
  }

  qnt = i;

  printf("\nTotal de nomes unificados: %d\n", qnt);

  printf("\n\n");
  for (i = 0; i < qnt; i++)
  {
    printf("Name: %s\t", students[i].name);
    printf("Score: %.2f\n", students[i].score);
  }
  printf("\n\n");

  // Create report
  FILE *rel;
  rel = fopen("Relatorio.md", "w");
  if (rel == NULL)
  {
    printf("\nError on file of relatory\n");
    return -1;
  }

  fprintf(rel, "| Nome | Média das notas |\n");
  fprintf(rel, "|------|----------------|\n");
  for (int i = 0; i < qnt; i++)
  {
    float average = students[i].score / 2;
    fprintf(rel, "| %s | %.2f |\n", students[i].name, average);
  }

  fclose(rel);
  free(students);
  return 0;
}
