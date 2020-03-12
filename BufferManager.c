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
	{
        printf("Lista vazia.");
		return 0;
	}
}

//---
//1: insercao concluida 0: não deu certo
//so funciona pq eu ja sei que a lista nao esta cheia
//não insere sempre no head, verificar isso
int InsertList(struct no *p,int x)
{
	int aux1;
	int aux2;
	if(p)
    {
        if(p->Data==-1)
		{
			p->Data=x;
			return 1;
		}
		else
		{
			aux1 = p->Data;
			p->Data=x;
			p=p->ptr;
			while(p)
			{
			aux2 = p->Data;
			p->Data = aux1;
			p=p->ptr;
			aux1 = aux2;
			}
		}
		return 1;
		
    }
    else 
	{
        printf("Lista vazia.");
		return 0;
	}
}

//---
//1: cheia, 0: não cheia
int ListIsNotFull(struct no *tail)
{
	if(tail->Data == -1)
		return 1;
	else
		return 0;
}

//---

int main () {
	//---
	
	printf("Inicializando a lista heat...\n"); 
	
	struct no *headh = NULL;
    	struct no *tailh = NULL;
	struct no *auxh = NULL;
	int i;
	headh = (struct no*) malloc(sizeof(struct no*));
	headh->Data = -1;
	headh->ptr = NULL;
	auxh = headh;
	for(i=1; i<(5*buffersize/8); i++)
	{	
		tailh = (struct no*) malloc(sizeof(struct no*));
		tailh->Data = -1;
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
	heado->Data = -1;
	heado->ptr = NULL;
	auxo = heado;
	for(i=1; i<(3*buffersize/8); i++)
	{	
		tailo = (struct no*) malloc(sizeof(struct no*));
		tailo->Data = -1;
		tailo->ptr = NULL;
		auxo->ptr = tailo;
		auxo = tailo;
		tailo= NULL;
	}
	tailo = auxo;
	
	//----
	//TESTES
	/*
	i=0;
	while(ListIsNotFull(tailo))
	{
		InsertList(heado,i);
		i++;
		ShowList(heado);
	}
	
	if(BuscaList(heado,5))
		printf("5: %d\n",BuscaList(heado,5));
	else
		printf("0: %d\n",BuscaList(heado,0));
	*/
	//-----------------
	//MANAGER LRU-MYsql
	
		/*O QUE EU TO FAZENDO:
		GERANDO ALEATORIOS DE 1 A 10;
		SE EU TIRO 1 (METAFORICAMENTE EU PRECISO DA PAGINA 1)
		TO ANOTANDO EM UM VETOR CONTADOR, QUANTIDADE QUE CADA NUMERO SAIU
		[duvida 1]TEORICAMENTE OS NUMEROS QUE MAIS SAIRAM EM SUA MAIORIA DEVEM TA EM HEAT
		*/
	// variavel aleatoria
	int a;
	//inicialianzndo contador
	int contador[101];
	for(i=0;i<101;i++)
	{
		contador[i]=0;
	}

	for(i=0;i<1000;i++)
	{
		a = rand() % 100;
		//printf("%d\n",a);
		contador[a] = contador[a]+1;
		if(BuscaList(heado,a))
		{	
			//[duvida 2]
			if (!(BuscaList(headh,a)))
			{
				if(ListIsNotFull(tailh))
					InsertList(headh,a);
				else
				{
					tailh->Data = -1;
					InsertList(headh,a);
				}
			}
		}
		else
			{
				if(ListIsNotFull(tailo))
					InsertList(heado,a);
				else 
				{
					tailo->Data = -1;
					InsertList(heado,a);
				}
			}
		
		/*
		ShowList(headh);	
		ShowList(heado);
		printf("\n");
		*/
	}
	
	//-----------------
	
	ShowList(headh);	
	ShowList(heado);	
	
	printf("\n[");
	for(i=0;i<101;i++)
	{
		printf(" %d=%d ",i,contador[i]);
	}
	printf("]\n");
	return 0;
}



/*
DUVIDAS

1 - Devo levar em conta o numero de vezes que foi requisitado?

2 - Se eu passo um valor pro heat, eu tiro ele do old?

*/
