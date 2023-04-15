#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
  char name[30];
  int qnt;
} Book;

typedef struct
{
  Book *books;
  int qnt;
  int date;
} Library;

typedef struct
{
  char name[30];
  int age;
  char email[100];
} Person;

void createUser(Person *US, Library *Biblioteca[], int *t);
void createLibrary(Library *Biblioteca[], int *t);
void menu(Person *US, Library *Biblioteca[], int *t);

void generateReport(Library *Biblioteca, int t);
void impress(Person *USC, Library *Biblioteca[], int *t);

int main()
{

  int t = 1;
  Person Usuario;
  Library *Biblioteca = malloc(t * sizeof(Library)); // aloca memória para o array

  if (Biblioteca == NULL)
  { // verifica se a alocação foi bem-sucedida
    printf("Erro na alocação de memória para Biblioteca\n");
    exit(1); // encerra o programa
  }

  system("cls");
  setlocale(LC_ALL, "Portuguese");
  printf("\nSISTEMA DE GERÊNCIAMENTO DE LEITURA\n\n");
  createUser(&Usuario, &Biblioteca, &t);

  free(Biblioteca);
}

void createUser(Person *US, Library *Biblioteca[], int *t)
{
  printf("### Criação de Usuário ###\n\n");

  printf("Digite seu nome: ");
  scanf(" %[^\n]s", (*US).name);

  printf("Digite sua idade: ");
  scanf(" %d", &(*US).age);

  printf("Digite seu e-mail: ");
  scanf(" %[^\n]s", (*US).email);

  printf("Sucesso\n\n");

  menu(US, Biblioteca, t);
}

void menu(Person *US, Library *Biblioteca[], int *t)
{
  int op;
  do
  {
    printf("## Menu ## \n\n ");
    printf("1 - Criar Registro\n ");
    printf("2 - Gerar Relatorio\n");
    printf("0 - Sair\n");
    scanf(" %d", &op);

    if (op == 1)
      createLibrary(&Biblioteca[0], t);
    if (op == 2)
      impress(US, Biblioteca, t);
    else
      printf("Invalid Option, try again\n");
  } while (op != 0);
}

void createLibrary(Library *Biblioteca[], int *t)
{
  int i, j, tm, tmb;

  printf("Cadastro Biblioteca\n\n");

  printf("Quantos dias de leitura: ");
  scanf(" %i", &tm);

  printf("\n#Quantos dias de leitura: %d\n", tm);

  printf("\ntempo: %d\n", tm);

  *t = tm;

  for (i = 0; i < tm; i++)
  {
    printf("Digite a data da leitura[%i]: ", i + 1);
    scanf(" %d", &(*Biblioteca)[i].date);

    printf("Digite a quantidade de livros: ");
    scanf(" %d", &(*Biblioteca)[i].qnt);

    tmb = (*Biblioteca)[i].qnt;
    (*Biblioteca)[i].books = malloc(tmb * sizeof(Book));

    for (j = 0; j < tmb; j++)
    {
      printf("Digite o nome do livro[%i]: ", j + 1);
      scanf(" %[^\n]s", (*Biblioteca)[i].books[j].name);
    }
  }
}
void impress(Person *USC, Library *Biblioteca[], int *t)
{
  FILE *file;
  int i, j;

  file = fopen("file.txt", "w");

  if (file == NULL)
    printf("Erro");

  fprintf(file, "Segue abaixo o relatório dos livros lidos:\n\n");
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo\n");
  }
  else
  {
    fprintf(file,
            "Olá %s,\nFoi verificado que você possui %d anos. Um link de ativação foi enviado para o seu email: %s.\n",
            USC->name,
            USC->age,
            USC->email);
  }
  for (i = 0; i < *t; i++)
  {
    fprintf(file, "Data da leitura: %d\n", Biblioteca[i]->date);
    fprintf(file, "Quantidade de livros: %d\n", Biblioteca[i]->qnt);

    for (j = 0; j < Biblioteca[i]->qnt; j++)
    {
      fprintf(file, "- %s\n", Biblioteca[i]->books[j].name);
    }

    fprintf(file, "\n");
  }

  fprintf(file, "Obrigado pela utilização do sistema.\n");

  fclose(file);
  printf("Relatório salvo com sucesso no arquivo 'file.txt'.\n");
  generateReport(Biblioteca, t);
}

void generateReport(Library *Biblioteca, int t)
{
  FILE *file;
  int i, j;

  file = fopen("relatorio.txt", "w");
  if (file == NULL)
  {
    printf("Erro ao abrir arquivo.\n");
    return;
  }

  fprintf(file, "RELATÓRIO DE LEITURA\n\n");
  for (i = 0; i < t; i++)
  {
    fprintf(file, "Data da leitura: %d\n", Biblioteca[i].date);
    fprintf(file, "Quantidade de livros lidos: %d\n", Biblioteca[i].qnt);
    for (j = 0; j < Biblioteca[i].qnt; j++)
    {
      fprintf(file, "Livro %d: %s\n", j + 1, Biblioteca[i].books[j].name);
    }
    fprintf(file, "\n");
  }

  fclose(file);
  printf("Relatório gerado com sucesso.\n");
}
