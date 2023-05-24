#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a
{
  char name[50];
  int ep;
  char nameEp[50];
  char resume[500];
  int day;
  char month[20];
  int year;
  struct a *next;
} Anime;

Anime createAnime(FILE *file)
{
  Anime newAnime;

  fscanf(file, " %[^\n]s", newAnime.name);
  fscanf(file, " %d", &newAnime.ep);
  fscanf(file, " %[^\n]s", newAnime.resume);
  fscanf(file, " %d", &newAnime.day);
  fscanf(file, " %[^\n]s", newAnime.month);
  fscanf(file, " %d", &newAnime.year);

  return newAnime;
}

void loadListFromFile(Anime **head, const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo para leitura.\n");
    return;
  }

  // Limpar a lista existente antes de carregar do arquivo
  freeList(*head);

  char line[700];
  while (fgets(line, sizeof(line), file) != NULL)
  {
    Anime anime;

    if (sscanf(line, " %[^\n]s", anime.name) == 1 &&
        fscanf(file, " %d", &anime.ep) == 1 &&
        fscanf(file, " %[^\n]s", anime.resume) == 1 &&
        fscanf(file, " %d", &anime.day) == 1 &&
        fscanf(file, " %[^\n]s", anime.month) == 1 &&
        fscanf(file, " %d", &anime.year) == 1)
    {
      anime.next = NULL;
      addNode(head, anime);
    }
    else
    {
      printf("Erro ao ler linha do arquivo: %s\n", line);
    }
  }

  fclose(file);
  printf("Lista carregada do arquivo com sucesso.\n");
}
void addNode(Anime **head, const Anime anime)
{
  Anime *newNode = malloc(sizeof(Anime));
  if (newNode == NULL)
  {
    printf("Falha ao alocar memória.\n");
    return;
  }

  *newNode = anime;
  newNode->next = *head;
  *head = newNode;
}

void freeList(Anime *head)
{
  Anime *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}
