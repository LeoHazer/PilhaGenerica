#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define MAX 100

typedef struct item
{

    int chave;
    void *obj;

} Item;

struct pilha
{
    int topo;
    Item vet[MAX];
};


Pilha Inicializar(void)
{
    int i;
    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    p->topo = 0;

    for(i=0; i<MAX; i++)
    {
        p->vet[i].obj = NULL;
    }

    return p;

}

Pilha Destruir(Pilha p)
{
    int i;

    for(i=0; i<p->topo; i++)
        free(p->vet[i].obj);

    free(p);
    return NULL;
}

int Cheia(Pilha p)
{
    if(p->topo == MAX)
        return 1;
    return 0;
}

int Vazia(Pilha p)
{
    if(p->topo == 0)
        return 1;

    return 0;
}


int Push(Pilha p, int chave, void *objeto, int sizeObj)
{
    if(Cheia(p))
        return 0;

    p->vet[p->topo].chave = chave;
    p->vet[p->topo].obj = (void*)malloc(sizeObj);
    memcpy(p->vet[p->topo].obj,objeto, sizeObj);

    p->topo++;

    return 1;
}

int Pop(Pilha p, int *chave, void *objeto, int sizeObj)
{
    if(Vazia(p))
        return 0;

    p->topo--;
    *chave = p->vet[p->topo].chave;
    memcpy(objeto, p->vet[p->topo].obj, sizeObj);
    free(p->vet[p->topo].obj);
    p->vet[p->topo].obj = NULL;

    return 1;
}

void Imprimir(Pilha p)
{
    int i;
    printf("\nChaves: ");
    for(i=0; i<p->topo; i++)
        printf("%d ", p->vet[i].chave);
}

int Existe(Pilha p, int chave)
{
    int i;

    for(i=0; i<p->topo; i++)
        if(p->vet[i].chave == chave)
            return 1;

    return 0;
}
