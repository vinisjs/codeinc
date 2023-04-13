#include <stdio.h>
#include <stdlib.h>

int main()
{
  int rows, cols, i, j;
  int **matrix;

  printf("Enter number of rows and columns:\n");
  scanf("%d %d", &rows, &cols);

  // aloca memória para o array de ponteiros
  matrix = (int **)malloc(rows * sizeof(int *));

  // aloca memória para cada linha do array
  for (i = 0; i < rows; i++)
  {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // inicializa a matriz com valores
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      matrix[i][j] = i * j;
    }
  }

  // imprime a matriz
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // libera memória alocada
  for (i = 0; i < rows; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}
