#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


int a, b;
int d[100010];

/*Prototipo das funcoes*/
void visor(int a);
int filaVazia(Fila *f);
void iniciaFila(Fila *f);
void removeElemento(Fila *f);
void insereElemento(Fila *f, int elemento);


int main(){

  int t;

  //Recebe o numero de casos de teste.
  scanf("%d", &t);

  //Loop que itera o numero de vezes quantos forem o numero de casos de teste. 
  while (t--){

    //funcao que inicializa todos os valores do vetor d com -1. 
    memset(d, -1, sizeof(d));

    //Recebe o numero inicial no visor e o numero que deve ser mostrado no visor depois de apertar os botoes.
    scanf("%d %d", &a, &b);

    //Passa o numero inicial para a funcao visor.
    visor(a);

    //o numero minimo de apertos de botao.
    printf("%d\n", d[b]);
  }

  return 0;

}


void visor(int a){

  //Aloca memoria para a estrutura fila e passa o endereco para variavel f.
  Fila *f = (Fila *) malloc(sizeof(Fila));

  iniciaFila(f);

  //Insere o numero inicial na fila.
  insereElemento(f, a);

  //O vetor na posicao correspondente ao numero inicial recebe o valor 0.
  d[a] = 0;

  //Loop que opera enquanto a fila nao estiver vazia.
  while (!filaVazia(f)){
    
    int v = f->inicio->valor;

    //Se o vetor na posicao correspondente ao numero que deve ser mostrado no visor depois de apertar os botoes possuir algum valor, encerra-se entao o loop.
    if (d[b] != -1)
      break;

    removeElemento(f);

    //As variaveis rev, que será usada para inverter o valor recebido, eh iniciada com 0 e a variavel aux, eh iniciada com o valor do inicio da fila.
    int rev = 0, aux = v;

    //Loop que faz a inversao do valor.
    while (aux){

      //Multiplica o valor da variavel por 10;
      rev = rev*10;
      //A variavel rev recebe seu valor somado ao resto da divisao da variavel aux por 10.
      rev = rev + aux % 10;
      //A variavel aux recebe o resultado da divisao do seu valor por 10.
      aux  = aux/10;
    }

    //Se o vetor na posicao correspondente a variavel que recebeu a inversao nao possui valor, 
    //o vetor, nessa posicao, recebe o valor do vetor na posicao v, que recebeu o inicio da fila, incrementada de uma unidade. 
    //Em seguida, eh inserido o valor invertido na fila.
    if (d[rev] == -1){
      d[rev] = d[v] + 1;
      insereElemento(f, rev);
    }

     //Se o vetor na posicao seguinte a v, que recebeu o inicio da fila, nao possui valor, 
    //o vetor, nessa posicao, recebe o valor do vetor na posicao v, incrementada de uma unidade. 
    //Em seguida, eh inserido na fila o valor de v, incrementado de uma unidade. 
    if (d[v + 1] == -1){
      d[v + 1] = d[v] + 1;
      insereElemento(f, v + 1);
    }
    
  }

}


void iniciaFila(Fila *f){
  f->inicio = NULL;
  f->fim = NULL;
}


void insereElemento(Fila *f, int elemento){

  //Novo noh eh alocado na memoria. 
  No *novo = (No *) malloc(sizeof(No));

  //O elemento eh inserido na variavel valor da estrutura novo. 
  novo->valor = elemento;

  //O proximo elemento do elemento recebido recebe NULL, indicando o fim da fila.
  novo->proximo = NULL;

  //Testar se a fila estava vazia. Se sim, atualizar o campo inicio com o novo no.
  //Se nao, o elemento novo se torna o proximo do elemento no fim da fila antes do novo elemento ser inserido.
  if (f->inicio == NULL) f->inicio = novo;

  else f->fim->proximo = novo;

  //Como a insercao na fila eh feita no fim, o campo fim aponta agora para o novo elemento.
  f->fim = novo;

}


void removeElemento(Fila *f){

  //Aloca memoria para a estrutura apagar do tipo no que recebe o no inicio.
  No *apagar = f->inicio;
  
  //O campo inicio eh atualizado com o proximo
  f->inicio = f->inicio->proximo;

  //EH liberado o espaco de memoria que havia o inicio.
  free(apagar);

  //Testa se a fila ficou vazia, se sim, o campo fim aponta para null.
  if(f->inicio == NULL) f->fim = NULL;
 
}


int filaVazia(Fila *f){

  //Se o inicio for NULL, indica que a fila estah vazia, entao retorna um valor verdadeiro. Senao retorna um valor falso.
  if(f->inicio == NULL)
    return 1;
  else
    return 0;
}
