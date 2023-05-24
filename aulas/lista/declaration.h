/*
  Pilha LIFO: O primeiro a entrar é o último a sair
  FIla FIFO: O primeiro a entrar é o primeiro a sair
  Lista: não tem regras "explicitas".
*/
#include <stdio.h>
#include <stdlib.h>

// template da lista
typedef struct no
{
  int Value;
  struct no *Next;
} No;

void InsertToInit(No **list, int value);
void InsertToEnd(No **list, int value);
void InsertToHere(No **list, int value, int ref);
void impress(No *list);