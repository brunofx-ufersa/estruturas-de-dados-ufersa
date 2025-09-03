#include <stdio.h>
#include <stdlib.h>

/* Estrutura do Nó */

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
} Node;

/* Função para Criar um Nó */

Node* createNode(int key) { 
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}

/* Funções de Travessia */

void preorder(Node* root){
    if (root){
        printf(" %d", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if (root){
        inorder(root->left);
        printf(" %d", root->key);
        inorder(root->right);
    }
}

void posorder(Node* root){
    if (root){
        posorder(root->left);
        posorder(root->right);
        printf(" %d", root->key);
    }
}

int main () {

    Node* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(5);
    root->right->left = createNode(12);
    root->right->right = createNode(18);
    
    printf("Pre-Ordem: ");
    preorder(root);
    printf("\n");

    printf("Ordem:     ");
    inorder(root);
    printf("\n");

    printf("Pos-Ordem: ");
    posorder(root);
    printf("\n");
    
    return 0;

}

