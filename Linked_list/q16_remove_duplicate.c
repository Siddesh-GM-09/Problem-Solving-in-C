#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
void removeDup(SLL**);
int main(){
    int size;
    printf("Enter the number of Nodes : ");
    scanf("%d",&size);
    SLL* head=NULL;
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Entered Data : ");
    display(head);
    removeDup(&head);
    printf("\nAfter : ");
    display(head);
    return 0;
}

void removeDup(SLL **head){
    SLL *curr = *head;
    SLL *prev = NULL;
    int hash[1000] = {0};
    while(curr!=NULL){
        if(hash[curr->val]==1){
            if(prev){
                prev->next=curr->next;
            }
            else{
                *head=curr->next;
            }
            SLL* temp=curr;
            curr=curr->next;
        }
        else{
            prev=curr;
            hash[curr->val]=1;
            curr=curr->next;
        }
    }
}

void createNode(SLL** ptr,int data){
    SLL* new=malloc(sizeof(SLL));
    new->next=NULL;
    new->val=data;
    if(*ptr==NULL){
        *ptr=new;
    }
    else{
        SLL* last=*ptr;
        while (last->next!=NULL){
            last=last->next;
        }
        last->next=new;
    }
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