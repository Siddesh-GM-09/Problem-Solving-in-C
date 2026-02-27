/* Insert Node in Doubly Linked List */
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    struct Data* prev;
    int val;
    struct Data* next;
}DLL;

void createNode(DLL**,int);
void display(DLL*);
void insertNode(DLL**,int);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    DLL* head=NULL;
    printf("Enter the data : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Entered Data in DLL : ");
    display(head);
    int data;
    printf("\nEnter the number to insert : ");
    scanf("%d",&data);
    insertNode(&head,data);
    printf("Entered Data in DLL : ");
    display(head);
    printf("\n");
    return 0;
}
void insertNode(DLL** ptr,int data){
    DLL* newPtr=calloc(1,sizeof(DLL));
    DLL* temp=*ptr;
    newPtr->val=data;
    int pos,cnt=0;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==0){
        newPtr->next=*ptr;
        *ptr=newPtr;
        return ;
    }
    while (temp!=NULL)
    {
        if(pos==cnt){
            newPtr->next=temp;
            newPtr->prev=temp->prev;
            temp->prev->next=newPtr;
            temp->prev=newPtr;
            return;
        }
        cnt++;
        temp=temp->next;
    }
    printf("Invalid Position\n");
}
void createNode(DLL** ptr,int data){
    DLL* new=calloc(1,sizeof(DLL));
    new->val=data;
    if(*ptr!=NULL){
        (*ptr)->prev=new;
    }
    new->next=*ptr;
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
        printf("Record Not Found\n");
    }
}