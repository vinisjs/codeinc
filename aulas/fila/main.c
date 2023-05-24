#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
  int a;
  struct a *Next;
} No;

void push(No **fila)
{
  No *New, *ax = malloc(sizeof(No));
  if (New)
  {
    New->Next = NULL;

    if (*fila == NULL)
    {
      *fila = New;
    }
    else
    {
      ax = *fila;
      while (ax->Next)
      {
        ax = ax->Next;
      }
      ax->Next = New;
    }
  }
  else
    printf("error\n");
}

No *pop(No **fila)
{
  No *Rm = NULL;
  if (*fila)
  {
    Rm = *fila;
    *fila = Rm->Next;
  }
  else
  {
    printf("fila vazia");
  }
  return Rm;
}

void impress(No *fila)
{
  printf("t\--- FILA ---\t\n");
  while (fila)
  {
    printf("t\--- FILA ---");
    fila = fila->Next;
  }

  printf("t\--- FILA ---");
}

int main(int argc, char const *argv[])
{
  int op;
  No *Fila = NULL;

  do
  {
    printf("");
  } while (op != 0);

  return 0;
}
