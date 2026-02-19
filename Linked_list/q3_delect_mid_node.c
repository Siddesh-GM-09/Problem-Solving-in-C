#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
void midDelete(SLL**);
void freeList(SLL** );
int main(){
    int size;
    SLL* head=NULL;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    printf("Enter the Data : \n");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Entered Data : ");
    display(head);
    midDelete(&head);
    printf("After Delete : ");
    display(head);
    freeList(&head);
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
        printf("Record Not Found\n");
    }
}

void midDelete(SLL** ptr){
    if(*ptr==NULL || (*ptr)->next==NULL){
        return ;
    }
    SLL *slow=*ptr;
    SLL *fast=*ptr;
    SLL *prev=NULL;
    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    free(slow);
}
void freeList(SLL** ptr){
    SLL* temp;
    while(*ptr != NULL){
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}