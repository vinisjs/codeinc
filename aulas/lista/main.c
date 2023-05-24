#include "declaration.h"

int main(int argc, char const *argv[])
{
  int op, value, ref;
  No *Top = NULL;
  do
  {
    printf("Select on option in bottom\n");
    printf("\n0 - Exit\n1 - Insert to Init\n2 - Insert to Here\n3 - Insert to End\n4 - Impress\n: ");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
      printf("\nValue: ");
      scanf(" %d", &value);
      InsertToInit(&Top, value);
      break;
    case 2:
      printf("\nValue: ");
      scanf(" %d", &value);
      printf("\nRef: ");
      scanf(" %d", &ref);
      InsertToHere(&Top, value, ref);
      break;
    case 3:
      printf("\nValue: ");
      scanf(" %d", &value);
      InsertToEnd(&Top, value);
      break;
    case 4:
      impress(Top);
      break;
    default:
      break;
    }
  } while (op != 0);

  return 0;
}
