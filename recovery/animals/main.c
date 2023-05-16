#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  char name[30];
  char date[10];
} Remedy;

typedef struct b
{
  char name[30];
} Person;

typedef struct c
{
  char name[30];
  Remedy remedy[30];
  Person person;
} Animals;

void findAndReadFile(int *argc, char const **argv, FILE **file, int *totalInFile);
void createObjectAnimals(Animals **animal, int *totalInFile, FILE **file, int *i, int *j);

int main(int argc, char const *argv[])
{
  system("clear");
  FILE *file;
  Animals *animal;
  int i = 0;
  int j = 0;
  int totalInFile = 0;

  findAndReadFile(&argc, &argv[1], &file, &totalInFile);
  createObjectAnimals(&animal, &totalInFile, &file, &i, &j);

  fclose(file);
  free(animal);
  return 0;
}

void findAndReadFile(int *argc, char const **argv, FILE **file, int *totalInFile)
{
  if (*argc < 2)
  {
    printf("Error to find file\n");
    exit(0);
  }

  *file = fopen(*argv, "r");

  if (*file == NULL)
  {
    printf("Error to read file\n");
    exit(0);
  }

  fscanf(*file, "%i", &*totalInFile);
  printf("Total in file: %d\n", *totalInFile);
}

void createObjectAnimals(Animals **animal, int *totalInFile, FILE **file, int *i, int *j)
{
  *animal = malloc(sizeof(Animals) * (*totalInFile));

  if (*animal == NULL)
  {
    printf("Fail to alloc memory\n");
  }

  while (!feof(*file))
  {
    fscanf((*file), " %[^\n]s", (*animal)[*i].name);
    fscanf((*file), " %[^\n]s", (*animal)[*i].remedy[*i].name);

    if (feof((*file)))
    {
      printf("end file \n");
      break;
    }

    fscanf((*file), " %[^\n]s", (*animal)[*i].remedy[*i].date);
    fscanf((*file), " %s[^\n]", (*animal)[*i].person.name);

    (*i)++;
  }

  (*i)--; // gambiarra

  for ((*j) = 0; (*j) < (*i); (*j)++)
  {
    printf("----- -----\n");
    printf("id [%d]\n", *j);
    printf("Animal..: %s \n", (*animal)[*j].name);
    printf("Medicine..: %s \n", (*animal)[*j].remedy[*j].name);
    printf("Remedy Date..: %s \n", (*animal)[*j].remedy[*j].date);
    printf("Payer..: %s\n", (*animal)[*j].person.name);
  }
}
