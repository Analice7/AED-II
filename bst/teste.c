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
            	preorder(a1); 
                printf("\n");
                break;
           case 3:
                inorder(a1);
           	printf("\n");
           	break;
           case 4:
           	posorder(a1);
           	printf("\n");
           	break;
           case 5:
           	reverso(a1);
           	printf("\n");
           	break;
           case 6:
           	printf("%d\n", altura(a1));
           	break;
           case 7:
           	valor = 0;
           	qtdFolhas(a1, &valor);
           	printf("%d\n", valor);
           	break;
           case 8:
           	scanf("%d", &valor);
           	caminho(a1, valor);
           	printf("\n");
           	break;
           case 9:
           	scanf("%d", &valor);
                a1 = remover(a1, valor);
                break;
            case 99:
                exit(0);
        }    
    }
    free(a1);
 }
