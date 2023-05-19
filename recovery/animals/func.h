#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  char name[30];
  char date[11];
} Remedy;

typedef struct b
{
  char name[30];
} Person;

typedef struct c
{
  char name[30];
  int remedyCount;
  Remedy remedy[30];
  Person person;
} Animals;

void findAndReadFile(int *argc, char const **argv, FILE **file, int *totalInFile);
void createObjectAnimals(Animals **animal, int *totalInFile, FILE **file, int *i, int *j);
void readObjectAnimal(Animals **animal, int *totalInFile);
void genereteRelatory(Animals **animal, int *totalInFile, FILE **relatory);