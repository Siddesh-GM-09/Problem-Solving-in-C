/* Delete Node in Singly Linked List
Example: 10 20 30 delete 20
Output: 10 30 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;

void createNode(SLL**,int);
void display(SLL*);
void deleteNode(SLL**,int);
void freeNode(SLL**);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    SLL* head=NULL;
    printf("Enter the data : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Data is : ");
    display(head);
    int data;
    printf("Enter the value to delete : ");
    scanf("%d",&data);
    deleteNode(&head,data);
    printf("After Data is : ");
    display(head);
    freeNode(&head);
    return 0;
}
void deleteNode(SLL** ptr,int data){
    if(*ptr==NULL){
        printf("No Record Found\n");
        return;
    }
    SLL* temp=*ptr;
    SLL* prev=NULL;
    SLL* del=NULL;
    while(temp!=NULL){
        if(temp->val==data){
            if(temp==*ptr){
                del=temp;
                *ptr=temp->next;
                return;
            }
            else{
                prev->next=temp->next;
                del=temp;
            }
            free(del);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Number not Found\n");
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

void freeNode(SLL** ptr){
    SLL* prev=NULL;
    while(*ptr!=NULL){
        prev=*ptr;
        *ptr=(*ptr)->next;
        free(prev);
    }
}