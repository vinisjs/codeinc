#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
} Person;

typedef struct
{
  char name[30];
  char medicament[50];
  float date;

  Person user;
} Animal;

void readFile(int r, char const **d, FILE **file, int *q);
void createAnimals(FILE **file, Animal **animal, int *q);

int main(int argc, char const *argv[])
{
  system("clear");
  FILE *file;
  Animal *animal;
  int qnt;

  readFile(argc, &argv[1], &file, &qnt);
  createAnimals(&file, &animal, &qnt);

  printf("\ntotal on main: %d\n", qnt);

  fclose(file);
  free(animal);
  return 0;
}

void readFile(int r, char const **d, FILE **file, int *q)
{
  if (r < 2)
  {
    printf("Error to find file\n");
  }
  printf("Sucess to find file\n");

  *file = fopen(*d, "r");

  if (*file == NULL)
  {
    printf("Error to read file");
  }

  printf("Sucess to read File\n");

  fscanf(*file, "%d", &*q);
  printf("Sucess to read and save total animal's on file: %d\n", *q);
}

void createAnimals(FILE **file, Animal **animal, int *q)
{
  *animal = malloc(sizeof(Animal) * (*q));

  if (*animal == NULL)
    printf("Error to alloc memory from animal's");

  printf("in func: %d\n", *q);
  int i = 0;

  while (!feof(*file))
  {
    fscanf(*file, "%s", (*animal)[i].name);
    fscanf(*file, "%s", (*animal)[i].medicament);
    fscanf(*file, "%f", &(*animal)[i].date);
    fscanf(*file, "%s", (*animal)[i].user.name);
    i++;
  }

  int j = 0;

  printf("\n");
  printf("Animal \t Medicamento \t Data \t Pessoa \n");
  for (j = 0; j < i; j++)
  {
    printf("%s \t", (*animal)[j].name);
    printf("%s \t", (*animal)[j].medicament);
    printf("%.0f \t", (*animal)[j].date);
    printf("%s \t", (*animal)[j].user.name);
    printf("\n");
  }
  printf("\n");

  FILE *rel;
  rel = fopen("readme.md", "w");

  fprintf(rel, "Animal \t Medicamento \t Data \t Pessoa \n");
  printf("gerando relatório");
  for (j = 0; j < i; j++)
  {
    printf(" .");
    fprintf(rel, "%s ", (*animal)[j].name);
    fprintf(rel, "%s ", (*animal)[j].medicament);
    fprintf(rel, "%.0f ", (*animal)[j].date);
    fprintf(rel, "%s \n", (*animal)[j].user.name);
  }
}
