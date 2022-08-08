#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Cria a estrutura No da arvore com ponteiros para subarvore esquerda e direita.
struct No { 
  int valor;
  struct No *esquerda, *direita;
};
typedef struct No Arvore;

int tipo;

/*Prototipo das funcoes*/
Arvore * encontraPai(Arvore *r, int v);
int imprimeArvore(Arvore *r);


int main(){

  Arvore *raiz, *pai, *auxiliar;
  int tam, numCasos, i, j, no;
  raiz = NULL;
  
  //Recebe o numero de casos
  scanf("%d", &numCasos);

  //Loop que itera pelo numero de casos.
  for(i = 1; i <= numCasos; i++){

    raiz = NULL;

    //recebe a quantidade de elementos da arvore.
    scanf("%d", &tam);

    //Loop que preenche a arvore.
    for(j = 0; j < tam; j++){
      
      //Recebe o valor para ocupar um no da arvore.
      scanf("%d", &no);

      //Aloca memoria para a estrutura do tipo arvore.
      auxiliar = (Arvore *) malloc(sizeof(Arvore));

      //Inicia o no com o valor recebido e os ponteiros das subarvores da esquerda e direita recebem Null.
      auxiliar->valor = no;
      auxiliar->esquerda = NULL;
      auxiliar->direita = NULL;

      //Procurar o valor raiz desse no.
      pai = encontraPai(raiz, no);

      //Se o valor nao possui uma raiz, ele se torna a raiz.
      if(pai == NULL)
        raiz = auxiliar;
      //Se possuir raiz e se for menor que ela, esse valor ocupa o no da esquerda, se nao o da direita. 
      else
        if(no <= pai->valor)
          pai->esquerda = auxiliar;
        else
          pai->direita = auxiliar;
    }

    //Imprime a arvore nos 3 diferentes casos: prefixo, infixo e posfixo.
    printf("Case %d:", i);

    printf("\nPre.:");
    tipo = 1;
    imprimeArvore(raiz);

    printf("\nIn..:");
    tipo = 2;
    imprimeArvore(raiz);

    printf("\nPost:");
    tipo = 3;
    imprimeArvore(raiz);

    printf("\n\n");

  }

  return 0;
}


int imprimeArvore(Arvore *r){
  
  //Se a arvore nao estiver vazia, imprime nos 3 casos. 
  if(r != NULL) {

    //Imprime na posicao prefixa: começando da raiz, seguido para a subarvore da esquerda e termina na subarvore da direita.
    if(tipo == 1){
      printf(" %d", r->valor);
      imprimeArvore(r->esquerda);
      imprimeArvore(r->direita);
    }

    //Imprime na posicao infixa: começando subarvore da esquerda, seguido para a raiz e termina na subarvore da direita.
    if(tipo == 2){
      imprimeArvore(r->esquerda);
      printf(" %d", r->valor);
      imprimeArvore(r->direita);
    }

    //Imprime na posicao posfixa: começando subarvore da esquerda, seguido para a subarvore da direita e termina na raiz.
    if(tipo == 3){
      imprimeArvore(r->esquerda);
      imprimeArvore(r->direita);
      printf(" %d", r->valor);
    }
  }

  return 0;
}


Arvore * encontraPai(Arvore *r, int v){ 
  
  
  if(r == NULL)
  //Arvore estah vazia.
    return NULL;
  else
  //Se o valor recebido for menor que a raiz, esse novo valor deve ficar a esquerda de r e eh retornado o valor da raiz. 
    if(v <= r->valor)   
      if(r->esquerda == NULL)
        return r;

      //Se um valor existir a esquerda, chama-se a funcao novamente por recursao, passando esse valor como parametro. 

      else
        return encontraPai(r->esquerda, v);

  //Se o valor recebido for maior que a raiz, esse novo valor deve ficar a direita de r.
    else
    //O novo valor deve ficar a direita de r e eh retornado o valor da raiz. 
      if(r->direita == NULL)
        return r;
       //Se um valor existir a direita, chama-se a funcao novamente por recursao, passando esse valor como parametro.   
      else
        return encontraPai(r->direita, v);
}
