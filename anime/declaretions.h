#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  char name[50];
  int ep;
  char nameEp[50];
  char resume[500];
  struct a *next;
} Anime;

void openFile(FILE **file, char const **argv, int *argc);