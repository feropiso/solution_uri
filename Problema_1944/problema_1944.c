#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Cria no do tipo caractere.
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
void preparaSorteio (Pilha *p);
void insereElemento(Pilha *p, char elemento);
void removeElemento(Pilha *p);
int pilhaVazia(Pilha *p);


int main(void) {

  int numCasos;

  int vencedores = 0;

  char a, b, c, d;
  char A, B, C, D;

  //recebe o numero de casos de teste.  
  scanf("%d", &numCasos);

  //Aloca memoria para a estrutura pilha e passa o endereco para variavel p.
  Pilha *p = (Pilha *) malloc(sizeof(Pilha));

  //Passa como parametro a variavel p para a funcao de inicializacao.
  iniciaPilha(p);
  
  //Loop que opera no numero de vezes que correspondente ao numero de casos informado, ate o valor 0, que eh um valor falso, encerrando o loop.
  while(numCasos--){

    //Verifica se a pilha estah vazia, se estiver, chama a funcao que preenche os valores iniciais.
    if(pilhaVazia(p))
      preparaSorteio(p);
    
    //recebe a combinacao das 4 letras que o visitante deseja inserir no painel.  
    scanf(" %c %c %c %c", &a, &b, &c, &d);
   
    //Passa o valor do topo da pilha para uma variavel auxiliar e em seguida eh removido esse valor da pilha. Esse processo eh repetido para outras 3 variaveis.
    D = p->topo->valor;  
    removeElemento(p);
    
    C = p->topo->valor;  
    removeElemento(p);

    B = p->topo->valor;  
    removeElemento(p);

    A = p->topo->valor;  
    removeElemento(p);

    //Compara cada letra recebida com o inverso das que estavam armazenadas na pilha, se forem iguais, a variavel vencedor eh incrementada em mais 1.
    if(a==D && b==C && c==B && d==A)
      vencedores++;

    //Se nao houve vencedor, os valores retirados da pilha retornam na ordem abaixo, seguido das letras inseridas pelo participante.        
    else{

      insereElemento(p, A);
      insereElemento(p, B);
      insereElemento(p, C);
      insereElemento(p, D);

      insereElemento(p, a);
      insereElemento(p, b);
      insereElemento(p, c);
      insereElemento(p, d);       
             
    }
  }
  
  //Imprime o numero de vencedores.
  printf("%d\n", vencedores);
  return 0;
}


void iniciaPilha(Pilha *p){
  p->topo = NULL;
  p->tam = 0; 
}

//Funcao que insere os valores iniciais FACE.
void preparaSorteio(Pilha *p){
  
  insereElemento(p, 'F');
  insereElemento(p, 'A');
  insereElemento(p, 'C');
  insereElemento(p, 'E');
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

int pilhaVazia(Pilha *p){

  //Se o topo for NULL, indica que a pilha estah vazia, entao retorna um valor verdadeiro. Senao retorna um valor falso.
  if(p->topo == NULL)
    return 1;
  else
    return 0;
}
