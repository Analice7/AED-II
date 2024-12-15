#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//função inserir recebe como parâmetro o ponteiro para a raiz de uma árvore,
//o valor a ser inserido e RETORNA o ponteiro para a (sub)árvore resultante
arvore inserir (arvore raiz, int valor, int *cresceu) {
	//caso base - instância mais simples do problema
	//inserir em uma árvore vazia
	if(raiz == NULL) {
		//1. Alocar espaço para o nó
		arvore novo = (arvore) malloc(sizeof(no));
		//2. Inicializar o nó
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;
        	novo->fb = 0;   
        	*cresceu = 1;
		//3. Ligação do novo nó com o restante da árvore
		return novo;	
	} else {
		if(valor > raiz->valor) {
			raiz->dir = inserir(raiz->dir, valor, cresceu);
            		//atualizar o FB e rotacionar se necessário
			if(*cresceu) {
				switch(raiz->fb) {
				    case -1:
					raiz->fb = 0; 
					*cresceu = 0; 
					break;
				    case 0:
					raiz->fb = 1;
					*cresceu = 1;
					break;
				    case 1:
					raiz = rotacionar(raiz);
					*cresceu = 0; // Após a rotação, a altura não aumenta mais
					break;
				}
            		}


		} else {
			raiz->esq = inserir(raiz->esq, valor, cresceu);	
		    	//atualizar o FB e rotacionar se necessário
		    	//nó 10 do desenho
		    	if(*cresceu) {
				switch(raiz->fb) {
				    case -1:
					raiz = rotacionar(raiz);
					*cresceu = 0; // Após a rotação, a altura não aumenta mais
					break;
				    case 0:
					raiz->fb = -1;
					*cresceu = 1;
					break;
				    case 1:
					raiz->fb = 0;
					*cresceu = 0;
					break;
				}
		    }

		}
		return raiz;
	}
}

arvore remover (arvore raiz, int valor, int *diminuiu) {
    if(raiz == NULL) {
        *diminuiu = 0;
        return NULL;    
    } else {
        //elemento encontrado
        if(valor == raiz->valor) {
            //caso 1: zero filhos - folhas
            if(raiz->esq  == NULL && raiz->dir == NULL ) {
                *diminuiu = 1;
                free(raiz);
                return NULL;                  
            } 
            
            //caso 2: um filho
            //a) exatamente um filho esquerdo
            if(raiz->esq  != NULL && raiz->dir == NULL ) {
                *diminuiu = 1;
                arvore raizResultante = raiz->esq;
                free(raiz);
                return raizResultante;
            }

            //b) exatamente um filho direito
            if(raiz->esq == NULL && raiz->dir != NULL) {
            	*diminuiu = 1;
            	arvore arvoreResultante = raiz->dir;
            	free(raiz);
            	return arvoreResultante;
	    }
            

            //caso 3: dois filhos
            if(raiz->esq  != NULL && raiz->dir != NULL) {
                raiz->valor = maiorElemento(raiz->esq)->valor;
                raiz->esq = remover(raiz->esq, raiz->valor, diminuiu);
                return raiz;
                  
            }

        } else {
            //procurar pelo elemento
            if(valor > raiz->valor) {
		raiz->dir = remover(raiz->dir, valor, diminuiu);
                //Atualizar FB e rotacionar se necessário
                if(*diminuiu) {
                    switch(raiz->fb) {
                        case 0:
                            raiz->fb = -1;
                            *diminuiu = 0;
                            break;
                        case 1:
                            raiz->fb = 0;
                            *diminuiu = 1;
                            break;
                        case -1:
                            raiz = rotacionar(raiz);
			    if (raiz->fb == 0) {
				*diminuiu = 1;
			    } else {
				*diminuiu = 0;
			    }
			    return raiz;
                    }
                }



	    } else {
		    raiz->esq = remover(raiz->esq, valor, diminuiu);
		    if(*diminuiu) {
			    switch(raiz->fb) {
				case 0:
				    raiz->fb = 1;
				    *diminuiu = 0;
				    break;
				case 1:
				    raiz = rotacionar(raiz);
				    if (raiz->fb == 0) {
					*diminuiu = 1;
				    } else {
					*diminuiu = 0;
				    }
				    return raiz;
				case -1:
				    raiz->fb = 0;
				    *diminuiu = 1;
				    break;
			    }
        	   }

	    }
            return raiz ;
        }
    }
}

arvore rotacionar(arvore raiz) {
    if(raiz->fb > 0) {
        //Rotação esquerda
        if(raiz->dir->fb >= 0) {
            //Atualizar FB
            return rotacao_simples_esquerda(raiz);
        } else {
            //Atualizar FB
            return rotacao_dupla_esquerda(raiz);
        }
    } else {
    	//rotação direita
    	if(raiz->esq->fb <= 0) {
    		return rotacao_simples_direita(raiz);
    	} else {
    		return rotacao_dupla_direita(raiz);
    	}
    }
}

/*
     p
    / \
   t1  u
      / \
     t2 t3

     u
    / \
   p   t3
  / \
 t1 t2

*/
arvore rotacao_simples_esquerda(arvore raiz) {
    arvore p = raiz;
    arvore u = p->dir;

    //Atualizar os ponteiros com o estado resultante
    p->dir = u->esq;
    u->esq = p;

    //Atualizar fatores de balanço
    if(u->fb == 0) {
        u->fb = 0; // resultado do cálculo para o caso +2, 0
        p->fb = 1; //
    } else {
        u->fb = 0; // resultado do cálculo para o caso +2, 0
        p->fb = 0; //

    }
    return u;  
}

/*

     p
    / \
   u   t3
  / \
 t1 t2
 
     u
    / \
   t1  p
      / \
     t2 t3

*/

arvore rotacao_simples_direita(arvore raiz) {
    arvore p = raiz;
    arvore u = p->esq;
    //Atualizar os ponteiros com o estado resultante
    p->esq = u->dir;
    u->dir = p;

    //Atualizar fatores de balanço
    if(u->fb == 0) {
        u->fb = 0; // resultado do cálculo para o caso +2, 0
        p->fb = -1; //
    } else {
        u->fb = 0; // resultado do cálculo para o caso +2, 0
        p->fb = 0; //

    }
    return u;  
}

arvore rotacao_dupla_esquerda(arvore raiz) {
	raiz->dir = rotacao_simples_direita(raiz->dir);
	raiz = rotacao_simples_esquerda(raiz);
	return raiz;
	
}

arvore rotacao_dupla_direita(arvore raiz) {
	raiz->esq = rotacao_simples_esquerda(raiz->esq);
	raiz = rotacao_simples_direita(raiz);
	return raiz;
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

void preorder(arvore raiz){
    if(raiz != NULL) {
        printf("[%d %d]", raiz->valor, raiz->fb);
        preorder(raiz->esq);
        preorder(raiz->dir);
    }
}
