#include <stdio.h>
#include <stdlib.h>
/*
	O sistema deve permitir:
	[ ] - cadastrar setores do campus,
	[ ] - onde cada setor ter� um nome,
	[ ] - tamanho (altura e largura),
	[ ] - quantidade de �rvores j� plantadas,
	[ ] - quantidade de constru��es nesse setor
	[ ] - e a lista de �rvores plantadas.

	[ ] - Para cada �rvore, o sistema deve ser capaz de armazenar: a esp�cie,
	[ ] - o porte,
	[ ] - o ano de plantio e
	[ ] - o nome de quem a plantou.

	[ ] - Deve ser poss�vel cadastrar at� 10 setores,
	[ ] - e cada setor pode ter at� 10 �rvores.
	O programa n�o deve ter vari�veis globais.

	Deve haver um:
	[ ] - menu para cadastrar setores e
	[ ] - �rvores em um setor,
	[ ] - e deve ser poss�vel listar os setores
	[ ] - e as �rvores em cada setor.
*/

typedef struct
{
	char name[50];
	float width;
	float heigth;
	int arv_qnt;
	int const_qnt;
} Setores;

typedef struct
{
	char especie[250];
	int age;
	int name[250];
} Arvores;

// funções
void menu();
void cadastro(Setores *setores);

int main()
{
	system("cls");
	menu();
}

void cadastro(Setores *x)
{

	int u = 0;
	int op;

	do
	{
		printf("Digite o Nome do Setor: ");
		scanf(" %[^\n]", *x[u].name);

		printf("Nome do Setor: %s", *x[u].name);

		u++;
		printf("Finalizar: \n0 - Sim | 1 - Não ");
		scanf(" %d", &op);

	} while (op == 0);
}

void menu()
{
	int op;
	Setores x[3];

	printf("############### MENU ############### \n");
	printf("# 1 - CADASTRO DE SETORES \n");
	printf("# 2 - CADASTRO DE ARVORE \n");
	printf("# 3 - RELATORIO \n");
	printf("# 0 - SAIR \n");
	scanf(" %d", &op);

	switch (op)
	{
	case 1:
		cadastro(&x);
		break;
	case 2:
		/* code */
		break;
	case 3:
		/* code */
		break;
	case 0:
		break;
	default:
		printf("Opcao Invalida \n");
		menu();
		break;
	}
}
