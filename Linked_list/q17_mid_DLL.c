/*Find the middle node of a doubly linked list.
Input: 1 2 3 4 5
Output: 3 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    struct Data* prev;
    int val;
    struct Data* next;
}DLL;
void createNode(DLL**,int);
void display(DLL*);
DLL* midNode(DLL*);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    DLL* head=NULL;
    printf("Enter the Data : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("\nEntered Data : ");
    display(head);
    DLL* res=midNode(head);
    printf("\nMid Node is : %d\n",res->val);
    return 0;
}
void createNode(DLL** ptr,int data){
    DLL* new=calloc(1,sizeof(DLL));
    new->val=data;
    if(*ptr==NULL){
        *ptr=new;
    }
    else{
        DLL* last=*ptr;
        while(last->next!=NULL){
            last=last->next;
        }
        new->prev=last;
        last->next=new;
    }
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

DLL* midNode(DLL* ptr){
    if(ptr==NULL){
        return ptr;
    }
    DLL* slow=ptr;
    DLL* fast=ptr;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}