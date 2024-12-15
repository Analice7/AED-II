#ifndef AVL_H
#define AVL_H

typedef struct no {
	int fb;
	int valor;
	struct no *esq, *dir;
} no;

typedef no * arvore;

arvore inserir (arvore raiz, int valor, int *cresceu);

arvore remover (arvore raiz, int valor, int *diminuiu);

arvore rotacionar(arvore raiz);

arvore rotacao_simples_esquerda(arvore raiz);

arvore rotacao_simples_direita(arvore raiz);

arvore rotacao_dupla_esquerda(arvore raiz);

arvore rotacao_dupla_direita(arvore raiz);

arvore maiorElemento(arvore raiz);

void preorder(arvore raiz);

#endif
