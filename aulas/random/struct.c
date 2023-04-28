#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Struct
*/

typedef struct {
	char name[50];
	int age;
	char sex;
	
} Person;

int main()
{
	int i;
	int u = 3;
	Person User[u];
	
	for(i = 0; i < u ; ++i)
	{
		printf("Digite seu nome: ");
		scanf(" %[^\n]", &User[i].name);
		//getchar();
		
		printf("Digite sua idade: ");
		scanf(" %d", &User[i].age);
		// remove o erro do "enter" entrar em outro vetor
		//getchar();
		
		printf("Selecione o genero: [m] - masculino ou [f] - feminino: ");
		scanf(" %c", &User[i].sex);
		//getchar();
			
	}
	for (i = 0; i < u; ++i)
	{
		printf("\nID: %d\n", i);
		printf("Nome: %s\n", User[i].name);
		printf("Idade: %d\n", User[i].age);
		printf("Sexo: %c\n\n", User[i].sex);
	}

}
