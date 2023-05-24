#include "declaretions.h"

void openFile(FILE **file, char const **argv, int *argc)
{
  char path[50];
  if (*argc < 2)
  {
    printf("Error to recive file\n");
    printf("Please enter the file path\n");
    scanf(" %[^\n]s", path);
    *argv = path;
  }
  *file = fopen(*argv, "r");
  if (*file == NULL)
    printf("error to open file\n");
  fclose(*file);
  exit(0);
}