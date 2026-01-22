#include "header.h"
int main(){
    int op,n;
    BST* root=NULL;
    while(1){
        printf("1.Insert 2.In Order 3.Pre Order 4.Post Order 5.exit\n");
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
            case 5:exit(0);
            default:printf("Enter valid Options\n");
        }
    }
}
