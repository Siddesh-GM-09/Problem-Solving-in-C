#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
    struct tree* left;
    int num;
    struct tree* right;
}BST;

void insertNode(BST**,int);
void inOrder(BST*);
void preOrder(BST*);
void postOrder(BST*);