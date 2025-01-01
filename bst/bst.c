#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


//função inserir recebe como parâmetro o ponteiro para a raiz de uma árvore,
//o valor a ser inserido e RETORNA o ponteiro para a (sub)árvore resultante
arvore inserir (arvore raiz, int valor) {
	//caso base - instância mais simples do problema
	//inserir em uma árvore vazia
	if(raiz == NULL) {
		//1. Alocar espaço para o nó
		arvore novo = (arvore) malloc(sizeof(no));
		//2. Inicializar o nó
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		//3. Ligação do novo nó com o restante da árvore
		return novo;	
	} else {
		if(valor > raiz->valor) {
			raiz->dir = inserir(raiz->dir, valor);
		} else {
			raiz->esq = inserir(raiz->esq, valor);	
		}
		return raiz ;
	}
}

void preorder(arvore raiz){
    if(raiz != NULL) {
        printf("[%d]", raiz->valor);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}

void inorder(arvore raiz) {
	if(raiz != NULL) {
		inorder(raiz->esq);
		printf("[%d]",raiz->valor);
		inorder(raiz->dir);
	}
}

void posorder(arvore raiz) {
	if(raiz != NULL) {
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->valor);
	}
}

void reverso(arvore raiz) {
	if(raiz != NULL) {
		reverso(raiz->dir);
		printf("[%d]",raiz->valor);
		reverso(raiz->esq);
	}
}

int altura(arvore raiz) {
    if (raiz == NULL) {
        return -1;
    }
    
    int alturaEsquerda = altura(raiz->esq);
    int alturaDireita = altura(raiz->dir);

    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

void qtdFolhas(arvore raiz, int* total) {
    if (raiz != NULL) {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            (*total)++;
        } else { 
            qtdFolhas(raiz->esq, total);
            qtdFolhas(raiz->dir, total);
        }
    }
}

void caminho(arvore raiz, int valor) {
	if(!buscar(raiz, valor)) {
		return;
	}
	if (raiz != NULL) {
		printf("[%d]", raiz->valor);
        	if (valor > raiz->valor) {
            		caminho(raiz->dir, valor);
		} else if (valor < raiz->valor) {
            		caminho(raiz->esq, valor);
		}
    	}
}

arvore remover (arvore raiz, int valor) {
    if(raiz == NULL) {
        return NULL;    
    } else {
        //elemento encontrado
        if(valor == raiz->valor) {
            //caso 1: zero filhos - folhas
            if(raiz->esq  == NULL && raiz->dir == NULL ) {
                free(raiz);
                return NULL;                  
            } 
            
            //caso 2: um filho
            //a) exatamente um filho esquerdo
            if(raiz->esq  != NULL && raiz->dir == NULL ) {
                arvore raizResultante = raiz->esq;
                free(raiz);
                return raizResultante;
            }

            //exatamente um filho direito
            if(raiz->esq  == NULL && raiz->dir != NULL ) {
                arvore raizResultante = raiz->dir;
                free(raiz);
                return raizResultante;
            }
            

            //caso 3: dois filhos
            if(raiz->esq  != NULL && raiz->dir != NULL) {
                raiz->valor = maiorElemento(raiz->esq)->valor;
                raiz->esq = remover(raiz->esq, raiz->valor);
                return raiz;
                  
            }

        } else {
            //procurar pelo elemento
            if(valor > raiz->valor) {
			    raiz->dir = remover(raiz->dir, valor);
		    } else {
			    raiz->esq = remover(raiz->esq, valor);	
		    }
            return raiz ;
        }
    }
}

arvore maiorElemento(arvore raiz){
    arvore temp = raiz;
    if(temp == NULL)
        return NULL;
    while(temp->dir != NULL) {
        temp = temp->dir;
    }
    return temp;
}

int buscar(arvore raiz, int valor) {
	if(raiz != NULL){
		if (valor > raiz->valor) {
            		return buscar(raiz->dir, valor);
		} else if (valor < raiz->valor) {
            		return buscar(raiz->esq, valor);
		} else {
		  	return 1;
		}
	}
	return 0;
}




