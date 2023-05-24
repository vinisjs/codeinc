#include "declaration.h"

// insert in init
void InsertToInit(No **list, int value)
{
  No *New = malloc(sizeof(No));

  if (New)
  {
    New->Value = value;
    // (*New).Value = value;
    New->Next = *list;

    *list = New;
  }
  else
    printf("Error to alloc Memory\n");
}

void InsertToEnd(No **list, int value)
{
  No *Aux, *New = malloc(sizeof(No));

  if (New)
  {
    New->Value = value;
    New->Next = NULL;

    // its firts?
    if (*list == NULL)
    {
      *list = New;
    }
    else
    {
      Aux = *list;
      while (Aux->Next)
      {
        Aux = Aux->Next;
      }
      Aux->Next = New;
    }
  }
  else
    printf("Error to alloc Memory\n");
}

void InsertToHere(No **list, int value, int ref)
{
  No *Aux, *New = malloc(sizeof(No));

  if (New)
  {
    New->Value = value;

    // its first?
    if (*list == NULL) // é p primero?
    {
      New->Next = NULL;
      *list = New;
    }
    else
    {
      Aux = *list; // a aux serve pra não quebrar na main

      while (Aux->Value != ref && Aux->Next) // busca a ref e que tenha um valor de prox
      {
        Aux = Aux->Next;
      }
      New->Next = Aux->Next;
      Aux->Next = New;
    }
  }
  else
    printf("Error to alloc Memory\n");
}

void impress(No *list)
{
  printf("\n\tLista: ");
  while (list)
  {
    printf("valor: %d\t", list->Value);
    list = list->Next;
  }
  printf("\n\n");
}