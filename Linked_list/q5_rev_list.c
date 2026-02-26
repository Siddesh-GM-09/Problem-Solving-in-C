/*Reverse a singly linked list.
Input:
1 2 3 4
Output:
4 3 2 1*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
void revNode(SLL** ptr);
int main(){
    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    SLL* headptr=NULL;
    printf("Enter the data : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&headptr,data);
    }
    printf("Entered Data : ");
    display(headptr);
    revNode(&headptr);
    printf("\nAfter Reverse : ");
    display(headptr);
    return 0;
}
void revNode(SLL** ptr){
    SLL *p=*ptr,*r=NULL;
    while(p!=NULL){
        SLL* q=p;
        p=p->next;
        q->next=r;
        r=q;
    }
    *ptr=r;
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