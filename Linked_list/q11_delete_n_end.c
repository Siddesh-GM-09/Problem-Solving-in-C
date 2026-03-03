/*Delete Nth node from end.
Input: 1 2 3 4 5
Delete 2
Output: 1 2 3 5 */

#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
void delNode(SLL**,int);
int main(){
    int size;
    SLL* head=NULL;
    printf("Enter the size : ");
    scanf("%d",&size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&head,data);
    }
    printf("Entered Data : ");
    display(head);
    int k;
    printf("Enter the count Value : ");
    scanf("%d",&k);
    delNode(&head,k);
    printf("After : ");
    display(head);
    return 0;
}

void delNode(SLL** ptr,int k){
    if(*ptr==NULL){
        return ;
    }
    int cnt=0;
    SLL* temp=*ptr;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==k){
        SLL* newHead=(*ptr)->next;
        free(*ptr);
        *ptr=newHead;
    }
    cnt=cnt-k-1;
    temp=*ptr;
    while(cnt--){
        temp=temp->next;
    }
    SLL* del=temp->next;
    temp->next=del->next;
    free(del);
}

void createNode(SLL** ptr,int data){
    SLL* new=malloc(sizeof(SLL));
    new->val=data;
    new->next=NULL;
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