#ifndef BST_H
#define BST_H

typedef struct no {
	int valor;
	struct no *esq, *dir;
} no;

typedef no * arvore;

arvore inserir (arvore raiz, int valor);

void preorder(arvore raiz);

void inorder(arvore raiz);

void posorder(arvore raiz);

void reverso(arvore raiz);

int altura(arvore raiz);

void qtdFolhas(arvore raiz, int* total);

void caminho(arvore raiz, int valor);

int buscar(arvore raiz, int valor);

arvore remover (arvore raiz, int valor);

arvore maiorElemento(arvore raiz);

#endif
