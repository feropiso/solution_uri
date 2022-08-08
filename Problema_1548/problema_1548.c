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
int comparaValores(const void *p1, const void *p2);


int main (){  
  
  int casos, alunos, i, j, nota, notasOrdenadas[1001], iguais;

  //Aloca memoria para a estrutura fila e passa o endereco para variavel f.
  Fila *f = (Fila *) malloc(sizeof(Fila));

  //Recebe a quantidade de casos.
  scanf("%d", &casos);
  
  while(casos > 0){

    //Passa como parametro a variavel f para a funcao de inicializacao.
    iniciaFila(f);

    //Recebe a quantidade de alunos.
    scanf("%d", &alunos); 
    
    //Loop que recebe a nota de cada aluno e insere na fila e no vetor. 
    for(i = 0; i < alunos; i++){
      scanf("%d ", &nota);
      insereElemento(f, nota);
      notasOrdenadas[i] = nota;
    }

    //funcao que faz ordenacao de vetores.
    qsort(notasOrdenadas, alunos, sizeof(int), comparaValores);
    
    //Loop que itera pelos alunos e compara as notas da fila com a do vetor ordenado e incrementa a variavel iguais que indica quantos nao precisam mudar de lugar.
    for( i = 0, iguais = 0; i < alunos; i++){

      if(f->inicio->valor == notasOrdenadas[i])
        iguais++;
      
      //Remove o elemento do inicio da fila.
      removeElemento(f);                
    }
    
    printf("%d\n", iguais);   

    casos--;
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

  //O elemento eh inserido na variavel valor da estrutura. 
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

//Funcao auxiliar que compara dois valores fornecidos e retorna -1 se o primeiro for maior que o segundo; 0 se forem iguais e 1 se o segundo valor for maior.
int comparaValores(const void *p1, const void *p2){
  
  int *i, *j;
  
  i = (int *)p1;
  j = (int *)p2;

  if(*i > *j)
    return -1;
  else
    if(*i == *j)
      return 0;
    else
      return 1;
}
