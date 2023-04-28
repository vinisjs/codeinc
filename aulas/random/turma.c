/*
  crie um programa com um menu que seja possivel
  cadastrar ate 10 turmas e listar as turmas do curso
  cada turma tem um numero, turno, semestre
  e ate 20 alunos cada aluno tem numero de matricula
  nome e idade fazer com funçoes
*/

#include <stdio.h>

typedef struct y
{
  int matricula;
  char nome[25];
  int idade;
} aluno;

typedef struct x
{
  int numero;
  char turno[15];
  int semestre;
  int numeroAlunos;
  aluno al[20];
} turma;

void menu();
void cadastrar(turma *t);
void listarTurma(turma t[10], int quantidade);
void cadastrarAlunos(aluno al[20], int numeroAlunos);
void listarAlunos(aluno al[20], int numeroAlunos);
int buscaTurma(turma t[10], int quantidade, int numeroTurma);

int main(int argc, char const *argv[])
{
  int op, quantidade = 0, numeroTurma, i;
  turma t[10];
  do
  {
    menu();
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      if (quantidade < 10)
      {
        cadastrar(&(t[quantidade]));
        t[quantidade].numeroAlunos = 0;
        quantidade++;
      }
      else
      {
        printf("Limite maximo de 10 turmas;\n");
      }

      break;

    case 2:
      listarTurma(t, quantidade);
      break;
    case 3:
      printf("Entre com o numero da turma: ");
      scanf("%d", &numeroTurma);
      i = buscaTurma(t, quantidade, numeroTurma);
      if (i >= 0)
      {
        listarAlunos(t[i].al, t[i].numeroAlunos);
      }
      else
      {
        printf("Turma nao encontrada\n");
      }
      break;
    case 4:

      printf("Entre com o numero da turma: ");
      scanf("%d", &numeroTurma);
      i = buscaTurma(t, quantidade, numeroTurma);
      if (i >= 0)
      {
        cadastrarAlunos(t[i].al, t[i].numeroAlunos);
        t[i].numeroAlunos++;
      }
      else
      {
        printf("Turma nao encontrada\n");
      }
      break;
    }

  } while (op != 0);

  return 0;
}

int buscaTurma(turma t[10], int quantidade, int numeroTurma)
{
  int i;
  for (i = 0; i < quantidade; ++i)
  {
    if (t[i].numero == numeroTurma)
    {
      return i;
    }
  }
  return -1;
}

void listarAlunos(aluno al[20], int numeroAlunos)
{
  int i;
  for (i = 0; i < numeroAlunos; ++i)
  {
    printf("---------------\n");
    printf("Matricula: %d\n", al[i].matricula);
    printf("Nome: %s\n", al[i].nome);
    printf("Idade: %d\n", al[i].idade);
  }
}

void cadastrarAlunos(aluno al[20], int numeroAlunos)
{

  printf("Matricula: ");
  scanf("%d", &al[numeroAlunos].matricula);
  printf("Nome: ");
  scanf("%s", al[numeroAlunos].nome);
  printf("Idade: ");
  scanf("%d", &al[numeroAlunos].idade);
}

void listarTurma(turma t[10], int quantidade)
{
  int i;
  for (i = 0; i < quantidade; ++i)
  {
    printf("\n------------------------\n");
    printf("Numero: %d\n", t[i].numero);
    printf("Turno: %s\n", t[i].turno);
    printf("Semestre: %d\n\n", t[i].semestre);
  }
}

void menu()
{
  printf("\n\n-----------Menu----------\n");
  printf("1) Cadastrar\n");
  printf("2) Listar\n");
  printf("3) Listar alunos\n");
  printf("4) Cadastrar alunos\n");
  printf("0) Sair\n");
}

void cadastrar(turma *t)
{
  printf("Entre com o numero:\n");
  scanf("%d", &(*t).numero);
  printf("Entre com o turno:\n");
  scanf("%s", (*t).turno);
  printf("Entre com o semestre: \n");
  scanf("%d", &(*t).semestre);
}