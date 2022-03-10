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

Lista * insere (Lista * inicio,char r[],int size){

 Lista *novo;
 novo = (Lista *) malloc(sizeof(Lista));
 for(int i = 0;i<size;i++){
  novo->resposta[i] = r[i];
}
 if(inicio == NULL){
   novo->prox = NULL;
   return novo;
 }else{
   Lista *pAux = inicio;
   
   while(pAux->prox != NULL){
     pAux = pAux->prox;
   }  
    novo->prox = NULL;
    pAux->prox = novo;
 
    return inicio;
   }  
}

void apresentar(Lista * lista){
  Lista * p;
  p = lista;
  do{
    printf("Valor: %s\n",p->resposta);
    p = p->prox;
  }while(p!=NULL); 
}
// Main do Projeto

int main(void) {

  char *perguntas[5] = {"Qual o seu nome?", "Você conhece os protudos da Empresa?", "Como você avalia o atendimento prestado pela nossa equipe durante a compra de alguns dos produtos?", "Os nossos produtos estão abaixo, acima, ou atende às suas expectativas?","Em uma escala de 0 a 10, o quanto você nos recomendaria para um amigo ou familiar?"};

  Lista *lista;
  char RecebeResposta[50];

	printf("Ola, a empresa Start esta passando por melhorias e precisa da sua opiniao!\n");
	printf("Por favor, responda as seguintes perguntas com o maximo de sinseridade possivel.\n");

  lista = criar();
  
  for(int i = 0; i <= 4; i++){
    printf("%s\n", perguntas[i]);
    fgets(RecebeResposta,50,stdin);
    lista = insere(lista,RecebeResposta,50);
  }
 
 apresentar(lista);


return 0;
}
