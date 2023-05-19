#include "func.h"

int main(int argc, char const *argv[])
{
  system("clear");
  FILE *file;
  FILE *relatory;
  Animals *animal;
  int i = 0;
  int j = 0;
  int totalInFile = 0;

  findAndReadFile(&argc, &argv[1], &file, &totalInFile);
  createObjectAnimals(&animal, &totalInFile, &file, &i, &j);
  readObjectAnimal(&animal, &totalInFile);
  genereteRelatory(&animal, &totalInFile, &relatory);

  if (file != NULL)
    fclose(file);
  free(animal);
  return 0;
}

