/*Count nodes in circular linked list.
Input:
1 2 3 4
Output: 4      */

#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}CLL;
void addBeg(CLL**);
void display(CLL*);
void count(CLL*);
int main(){
    int op;
    CLL* head=NULL;
    while(1){
        printf("\nEnter the options : 1.add 2.display 3.count 4.exit\n");
        scanf("%d",&op);
        switch(op){
            case 1: addBeg(&head);break;
            case 2: display(head);break;
            case 3: count(head);break;
            case 4:exit(0);
            default:printf("Enter the valid option\n");
        }
    }
}
void addBeg(CLL** ptr){
    CLL* new=malloc(sizeof(CLL));
    printf("Enter the value : ");
    scanf("%d",&new->val);
    if(*ptr==NULL){
        new->next=new;
    }
    else{
        CLL* last=*ptr;
        while(last->next!=*ptr){
            last=last->next;
        }
        last->next=new;
        new->next=*ptr;
    }
    *ptr=new;
}
void display(CLL* ptr){
    if(ptr==NULL){
        return;
    }
    CLL* temp=ptr;
    do
    {
        printf("%d ",temp->val);
        temp=temp->next;
    } 
    while (temp!=ptr);
    printf("\n");
}
void count(CLL* ptr){
    int cnt=0;
    CLL* temp=ptr;
    do{
        cnt++;
        temp=temp->next;
    }
    while(temp!=ptr);
    printf("Total nodes are : %d\n",cnt);
}