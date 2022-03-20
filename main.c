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


Lista * insere (Lista * inicio,char r[]){
int i = 0;
  Lista *novo;
  novo = (Lista *) malloc(sizeof(Lista));

  while(r[i]!=NULL){
  novo->resposta[i] = r[i];
  i++;
}
if(inicio == NULL){
  novo->prox = NULL;
  return novo;
}
else{
  Lista *pAux = inicio;
  while(pAux->prox != NULL){
  pAux = pAux->prox;
}  
  novo->prox = NULL;
  pAux->prox = novo;
  
  return inicio;
}}



Lista * reescreve(Lista * lista,int n,char resposta[]){
  Lista *pont = lista;

if(n==1){
  for(int i =0;i<sizeof(resposta);i++){
    pont->resposta[i] = resposta[i];
}}else{
  for(int i =0;i<n-1;i++){
    pont = pont->prox;
  }for(int i =0;i<sizeof(resposta);i++){
    pont->resposta[i] = resposta[i];
  }
  }
return lista;
}



void demonstra(Lista *l){
 Lista *pont = l;
  int i = 1;
  while(pont!=NULL){
    printf("%d - %s\n",i,pont->resposta);
    pont = pont->prox;
    i++;
  }
  
}


void arquiva(Lista *l,FILE *r){
  Lista *pont = l;
  r = fopen("Respostas.txt", "w");

  while(pont!=NULL){
  fwrite(&pont->resposta,50*sizeof(char),1,r);
  
  pont = pont->prox;
}fclose(r);
}


void LiberaLista(Lista *l){
  Lista *p = l;
  Lista *a;
  
while(p!=NULL){
  a = p->prox;
  free(p);
  p=a;
}}



void apresenta(FILE *lista){
  
  char p[50];
  lista = fopen("Respostas.txt", "rb");
 
  while(fread(&p,sizeof(p),1, lista)==1){
   printf("%s\n",p);
    }   
  fclose(lista);
 }
  

// Main do Projeto
int main(void) {
  
  FILE *arq;
  Lista *lista;
  char RecebeResposta[50];
  int excluivalor;
  int questiona = 1;
  
  char *perguntas[10] = {"Qual o seu nome?", "Quantos anos você tem?", "Qual a sua localização?", "Você costuma comprar produtos de forma online regularmente, às vezes ou nunca?", "Como você avalia o atendimento prestado pela nossa equipe durante a pandemia?","Os nossos produtos estão abaixo, acima, ou atendem às suas expectativas?","Entre aparelhos (notebook, celular) e acessórios (fones de ouvido, teclados, mouse) eletrônicos, o que mais você costuma comprar?", "O que motivou a compra deste produto?", "Você recomendaria a empresa para amigos e familiares?", "Você veio através de uma indicação (facebook, instagram)?"};

	printf("Ola, a empresa Start esta passando por melhorias e precisa da sua opiniao!\n");
	printf("Por favor, responda as seguintes perguntas com o maximo de sinseridade possivel.\n\n");

  lista = criar();
  
  for(int i = 0; i <= 9; i++){
    printf("\n%s\n", perguntas[i]);
    fgets(RecebeResposta,50,stdin);
    lista = insere(lista,RecebeResposta);
  }


printf("Deseja reescrever alguma das suas respostas?\n1 - reescrever 2 - finalizar \n\n");
scanf("%d",&questiona);

while(questiona==1){

demonstra(lista);
printf("Digite o valor que corresponde a resposta que deseja reescrever!\n");
scanf("%d",&excluivalor);
printf("Reescreva a sua resposta\n");
setbuf(stdin,NULL);
fgets(RecebeResposta,sizeof(RecebeResposta),stdin);
  
lista = reescreve(lista,excluivalor,RecebeResposta);

printf("1 - continuar\n2 - parar\n");
scanf("%d",&questiona);

}

  
  arquiva(lista,arq);
  LiberaLista(lista);
  apresenta(arq);


return 0;
}
