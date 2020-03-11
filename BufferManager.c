#include <stdio.h>
#include <stdlib.h>
// compilar com: gcc Main.c Forward.c Backward.c Central.c -o exe 
// executar: ./exe

//Constantes
#define buffersize 16

struct no
{
    int Data;
    struct no *ptr;
};

//---

void ShowList(struct no *p)
{
    printf("\nMostrando a lista:\n"); 
    if(p)
    {
        do
        {
            printf(" %d", p->Data);
            p=p->ptr;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}

//---
//retorna 1 se achar, 0 se nao
//posso modificar para retornar 'indice'
int BuscaList(struct no *p, int x)
{
	if(p)
    {
        do
        {
            if(p->Data==x)
				return 1;
			
            p=p->ptr;
        }
        while(p);
		return 0;
		
    }
    else
        printf("Lista vazia.");
}

//---

/*
struct no* InitListHeat()
{
	printf("Inicializando a lista heat...\n"); 
	struct no *head = NULL;
    struct no *tail = NULL;
	struct no *aux = NULL;
	int i;
	head = (struct no*) malloc(sizeof(struct no*));
	head->Data = 0;
	head->ptr = NULL;
	aux = head;
	for(i=1; i<(5*buffersize/8); i++)
	{	
		tail = (struct no*) malloc(sizeof(struct no*));
		tail->Data = 0;
		tail->ptr = NULL;
		aux->ptr = tail;
		aux = tail;
		tail= NULL;
	}
	return head;
}

//---

struct no* InitListOld()
{
	printf("Inicializando a lista old...\n"); 
	struct no *head = NULL;
    struct no *tail = NULL;
	struct no *aux = NULL;
	int i;
	head = (struct no*) malloc(sizeof(struct no*));
	head->Data = 0;
	head->ptr = NULL;
	aux = head;
	for(i=1; i<(3*buffersize/8); i++)
	{	
		tail = (struct no*) malloc(sizeof(struct no*));
		tail->Data = 0;
		tail->ptr = NULL;
		aux->ptr = tail;
		aux = tail;
		tail= NULL;
	}
	return head;
}
*/

//---

int main () {
	//---
	
	printf("Inicializando a lista heat...\n"); 
	
	struct no *headh = NULL;
    struct no *tailh = NULL;
	struct no *auxh = NULL;
	int i;
	headh = (struct no*) malloc(sizeof(struct no*));
	headh->Data = 0;
	headh->ptr = NULL;
	auxh = headh;
	for(i=1; i<(5*buffersize/8); i++)
	{	
		tailh = (struct no*) malloc(sizeof(struct no*));
		tailh->Data = 0;
		tailh->ptr = NULL;
		auxh->ptr = tailh;
		auxh = tailh;
		tailh= NULL;
	}
	tailh = auxh;
	
	//---
	
	printf("Inicializando a lista old...\n"); 
	struct no *heado = NULL;
    struct no *tailo = NULL;
	struct no *auxo = NULL;
	heado = (struct no*) malloc(sizeof(struct no*));
	heado->Data = 0;
	heado->ptr = NULL;
	auxo = heado;
	for(i=1; i<(3*buffersize/8); i++)
	{	
		tailo = (struct no*) malloc(sizeof(struct no*));
		tailo->Data = 0;
		tailo->ptr = NULL;
		auxo->ptr = tailo;
		auxo = tailo;
		tailo= NULL;
	}
	tailo = auxo;
	//----
	
	/*
	struct no *headh = NULL;
	struct no *heado = NULL;
	headh = InitListHeat();
	heado = InitListOld();
	*/
	
	printf("1: %d\n",BuscaList(heado,1));
	printf("0: %d\n",BuscaList(heado,0));
	
	ShowList(headh);	
	ShowList(heado);	
	return 0;
}