//Pilha.h
typedef struct pilha *Pilha;


Pilha Inicializar(void);
Pilha Destruir(Pilha p);
int Push(Pilha p, int chave, void *objeto, int sizeObj);
int Pop(Pilha p, int *chave, void *objeto, int sizeObj);
void Imprimir(Pilha p);
int Existe(Pilha p, int chave);
