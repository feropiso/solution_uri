#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
void insereElemento(Pilha *p, int elemento);
void removeElemento(Pilha *p);
void iniciaPilha(Pilha *p);
int pilhaVazia(Pilha *p);


int main(void) {

  int i, n = 3, k = 1, c, s, erro, max = 0;
  
//Aloca memoria para a estrutura pilha e passa o endereco para variavel p.
  Pilha *estacionamento = (Pilha *) malloc(sizeof(Pilha));

//Loop que opera enquanto o numero de motoristas e o numero de carros forem diferentes de 0.
  while(n != 0 && k != 0){

//Recebe o numero de motoristas e o numero de carros, respectivamente.
    scanf("%d %d", &n, &k);

//Se o numero de motoristas e o numero de carros forem 0, encerra o loop.
    if(n == 0 && k == 0)
      break;
    
    int entrada[100000] = {0};
    int saida[100000] = {0};

    iniciaPilha(estacionamento);

    erro = 0;

//Loop que opera o numero de vezes igual a quantidade de motoristas.
    for(i = 1; i <= n; i++){

//Recebe o horaria de entrada e saida, respectivamente, de cada motorista.
      scanf("%d %d", &c, &s);

//Verifica o maior horaria de saida e o passa para a variavel max.
      if(s >= max)
        max = s;

//O vetor entrada na posicao de valor c recebe o valor c, enquanto que o vetor saida na posicao de valor s tambehm recebe o valor c.      
      entrada[c] = c;
      saida[s] = c;
    }

//Loop que opera o numero de vezes igual ao maior horaria de saida recebido.
    for(i = 1; i <= max; i++){

      if(saida[i] != 0) {

//Se a pilha nao estiver vazia e o valor do topo eh igual ao valor do vetor saida na posicao i, eh removido o elemento do topo da pilha.
        if(!pilhaVazia(estacionamento) && estacionamento->topo->valor == saida[i])
          removeElemento(estacionamento);
   //Se nao, a variavel auxiliar erro, que indicará se eh possivel que todos os motoristas usem o estacionamento ou nao, 
        //recebe um valor verdadeiro e o loop eh encerrado.                
        else {
          erro = 1;
          break;
        }
      }


      if(entrada[i] != 0){

//Se o tamanho da pilha for menor que o numero de carros, o valor do vetor entrada na posicao i eh inserido na pilha.
        if(estacionamento->tam < k)
          insereElemento(estacionamento, entrada[i]);

//Se nao, a variavel auxiliar erro recebe um valor verdadeiro e o loop eh encerrado.
        else {
          erro = 1;
          break;
        }    
      }
    }

//Se a variavel auxiliar erro recebeu um valor verdadeiro indica que nao foi possivel que todos os motoristas usem o estacionamento. 
    //EH impresso Nao. Caso contrário, eh mostrado Sim.
    if(erro)
      printf("Nao\n");

    else
      printf("Sim\n");    
  }

  return 0;
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


void iniciaPilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0; 
}


int pilhaVazia(Pilha *p){

  //Se o topo for NULL, indica que a pilha estah vazia, entao retorna um valor verdadeiro. Senao retorna um valor falso.
  if(p->topo == NULL)
    return 1;
  else
    return 0;
}
