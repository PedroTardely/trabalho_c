#include <stdio.h>
#include <stdlib.h>
#include "modularizacao.h"

int main()
{
    Lista *lista;
    lista = criarLista();
    lista = inserirNaLista(lista, 5);
    lista = inserirNaLista(lista, 15);
    lista = inserirNaLista(lista, 10);
    lista = inserirNaLista(lista, 3);
    // Lista como foi digitada
    printf("\n");
    printf("Lista como foi inserida:\n");
    exibirElementos(lista);
    Lista* x;
    // Buscando elementos
    x = buscarElemento(lista, 15);
    printf("\n");
    printf("O elemento encontrado: %d\n", x->info);
    // Lista após o elemento ser exluido
    printf("\n");
    printf("Lista apos o elemento ser exluido:\n");
    lista = excluirElemento(lista, 15);
    exibirElementos(lista);
    printf("EH NECESSARIO COMENTAR OU APAGAR A FUNCAO 'inserirNaLista' PARA ORDEM CRESCENTE FUNCIONAR!!!\n");
    // Lista ordem Crescente
    printf("\n");
    printf("Lista em ordem crescente\n");
    lista = ordemCrescente(lista, 15);
    lista = ordemCrescente(lista, 3);
    lista = ordemCrescente(lista, 10);
    lista = ordemCrescente(lista, 5);
    exibirElementos(lista);


    
    return 0;
}
