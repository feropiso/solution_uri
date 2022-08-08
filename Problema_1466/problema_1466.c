#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 1000

//Cria a estrutura No da arvore com ponteiros para subarvore esquerda e direita.
struct No { 
  int valor;
  struct No *esquerda, *direita;
};
typedef struct No Arvore;

/*Prototipo das funcoes*/
Arvore * encontraPai(Arvore *r, int v);


int main(void) {
  
  Arvore *raiz, *pai, *aux, *vetorNo[TAM];

  int numNos, numCasos, i, j, valorNo, contA, contB;

  //Recebe a quantidade de casos
  scanf("%d", &numCasos);

  //Loop que itera pelos casos
  for(i = 1; i <= numCasos; i++){

    //Loop que inicializa o vetor de No com valores NULL
    for(j=0; j < 1000; j++)
      vetorNo[j] = NULL;
    
      raiz = NULL;
      
      //Recebe a quantidade de nos da arvore.
      scanf("%d", &numNos);

      //Loop que itera pela quantidade de nos e cria a arvore correspondente.
      for(j = 0; j < numNos; j++) {

        //Recebe o valor para ocupar um no da arvore.
        scanf("%d", &valorNo);
        
        //Aloca memoria para a estrutura do tipo arvore.
        aux = (Arvore *) malloc(sizeof(Arvore));

        //Inicia o no com o valor recebido e os ponteiros das subarvores da esquerda e direita recebem Null.
        aux->valor = valorNo;
        aux->esquerda = NULL;
        aux->direita = NULL;

        //Procura o valor raiz desse no.
        pai = encontraPai(raiz, valorNo);

        //Se o valor nao possui uma raiz, ele se torna a raiz.
        if(pai == NULL)
          raiz = aux;

        //Se possuir raiz e se for menor que ela, esse valor ocupa o no da esquerda, se nao o da direita. 
        else if (pai->valor != valorNo){
          if (valorNo < pai->valor)
            pai->esquerda = aux;
          else
            pai->direita = aux;
        }
      }

    printf("Case %d:\n", i);
    
    //O no raiz eh passado para a variavel aux e o primeiro valor do vetor recebe essa variavel. 
    aux = raiz;
    vetorNo[0] = aux;

    //As variaveis auxiliares contA e contB sao inicializadas com 1.
    contA = 1;
    contB  = 1;
    

    //Loop que imprime os valores por nível.
    while(aux != NULL){
      printf("%d", aux->valor);

      //Se o no recebido possui valores a esquerda, o vetor na posicao contA recebe esse no e a variavel contA eh incrementada.
      if(aux->esquerda != NULL){
        vetorNo[contA] = aux->esquerda;
        contA++;
      }

      //Se o no recebido possui valores a direita, o vetor na posicao contA (já incrementada antes) recebe esse no e a variavel contA eh incrementada novamente.
      if(aux->direita != NULL){
       vetorNo[contA] = aux->direita;
        contA++;
      }
      
      //Se o vetor na posicao contB possui valor, entao imprime um espaco em branco. 
      if(vetorNo[contB] != NULL)
        printf(" ");

      //O no aux recebe o no armazenado na posicao contB, que pode tanto ser o no da subarvore da esquerda ou da direita e incrementa a variavel contB.  
      aux = vetorNo[contB];
      contB++;
    }

    printf("\n\n");
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
