/* Insert node at beginning of Singly Linked List. 
Example: 10 20 30 Insert 5 
Output: 5 10 20 30*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    SLL* head=NULL;//headptr
    printf("Enter the input Data : \n");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Entered Data : ");
    display(head);
    while(head!=NULL){
        SLL* prev=head;
        head=head->next;
        free(prev);
    }
    head=NULL;
    return 0;
}
void createNode(SLL** ptr,int data){
    SLL* new=malloc(sizeof(SLL));
    new->val=data;
    new->next=*ptr;
    *ptr=new;
}
void display(SLL* ptr){
    if(ptr){
        printf("%d ",ptr->val);
        if(ptr->next!=NULL){
            display(ptr->next);
        }
    }
    else{
        printf("Nodes Not there \n");
    }
}