/*Insert node at beginning of DLL.
Input:
2 3 4 insert 1
Output:
1 2 3 4*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    struct Data* prev;
    int val;
    struct Data* next;
}DLL;
void display(DLL* );
void createNode(DLL**,int);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    DLL* headptr=NULL;
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&headptr,data);
    }
    printf("Data is : ");
    display(headptr);
    return 0;
}
void createNode(DLL** ptr,int data){
    DLL* new=calloc(1,sizeof(DLL));
    new->prev=NULL;
    new->val=data;
    new->next=*ptr;
    if(*ptr!=NULL){
        (*ptr)->prev=new;
    }
    *ptr=new;
}
void display(DLL* ptr){
    if(ptr){
        printf("%d ",ptr->val);
        if(ptr->next!=NULL){
            display(ptr->next);
        }
    }
    else{
        printf("Not Records found\n");
    }
}