#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista encadeada de respostas

typedef struct{

char resposta[30];
struct Lista *prox;

} Lista;

Lista * criar(){
return NULL;
}

Lista * insere (Lista *l, char v){
Lista *novo;
  
novo = (Lista *) malloc(sizeof(Lista));
novo->resposta[30] = v;
novo->prox = (struct Lista *) l;
return novo;
}

// Main do Projeto 

int main(void) {
	char *perguntas[2] = {"pergunta 1", "pergunta 2"};
  Lista *lista;
  char valor[30];
	
	printf("Ola, a empresa Start esta passando por melhorias e precisa da sua opiniao!\n");
	printf("Por favor, responda as seguintes perguntas com o maximo de sinseridade possivel.\n");

  lista = criar();

  for(int i = 0; i <= 2; i++){
    printf("%s\n", perguntas[i]);
    scanf("%s",&valor[30]);
    lista = insere(lista,*valor);
  }

  
  return 0;
}