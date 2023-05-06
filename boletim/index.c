#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  char name[30];
  int id;
  float points;
} allumn;

int compareTo(const char *str1, const char *str2);
char *copy(char *dest, const char *src);
void remover_aluno(allumn *alunos, int *num_alunos, int indice);

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
  int qnt = 0;
  int i = 0;
  fscanf(file, "%d", &qnt);

  printf("quantpoints: %d\n", qnt);

  alunos = malloc(qnt * sizeof(allumn));

  if (alunos == NULL)
  {
    printf("error to create allumn\n");
    return -1;
  }

  while (!feof(file))
  {
    fscanf(file, " %s", alunos[i].name);

    if (feof(file))
    {
      break;
    }
    fscanf(file, " %f", &alunos[i].points);
    // verificarDuplicata()

    // printf("name: %s\n", alunos[i].name);
    // printf("nota: %.2f\n", alunos[i].points);

    i++;
  }
  int numAlunos = i;
  // printf("\n\ni: %d\n", i);
  int j = numAlunos, k = 0, o = 0;
  int numeroAlunosRemovidos;
  int aux = 0;
  int jhl = 0;
  for (jhl = 0; jhl < 18; jhl++)
  {
    printf("\n%s", alunos[jhl].name);
  }

  while (j != 0)
  {

    // printf("\n\n\n%d unnnnn", numAlunos);
    numeroAlunosRemovidos = 0;
    for (k = aux; k < numAlunos; k++)
    {
      printf("num alunooo %d", numAlunos);
      //  printf("\n\nkkkkkkkk %d e num alunos ssss %d", k, numAlunos);
      if (compareTo(alunos[j].name, alunos[k].name) == 1)
      {
        // puts("works");
        printf("\n\na pessoa %s %d", alunos[j].name, aux);
        alunos[j].points += alunos[k].points;
        remover_aluno(&alunos, &numAlunos, k);
        numeroAlunosRemovidos++;
        numAlunos--;
        // copy(alunos[k].name, "");
      }
    }
    aux += 1;
    j -= numeroAlunosRemovidos;
    j--;
  }
  // printf("%d\n", compareTo(alunos[0].name, alunos[2].name));

  // free(alunos);
  int jh = 0;
   for (jh = 0; jh < numAlunos; jh++)
  {

    printf("\n\nname: %s\n", alunos[jh].name);
    printf("nota: %.2f\n", alunos[jh].points);
  }
  return 0;
}

int compareTo(const char *str1, const char *str2)
{
  int i = 0;
  printf("\n\n%c", str1[i]);
  while (str1[i] == str2[i])
  {
    printf("\n\n%c", str1[i]);
    if (str1[i] == '\0')
    {
      return 1;
    }
    i++;
  }
  return -1;
}

char *copy(char *dest, const char *src)
{
  char *p = dest;
  while (*src != '\0')
  {
    *p++ = *src++;
  }
  *p = '\0';
  return dest;
}

void remover_aluno(allumn *alunos, int *num_alunos, int indice)
{
  int i;
  // Deslocar todos os objetos subsequentes para preencher o espaço vazio deixado pelo objeto removido
  for (i = indice; i < *num_alunos - 1; i++)
  {
    copy(alunos[i].name, alunos[i + 1].name);
    alunos[i].points = alunos[i + 1].points;
  }

  // Decrementar o número de funcionários
}