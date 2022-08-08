#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Vetor que corresponde ao grau de cada operador.
int grau[7] = {1,1,2,2,3,0,4};
//Vetor que armazena os operadores.
char operador[7] = {'+','-','*','/','^','(',')'}; 

//Cria no do tipo caracter.
typedef struct no{
  char valor;
  struct no *proximo;
}No;

//Cria estrutura do tipo pilha.
typedef struct {
  No *topo;
  int tam;
}Pilha;

/*Prototipo das funcoes*/
void iniciaPilha(Pilha *p);
void removeElemento(Pilha *p);
int EhOperador(char elemento);
int grauOperador(char elemento);
void insereElemento(Pilha *p, char elemento);


int main(void) {

  int i, n;
  char expressao[301];

  //Aloca memoria para a estrutura pilha e passa o endereco para variavel p.
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));
  
  //Recebe o numero de casos.
  scanf("%d", &n);

  //Loop que decrementa o numero de casos ate o valor 0 que corresponde a um valor falso.

  while(n--){

    //Inicializa a pilha.
    iniciaPilha(p);

    //Recebe a expressao.
    scanf("%s", expressao);

    //loop que itera por cada caracter da expressao recebida ateh o final da string.
    for( i = 0 ; expressao[i] != '\0'; i++){
      
      //Mostra o caracter da expressao recebida que nao seja um operador.
      if(!EhOperador(expressao[i]))

        printf("%c", expressao[i]);

      //Se for operador e a pilha estiver vazia, insere o valor na pilha.   
      else
        if(p->topo == NULL)
          insereElemento(p, expressao[i]);
                       
        else
          //Se possuir um fecha parentese na expressao.
          if(expressao[i] == ')'){

            //Loop que percorre, mostra e remove os elementos da pilha ate encontrar um abre parentese. 
            while(p->topo->valor != '('){
              printf("%c", p->topo->valor);
              removeElemento(p);
            }

            //Remove o parentese de fechamento.
            removeElemento(p);

            
          }else{

            //Loop que mostra os valores da pilha enquanto tiverem grau maior ou igual ao caracter recebido. Em seguida, os remove da pilha.
            while(grauOperador(p->topo->valor) >= 
            grauOperador(expressao[i])){
              
              //O loop eh interrompido se for passado um parentese.
              if(expressao[i] == '(')
                break;

              printf("%c", p->topo->valor);

              removeElemento(p);
              
              //EH interrompido se a pilha ficar vazia.
              if(p->topo == NULL)
                break;
            }

            //insere o elemento que nao estah entre parentese.
            insereElemento(p, expressao[i]);
          }
      } 

      //loop que itera pela pilha, se nao estiver vazia, e mostra os elementos remanescentes. Remove estes logo em seguida. 
      while(p->topo != NULL){ 

        printf("%c", p->topo->valor);
        removeElemento(p);
      } 

    printf("\n");
  }

  return 0;
}

//Funcao que retorna o grau do operador.
int grauOperador(char elemento){

  int i;

  for(i=0;;i++)
    if(operador[i] == elemento)
      return grau[i];

}


//Funcao que verifica se eh um operador.
int EhOperador(char elemento){

  int i;

  for(i=0; i < 7; i++)
    if(operador[i] == elemento)
      return 1;

  return 0; 
}


void iniciaPilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0; 
}


void insereElemento(Pilha *p, char elemento){

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
