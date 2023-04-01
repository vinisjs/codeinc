#include <stdio.h>
#include <stdlib.h>

void soma(int *y);

int main()
{
  int number;

  printf("Digite um numero: ");
  scanf(" %d", &number);

  printf("Valor digitado: %d", number);

  soma(&number);

  printf("\nValor atualizado: %d", number);
}

void soma(int *y)
{
  *y = *y + 10;
  return;
}