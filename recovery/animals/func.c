#include "func.h"

void findAndReadFile(int *argc, char const **argv, FILE **file, int *totalInFile)
{
  *file = fopen(*argv, "r");
  if (*argc < 2 && *file == NULL)
  {
    printf("Error file not found.\n");
    printf("Error to read file.\n");

    printf("Digite a quantidade de animais: ");
    scanf(" %d", &(*totalInFile));
    printf("Total of animals: %d\n", (*totalInFile));
    // exit(1);
  }
  else
  {
    printf("Sucess to find file.\n");
    printf("Sucess to read file.\n");
    fscanf(*file, "%d", totalInFile);
    printf("Total in file: %d\n", *totalInFile);
  }
}

void createObjectAnimals(Animals **animal, int *totalInFile, FILE **file, int *i, int *j)
{
  *animal = malloc(sizeof(Animals) * (*totalInFile));

  if (*animal == NULL)
  {
    printf("Erro: Falha ao alocar memória.\n");
    exit(1);
  }

  for (*i = 0; *i < *totalInFile; (*i)++)
  {
    printf("Animal [%d]:\n", *i + 1);
    printf("Nome do animal: ");
    scanf(" %[^\n]", (*animal)[*i].name);

    printf("Quantidade de remédios: ");
    scanf("%d", &(*animal)[*i].remedyCount);

    if ((*animal)[*i].remedyCount > 30)
    {
      printf("Erro: Limite máximo de remédios excedido.\n");
      exit(1);
    }

    for (int a = 0; a < (*animal)[*i].remedyCount; a++)
    {
      printf("Remédio [%d]:\n", a + 1);
      printf("Nome do remédio: ");
      scanf(" %[^\n]", (*animal)[*i].remedy[a].name);

      printf("Data do remédio (DD/MM/AAAA): ");
      scanf(" %[^\n]", (*animal)[*i].remedy[a].date);
    }
    printf("Nome do pagador: ");
    scanf(" %[^\n]", (*animal)[*i].person.name);
  }
}

void readObjectAnimal(Animals **animal, int *totalInFile)
{
  system("clear");
  for (int j = 0; j < *totalInFile; j++)
  {
    printf("----- -----\n");
    printf("ID: %d\n", j + 1);
    printf("Animal: %s\n", (*animal)[j].name);

    for (int a = 0; a < (*animal)[j].remedyCount; a++)
    {
      printf("Remédio %d: %s\n", a + 1, (*animal)[j].remedy[a].name);
      printf("Data do Remédio %d: %s\n", a + 1, (*animal)[j].remedy[a].date);
    }

    printf("Pagador: %s\n", (*animal)[j].person.name);
  }
}

void genereteRelatory(Animals **animal, int *totalInFile, FILE **relatory)
{
  *relatory = fopen("relatory.txt", "w");
  if (*relatory == NULL)
  {
    printf("Fail to create relatory");
    exit(0);
  }

  for (int j = 0; j < *totalInFile; j++)
  {
    fprintf(*relatory, "ID: %d\n", j + 1);
    fprintf(*relatory, "Animal: %s\n", (*animal)[j].name);

    for (int a = 0; a < (*animal)[j].remedyCount; a++)
    {
      fprintf(*relatory, "Remédio %d: %s\n", a + 1, (*animal)[j].remedy[a].name);
      fprintf(*relatory, "Data do Remédio %d: %s\n", a + 1, (*animal)[j].remedy[a].date);
    }

    fprintf(*relatory, "Pagador: %s\n", (*animal)[j].person.name);
  }
}
