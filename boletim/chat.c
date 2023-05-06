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

int main(int argc, char const *argv[])
{
  /* Verifica se o caminho do arquivo foi fornecido */
  if (argc < 2)
  {
    printf("Error: file path not provided\n");
    exit(1);
  }

  /* Abre o arquivo */
  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Error: cannot open file\n");
    exit(1);
  }

  /* Lê o número de alunos */
  int num_students;
  fscanf(file, "%d", &num_students);
  printf("Number of students: %d\n", num_students);

  /* Aloca memória para os alunos */
  Allums *students = malloc(sizeof(Allums) * num_students);
  if (students == NULL)
  {
    printf("Error: cannot allocate memory\n");
    exit(1);
  }

  /* Lê os dados dos alunos do arquivo */
  for (int i = 0; i < num_students; i++)
  {
    students[i].id = i;
    fscanf(file, "%s%f", students[i].name, &students[i].score);
  }

  /* Filtra alunos com nomes duplicados */
  for (int i = 0; i < num_students; i++)
  {
    for (int j = i + 1; j < num_students; j++)
    {
      if (strcmp(students[i].name, students[j].name) == 0)
      {
        strcpy(students[j].validate, students[i].name);
      }
    }

    if (strcmp(students[i].name, students[i].validate) == 0)
    {
      printf("Duplicate student: id[%d] %s\n", students[i].id, students[i].name);
    }
    else
    {
      strcpy(students[i].validate, students[i].name);
    }
  }

  /* Calcula a média e média geral */
  float total_score = 0;
  for (int i = 0; i < num_students; i++)
  {
    total_score += students[i].score;
  }
  float average = total_score / num_students;
  printf("Class average score: %.2f\n", average);

  /* Imprime boletim */
  printf("\nClass Report Card\n");
  for (int i = 0; i < num_students; i++)
  {
    printf("id[%d] Name: %s Score: %.2f\n", students[i].id, students[i].name, students[i].score);
  }
  printf("Class average score: %.2f\n", average);

  /* Fecha o arquivo e libera a memória alocada */
  fclose(file);
  free(students);

  return 0;
}
