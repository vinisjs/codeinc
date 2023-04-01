#include <stdio.h>

void cad();

int main()
{
	printf("Hello World \n");
	cad();
}

void cad () {
	int i;
	int u = 0;
	int value[u];
	
	for(i = 0 ; i < 5 ; i++)
	{
		printf("Insira os 5 valores inteiros: ");
		scanf("%d", &value[i]);
	}	
}

int ret( int *value){
	int i;
	printf("");
	for(i = 0 ; i < 5 ; i++)
	{
		printf("Insira os 5 valores inteiros: ");
		scanf("%d", &value[i]);
	}
}
