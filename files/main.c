#include <stdio.h>

int main()
{
  FILE *file;

  file = fopen("file.txt", "w");

  if (file == NULL)
    printf("Erro");

  fprintf(file, "Hello World");

  fclose(file);
  return 0;
}