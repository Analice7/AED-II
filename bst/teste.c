#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char * argv[]) {
    //Declarar uma variável do tipo árvore
    arvore a1;
    //inicializar como uma árvore vazia
    a1 = NULL;
    
    while(1) {
        int opcao;
        int valor;
        
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                scanf("%d", &valor);
                a1 = inserir(a1, valor);
                break;
            case 2:
            	scanf("%d", &valor);
                a1 = remover(a1, valor);
                break;
            case 3:
                preorder(a1); 
                printf("\n");
                break;
           case 4:
           	inorder(a1);
           	printf("\n");
           	break;
           case 5:
           	posorder(a1);
           	printf("\n");
           	break;
            case 0:
                exit(0);
        }    
    }
    free(a1);
 }
