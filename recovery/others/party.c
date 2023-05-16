#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
  float meat, beverage, local, band;
} Person;

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    printf("Error to find file\n");
  }

  FILE *file;

  file = fopen(argv[1], "r");

  if (file == NULL)
  {
    printf("Error on open file\n");
    return -1;
  }
  printf("Sucess to open file\n");

  int qnt;
  fscanf(file, "%i", &qnt);

  printf("Quantidade: %i\n", qnt);

  Person *peopple;

  peopple = malloc(sizeof(Person) * qnt);

  int i = 0;
  while (!feof(file))
  {
    fscanf(file, " %s", peopple[i].name);
    peopple[i].meat = 1.5;
    peopple[i].beverage = 2.0;
    peopple[i].local = 50.00;
    peopple[i].band = 70.00;

    if (feof(file))
    {
      break;
    }
    i++;
  }

  for (int b = 0; b < i; b++)
  {

    printf("Name: %s\t", peopple[b].name);
    printf("Carne: %.2f\t", peopple[b].meat);
    printf("Bebida: %.2f\t", peopple[b].beverage);
    printf("Local: %.2f\t", peopple[b].local);
    printf("Banda: %.2f\t", peopple[b].band);
    printf("\n");
  }

  fclose(file);
  free(peopple);
}
