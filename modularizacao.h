#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int info;
	struct lista* prox;
} Lista;

Lista* criarLista();
Lista* inserirNaLista(Lista* lista, int i);
Lista* exibirElementos(Lista* lista);
Lista* buscarElemento(Lista* lista, int i);
Lista* excluirElemento(Lista* lista, int i);
Lista* ordemCrescente(Lista* lista, int i);
void liberarLista(Lista** lista);

void liberarLista(Lista** lista) {
	Lista *p = *lista;
	while(p == NULL){
		Lista *t = p->prox;
		free(p);
		p = t;
	}

	*lista = NULL;
}

Lista* ordemCrescente(Lista* lista, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;

	if (lista == NULL || lista->info >= i){
		novo->prox = lista;
		return novo;
	}

	Lista* atual = lista;
	while (atual->prox != NULL && atual->prox->info < i) {
		atual = atual->prox;
	}

	novo->prox = atual->prox;
	atual->prox = novo;

	return lista;
}

Lista* excluirElemento(Lista* lista, int i) {
	Lista* ant = NULL;
	Lista* p = lista;
	while(p != NULL && p->info != i) {
		ant = p;
		p = p->prox;
	}
	if(p == NULL) {
		return lista;
	}
	if(ant == NULL) {
		lista = p->prox;
	}else{
	    ant->prox = p->prox;
	}
	free(p);
	return lista;
}

	Lista* buscarElemento(Lista* lista, int i) {
		Lista* p;
		for(p = lista; p != NULL; p = p->prox) {
			if(p->info == i) {
				return p;
			}
		}
		printf("Informação nao encontrada\n");
		return NULL;
	}

	Lista* exibirElementos(Lista* lista) {
		Lista *p;
		if(lista == NULL) {
			printf("Lista vazia");
		} else {
			for(p = lista; p !=NULL; p = p->prox)
				printf("%d \n", p->info);
		}
		return p;
	}

	Lista* inserirNaLista(Lista* lista, int i) {
		Lista* novo = (Lista*) malloc(sizeof(Lista));
		novo->info = i;
		novo->prox = lista;
		return novo;
	}

	Lista* criarLista() {
		return NULL;
	}