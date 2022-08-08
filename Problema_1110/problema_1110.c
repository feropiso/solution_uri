#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>


//Cria estrutura do tipo no.
typedef struct no{
  int valor;
  struct no *proximo;
}No;

//Cria estrutura do tipo fila.
typedef struct {
  No *inicio;
  No *fim;  
}Fila;

/*Prototipo das funcoes*/
void iniciaFila(Fila *f);
void insereElemento(Fila *f, int elemento);
void removeElemento(Fila *f);
int tamanhoFila(Fila *f);


int main(void) {

  int n, i;

  //Aloca memoria para a estrutura fila e passa o endereco para variavel f.
  Fila *f = (Fila *) malloc(sizeof(Fila));

  //Loop que recebe valores enquanto eles forem inseridos ou forem diferentes de 0.
  while(scanf("%d", &n) && n != 0){
    
    iniciaFila(f);

    //Insere uma sequencia de numeros inteiros na fila, de 1 ateh o valor informado.
    for (i = 1; i <= n; ++i)
      insereElemento(f, i);
      
    printf("Discarded cards:");

    //loop que processa se o tamanho da fila for maior que 1.
    while(tamanhoFila(f) > 1) {

      //Mostra os valores na fila.
      printf(" %d", f->inicio->valor);

      //Imprime uma vírgula após cada valor.
      if(tamanhoFila(f) != 2)
        printf(",");

      //Remove o valor do inicio da fila.            
      removeElemento(f);

      //Insere o elemento que estah no inicio no fim da fila.
      insereElemento(f, f->inicio->valor);

      //Remove o novo elemento do inicio.     
      removeElemento(f);
    }

    //Imprime os valores que restaram da fila.
    printf("\nRemaining card: %d\n", f->inicio->valor);

  }

  return 0;
}

void iniciaFila(Fila *f){
  f->inicio = NULL;
  f->fim = NULL;
}


void insereElemento(Fila *f, int elemento){

  //Novo no eh alocado na memoria. 
  No *novo = (No *) malloc(sizeof(No));

  //O elemento eh inserido na variavel valor da estrutura novo. 
  novo->valor = elemento;

  //O proximo elemento do elemento recebido recebe NULL, indicando o fim da fila.
  novo->proximo = NULL;

  //Testar se a fila estava vazia. Se sim, atualizar o campo inicio com o novo no. Se nao, o elemento novo se torna o proximo do elemento no fim da fila antes do novo elemento ser inserido.
  if (f->inicio == NULL) f->inicio = novo;

  else f->fim->proximo = novo;

  //Como a insercao na fila eh feita no fim, o campo fim aponta agora para o novo elemento.
  f->fim = novo;

}


void removeElemento(Fila *f){

  //Aloca memoria para a estrutura apagar do tipo no que recebe o noh inicio.
  No *apagar = f->inicio;
  
  //O campo inicio eh atualizado com o proximo
  f->inicio = f->inicio->proximo;

  //EH liberado o espaco de memoria que havia o inicio.
  free(apagar);

  //Testa se a fila ficou vazia, se sim, o campo fim aponta para null.
  if(f->inicio == NULL) f->fim = NULL;
 
}
int tamanhoFila(Fila *f){

  int tam = 0;

  //Aloca memoria para a estrutura end do tipo no que recebe o no inicio.
  No *end = f->inicio;

  //Loop que percorre a fila enquanto nao encontrar um valor NULL e incrementa a variavel tam.
  while (end != NULL){
    tam++;
    end = end->proximo;
  }

  //retorna a variavel tam correspondente a quantidade de elementos na fila.
  return tam;
}
