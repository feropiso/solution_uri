#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Cria no do tipo inteiro.
typedef struct no{
  int valor;
  struct no *proximo;
}No;

//Cria estrutura do tipo pilha.
typedef struct {
  No *topo;
  int tam;
}Pilha;

/*Prototipo das funcoes*/
void iniciaPilha(Pilha *p);
void insereElemento(Pilha *p, int elemento);
void removeElemento(Pilha *p);




int main(void) {

  int entrada, numVagoes, i, naoEhPossivel, auxiliar, zero; 
  
  //Aloca memoria para a estrutura pilha e passa o endereco para variavel p.
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  
  //Loop que opera enquanto for inserida a quantidade de vagoes e se essa quantidade nao for 0.
  while(scanf("%d", &numVagoes) && numVagoes){

//Loop infinito que eh encerrado com a variavel entrada recebendo 0.
    while(1){     
      
      iniciaPilha(p);

//Loop que opera o numero de vezes quanto forem a quantidade de vagoes. No inicio do loop as variaveis auxiliar, que serve para constatar se as entradas sao feitas na ordem, naoEhPossivel, que serve para indicar a possibilidade de organizar os vagoes da forma solicitada ou nao, e zero, que indica as entradas de encerramento, sao inicializadas.
      for(i = 0, auxiliar = 1, naoEhPossivel = 0, zero = 0; i < numVagoes && !naoEhPossivel && !zero; i++){

//Recebe a numeracao de cada vagão.
        scanf("%d", &entrada);

//Verifica se a entrada foi o valor 0. Se for, indica o fim de uma sequencia e o loop eh encerrado.
        if(!entrada){
          zero = 1;
          break;
        }

        while(1){

//Se o valor da entrada for igual a variavel auxiliar, a variavel auxiliar eh incrementada em uma unidade e o loop eh encerrado.
          if(entrada == auxiliar){
            auxiliar++;
            break;
          }

          else
//Se o valor da entrada for maior do que a variavel auxiliar, a variavel auxiliar eh inserida na pilha e em seguida seu valor eh incrementado em uma unidade.

            if(entrada > auxiliar){
              insereElemento(p, auxiliar);            
              auxiliar++;
            }

            else{

//Se o valor da entrada for igual ao do topo da pilha, eh removido o valor do topo da pilha.
              if(p->topo->valor == entrada)
                removeElemento(p);

//A variavel naoEhPossivel recebe um valor verdadeiro indicando que nao foi possivel organizar os vagoes. 
              //Eh recebida entao para a proxima sequencia e se encerra o loop.
              else{
                naoEhPossivel = 1;

                for(; i < numVagoes-1; i++)
                  scanf("%d", &entrada);
              }  
             
              break;
            }
          }       
      }
//Verifica se a variavel zero contem um valor verdadeiro. Se tiver, o loop eh encerrado. 
      //Se nao, imprime a resposta Yes, se a variavel naoEhPossivel recebeu um valor falso (0), No, se recebeu um valor verdadeiro.
      if(!zero)
        if(!naoEhPossivel)
          printf("Yes\n");
        else
          printf("No\n");
      else
        break;        
    }

    printf("\n");
  }

  return 0;
}




void iniciaPilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0; 
}


void insereElemento(Pilha *p, int elemento){

   //Aloca memoria para um novo elemento e passa o endereco para a variavel novo.
  No *novo = (No *) malloc(sizeof(No));

  //O elemento a ser inserido eh guardado na variavel valor.
  novo->valor = elemento;

  //O proximo valor da pilha eh atualizado com o valor do topo.
  novo->proximo = p->topo;

  //O elemento inserido agora eh o novo topo da pilha.
  p->topo = novo;

  //Incrementa o valor do tamanho da pilha em mais um elemento.
  p->tam++;
}



void removeElemento(Pilha *p){

  //Variavel auxiliar que recebe o valor do topo.
  No *apagar = p->topo;

  //O topo eh atualizado com o valor seguinte.
  p->topo = p->topo->proximo;

  //Libera-se o espaco na memoria que continha o antigo valor do topo.
  free(apagar);

  //Decrementa o tamanho da pilha em menos um elemento.
  p->tam--;
 
}
