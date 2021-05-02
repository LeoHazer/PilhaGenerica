#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct aluno
{
    char nome[80];
    int matricula;
    float CR;
}Aluno;


int main()
{

    int i;
    Pilha p = Inicializar();

    for(i=0; i<3;)
    {
        Aluno a;
        printf("Digite a matricula, nome e CR do aluno\nnesta ordem:\n");
        scanf("%d", &a.matricula);
        scanf("%s", a.nome);
        scanf("%f", &a.CR);

        if(!Existe(p, a.matricula))
        {
            Push(p, a.matricula, &a, sizeof(a));
            i++;
        }
    }

    for(i=0; i<3; i++)
    {
        int key;
        Aluno obj;

        Pop(p, &key, &obj, sizeof(obj));
        printf("\nChave: %d\tObjeto: (%d, %s, %.2f)", key, obj.matricula,obj.nome, obj.CR);
        printf("\n");
        Imprimir(p);
    }

    p = Destruir(p);
    return 0;
}
