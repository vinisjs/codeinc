#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd);

int main(int argc, char const *argv[])
{
  int *x1, *x2, *x3, n1, n2, qtd, i;

  printf("tamanho do primeiro vetor:");
  scanf("%d", &n1);

  x1 = (int *)malloc(sizeof(int) * n1);
  if (x1 == NULL)
  {
    printf("erro ao alocar.\n");
    return -1;
  }
  for (int i = 0; i < n1; ++i)
  {
    scanf("%d", &x1[i]);
  }

  printf("tamanho do segundo vetor:");
  scanf("%d", &n2);

  x2 = (int *)malloc(sizeof(int) * n2);
  if (x2 == NULL)
  {
    printf("erro ao alocar.\n");
    free(x1);
    return -1;
  }
  for (int i = 0; i < n2; ++i)
  {
    scanf("%d", &x2[i]);
  }
  x3 = uniao(x1, x2, n1, n2, &qtd);

  printf("%d\n", qtd);

  for (i = 0; i < qtd; ++i)
  {
    printf("%d\t", x3[i]);
  }
  free(x1);
  free(x2);
  free(x3);
  return 0;
}

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd)
{
  int i = 0, j = 0, n;
  *qtd = 0;
  int *x3;

  x3 = (int *)malloc(sizeof(int) * (n1 + n2));

  while (i < n1 && j < n2)
  {
    if (x1[i] < x2[j])
    {
      x3[*qtd] = x1[i];
      i++;
    }
    else
    {
      if (x1[i] > x2[j])
      {
        x3[*qtd] = x2[j];
        j++;
      }
      else
      {
        x3[*qtd] = x1[j];
        j++;
        i++;
      }
    }
    (*qtd)++;
  }
  if (i < n1)
  {
    for (n = i; n < n1; ++n)
    {
      x3[*qtd] = x1[n];
      (*qtd)++;
    }
  }
  if (j < n2)
  {
    for (n = j; n < n2; ++n)
    {
      x3[*qtd] = x2[n];
      (*qtd)++;
    }
  }
  return x3;
}
