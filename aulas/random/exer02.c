#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main (void){
 int vet[SIZE], i;
 int *Endvet;
 Endvet = vet;
 
 printf("\tDigite %d elementos:\n",SIZE);
 
 for(i = 0; i < SIZE; i++){
  printf("%d: ",i+1);
    scanf("%d", &vet[i]);
 }
 
 printf("\n\tELEMENTOS:\n\n");
    
    for(i = 0; i < SIZE; i++){
      printf("%d  ",vet[i]);
  }
 printf("\n\nENDERECOS DO ARRAY:\n");
 
 for(i = 0; i < SIZE; i++){
     printf("%i : %i : %i\n",i+1, vet[i], Endvet++);
 } 
 
 printf("\nENDERECOS DO ARRAY PAR:\n");
 
 Endvet = vet;
 
 for(i = 0; i < SIZE; i++){
  
  if(vet[i] %2 == 0){
   printf("\nNumero %d eh par : Posicao = %d",vet[i], Endvet);
  }
  Endvet++;
}
}
