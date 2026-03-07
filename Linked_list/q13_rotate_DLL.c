/*Rotate doubly linked list by N nodes.
Input: 1 2 3 4 5
Rotate 2
Output: 3 4 5 1 2 */

#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    struct Data* prev;
    int val;
    struct Data* next;
}DLL;
void createNode(DLL**,int);
void display(DLL* );
void rotateList(DLL**,int);
void freeNode(DLL**);
int main(){
    int size;
    DLL* head=NULL;
    printf("Enter the size : ");
    scanf("%d",&size);
    printf("Enter the data : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Ented Data : ");
    display(head);
    int k;
    printf("Enter the number of rotations : ");
    scanf("%d",&k);
    rotateList(&head,k);
    printf("After : ");
    display(head);
    freeNode(&head);
    return 0;
}
void rotateList(DLL** ptr,int k){
    if(k==0 || *ptr==NULL || (*ptr)->next==NULL){
        return;
    }
    int cnt=0;
    DLL *temp=*ptr;
    while(temp->next!=NULL){
        cnt++;
        temp=temp->next;
    }
    temp->next=*ptr;
    (*ptr)->prev=temp;
    cnt++;
    k=k%cnt;
    cnt=cnt-k;
    DLL* prev=NULL;
    temp=*ptr;
    while(cnt--){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    *ptr=temp;
    (*ptr)->prev=NULL;
    display(*ptr);
}


void freeNode(DLL** ptr){
    DLL* del;
    while(*ptr!=NULL){
        del=*ptr;
        *ptr=(*ptr)->next;
        free(del);
    }
    ptr=NULL;
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
        last->next=new;
        last->prev=*ptr;
    }
}

void display(DLL* ptr){
    if(ptr==NULL){
        printf("Record Not Found\n");
    }
    do{
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    while(ptr!=NULL);
    printf("\n");
}