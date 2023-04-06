#include <stdio.h>
#include <stdlib.h>

int main()
{
  int **p;
  int n = 3;
  int i, j;

  p = (int **)malloc(sizeof(int *) * n);

  if (p == NULL)
  {
    printf("\nErr 500");
    return -1;
  }

  for (i = 0; i < n; i++)
  {
    p[i] = (int *)malloc(sizeof(int *) * n);

    if (p[i] == NULL)
    {
      printf("Erro");

      for (int j = 0; j < i; j++)
      {
        free(p[j]);
      }
      free(p);

      return -1;
    }
  }

  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      printf("%d\t %d\n", i, j);
    }
  }

  for (i = 0; i < n; ++i)
  {
    free(p[i]);
  }
  free(p);
  return 0;
}