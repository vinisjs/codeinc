#include <stdio.h>
#include <stdlib.h>

/* LIFO: O último a entrar é o Primeiro a sair */
typedef struct
{
  char name[50];
  int age;
  int class_number;
} Alumn;

typedef struct node
{
  Alumn student;
  struct node *next;
} Node;

Alumn createAlumn(FILE *arquivo)
{
  Alumn newAlumn;
  printf("Digite o nome: ");
  fscanf(arquivo, " %[^\n]s", newAlumn.name);
  printf("Digite a idade: ");
  fscanf(arquivo, " %d", &newAlumn.age);
  printf("Digite o número da turma: ");
  fscanf(arquivo, " %d", &newAlumn.class_number);

  return newAlumn;
}

Node *push(Node *top, Alumn aluno)
{
  Node *newNode = malloc(sizeof(Node));

  if (newNode != NULL)
  {
    newNode->student = aluno;
    newNode->next = top;
    top = newNode;
  }
  else
  {
    printf("Falha ao alocar memória.\n");
  }
  return top;
}

void printList(Node *top)
{
  if (top == NULL)
  {
    printf("A lista está vazia.\n");
  }
  while (top != NULL)
  {
    printf("Nome: %s\t", top->student.name);
    printf("Idade: %d\t", top->student.age);
    printf("Turma: %d\n", top->student.class_number);
    top = top->next;
  }
}

Node *pop(Node *top)
{
  if (top == NULL)
  {
    printf("A lista está vazia.\n");
    return top;
  }

  Node *temp = top;
  top = top->next;
  free(temp);

  return top;
}

void freeList(Node *top)
{
  Node *temp;
  while (top != NULL)
  {
    temp = top;
    top = top->next;
    free(temp);
  }
}

int main()
{
  Node *top = NULL;
  int op;
  FILE *arquivo;
  arquivo = fopen("entrada.txt", "r");
  printf("%d", printf("ola"));
  do
  {
    printf("Menu\n");
    printf("0 - Sair\n");
    printf("1 - Criar Usuário\n");
    printf("2 - Mostrar Usuários\n");
    printf("3 - Remover\n");
    scanf(" %d", &op);

    switch (op)
    {
    case 1:
      while (!feof(arquivo))
      {

        top = push(top, createAlumn(arquivo));
      }

      break;
    case 2:
      printList(top);
      break;
    case 3:
      top = pop(top);
      break;

    default:
      break;
    }
  } while (op != 0);

  freeList(top);

  return 0;
}
