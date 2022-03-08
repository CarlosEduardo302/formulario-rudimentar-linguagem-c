#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista encadeada de respostas

typedef struct{

char resposta[50];
struct Lista *prox;

} Lista;

Lista * criar(){
return NULL;
}

Lista * insere (Lista *lista, char valor){

Lista * novo = (Lista *) malloc(sizeof(Lista));
novo->resposta[50] = valor;
novo->prox = (struct Lista *) lista;
return novo;
}

// Main do Projeto 

void apresentar(Lista * lista){
  Lista * p;
  p=lista;
  while(p!=NULL){
    printf("Valor: %s\n",&p->resposta[50]);
    p = (Lista *) p->prox;
  }  
}

int main(void) {
	char *perguntas[5] = {"Qual o seu nome?", "Você conhece os protudos da Empresa?", "Como você avalia o atendimento prestado pela nossa equipe durante a compra de alguns dos produtos?", "Os nossos produtos estão abaixo, acima, ou atende às suas expectativas?","Em uma escala de 0 a 10, o quanto você nos recomendaria para um amigo ou familiar?"};
  Lista *lista;
  char valor[50];
	
	printf("Ola, a empresa Start esta passando por melhorias e precisa da sua opiniao!\n");
	printf("Por favor, responda as seguintes perguntas com o maximo de sinseridade possivel.\n");

  lista = criar();

  for(int i = 0; i <= 4; i++){
    printf("%s\n", perguntas[i]);
    scanf("%s",&valor[50]);
    lista = insere(lista,*valor);
  }

  apresentar(lista);
  return 0;
}
