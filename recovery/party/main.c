#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
  float carne;
  float bebida;
  float aluguel;
  float banda;
} Person;

void openAndReadFile(int *argc, char const **argv, FILE **file, int *totalPerson);
void createUser(Person **user, int *totalPerson, FILE **file, int *i);
void calc(int *j, int *i, Person **user, float const *carne, float const *bebida, float const *banda, float const *aluguel, float *totalCarne, float *totalBebida, float *totalBanda, float *totalAluguel);
void createRelatory(FILE **relatory, int *j, int *i, Person **user, float *totalCarne, float *totalBebida, float *totalBanda, float *totalAluguel);

int main(int argc, char const *argv[])
{
  system("clear");
  FILE *file;
  FILE *relatory;
  Person *user;
  int totalPerson;
  int i = 0, j = 0;

  float const carne = 1.5, bebida = 2.0, banda = 50.00, aluguel = 70.00;
  float totalCarne = 0, totalBebida = 0, totalAluguel = 0, totalBanda = 0;

  openAndReadFile(&argc, &argv[1], &file, &totalPerson);
  createUser(&user, &totalPerson, &file, &i);
  calc(&j, &i, &user, &carne, &bebida, &banda, &aluguel, &totalCarne, &totalBebida, &totalBanda, &totalAluguel);
  createRelatory(&relatory, &j, &i, &user, &totalCarne, &totalBebida, &totalBanda, &totalAluguel);

  free(user);
  fclose(file);
  return 0;
}

void openAndReadFile(int *argc, char const **argv, FILE **file, int *totalPerson)
{
  if (*argc < 2)
  {
    printf("Error: file not specified.\n");
    return;
  }

  *file = fopen(*argv, "r");
  if (*file == NULL)
  {
    printf("Error opening the file.\n");
    return;
  }

  int count = 0;
  char nome[100];

  while (fscanf(*file, " %[^\n]", nome) == 1 || !feof(*file))
  {
    count++;
  }

  *totalPerson = count;
  printf("Total in the file: %d\n", *totalPerson);
}

void createUser(Person **user, int *totalPerson, FILE **file, int *i)
{
  *user = malloc(sizeof(Person) * (*totalPerson));
  if (*user == NULL)
  {
    printf("Error allocating memory for user.\n");
    return;
  }

  rewind(*file);

  for (*i = 0; *i < *totalPerson; (*i)++)
  {
    if (fscanf(*file, " %[^\n]", (*user)[*i].name) != 1)
    {
      printf("Error reading name from file.\n");
      break;
    }
  }
}

void calc(int *j, int *i, Person **user, float const *carne, float const *bebida, float const *banda, float const *aluguel, float *totalCarne, float *totalBebida, float *totalBanda, float *totalAluguel)
{
  int k;
  for (*j = 0; *j < *i; (*j)++)
  {
    (*user)[*j].carne = (*carne);
    (*user)[*j].bebida = (*bebida);
    (*user)[*j].banda = (*banda);
    (*user)[*j].aluguel = (*aluguel);

    (*totalCarne) += (*carne);
    (*totalBebida) += (*bebida);
    (*totalBanda) += (*banda);
    (*totalAluguel) += (*aluguel);
  }

  for (k = 0; k < *i; k++)
  {
    // printf("---------------------------------\n");
    printf("id: %d\n", k);
    printf("Nome: %s \t|\t", (*user)[k].name);
    printf("Carne: %.2fkg \t|\t", (*user)[k].carne);
    printf("Bebida: %.2fl \t|\t", (*user)[k].bebida);
    printf("Banda: %.2f \t|\t", (*user)[k].banda);
    printf("Aluguel: %.2f \t|\n", (*user)[k].aluguel);
  }

  printf("\nTotal Carne: %.2fkg\t|\t", (*totalCarne));
  printf("Total Bebida: %.2fl\t|\t", (*totalBebida));
  printf("Total Banda: %.2f\t|\t", (*totalBanda));
  printf("Total Aluguel: %.2f\t|\n", (*totalAluguel));
}

void createRelatory(FILE **relatory, int *j, int *i, Person **user, float *totalCarne, float *totalBebida, float *totalBanda, float *totalAluguel)
{
  *relatory = fopen("relatory.txt", "w");

  fprintf(*relatory, "-------------------------------------\n");
  fprintf(*relatory, "----------\t The Relatory \t---------\n");
  fprintf(*relatory, "-------------------------------------\n\n");
  for (*j = 0; *j < *i; (*j)++)
  {
    fprintf(*relatory, "Nome..: %s \t|\t", (*user)[*j].name);
    fprintf(*relatory, "Carne..: %.2fkg \t|\t", (*user)[*j].carne);
    fprintf(*relatory, "Bebida..: %.2fl \t|\t", (*user)[*j].bebida);
    fprintf(*relatory, "Banda..: %.2f \t|\t", (*user)[*j].banda);
    fprintf(*relatory, "Aluguel..: %.2f \t|\n", (*user)[*j].aluguel);
  }
  fprintf(*relatory, "\n---------------------------------\n");
  fprintf(*relatory, "Total Carne..: %.2fkg \t|\t", (*totalCarne));
  fprintf(*relatory, "Total Bebida..: %.2fl \t|\t ", (*totalBebida));
  fprintf(*relatory, "Total Banda..: %.2f \t|\t ", (*totalBanda));
  fprintf(*relatory, "Total Aluguel..: %.2f \t|\n", (*totalAluguel));
}