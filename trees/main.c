#include "header.h"
int main(){
    int op,n;
    BST* root=NULL,*r;
    while(1){
        printf("1.Insert 2.In Order 3.Pre Order 4.Post Order 5.Search Number 6.exit\n");
        scanf("%d",&op);
        switch(op){
            case 1:scanf("%d",&n);
                insertNode(&root,n);
                break;
            case 2:inOrder(root);
                break;
            case 3:preOrder(root);
                break;
            case 4:postOrder(root);
                break;
            case 5:printf("Enter the number to search : ");
                scanf("%d",&n);
                r=searchNode(root,n);
                if(r){
                    printf("Number is found\n");
                }
                else{
                    printf("Number not found\n");
                }
            case 6:exit(0);
            default:printf("Enter valid Options\n");
        }
    }
}
void insertNode(BST** ptr,int data){
    if(*ptr==NULL){
        *ptr=calloc(1,sizeof(BST));
        (*ptr)->num=data;
    }
    else if(data<(*ptr)->num){
        insertNode(&((*ptr)->left),data);
    }
    else if(data>(*ptr)->num){
        insertNode(&((*ptr)->right),data);
    }
    else{
        printf("Duplicates Not Allowed\n");
    }
}
void inOrder(BST *ptr){
    if(ptr){
        inOrder(ptr->left);
        printf("%d ",ptr->num);
        inOrder(ptr->right);
    }
}
void preOrder(BST *ptr){
    if(ptr){
        printf("%d ",ptr->num);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}
void postOrder(BST *ptr){
    if(ptr){
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ",ptr->num);
    }
}
BST*  searchNode(BST *ptr,int data){
    if(ptr){
            if(ptr->num==data){
        return ptr;
        }
        else if(data<ptr->num){
            searchNode(ptr->left,data);
        }
        else if(data>ptr->num){
            searchNode(ptr->right,data);
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}