/* 
    Implement Queue using Stacks 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Data{
    int val;
    struct Data* next;
}SLL;
SLL* top1=NULL;
SLL* top2=NULL;
void push(SLL** ptr,int data){
    SLL* new=malloc(sizeof(SLL));
    new->val=data;
    new->next=*ptr;
    *ptr=new;
}
int pop(SLL** ptr){
    SLL *temp=*ptr;
    int val=temp->val;
    *ptr=temp->next;
    free(temp);
    return val;
}

void enqueue(int data){
    push(&top1,data);
}
int dequeue(void){
    int val;
    if(top1==NULL && top2==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    if(top2==NULL){
        while(top1!=NULL){
            val=pop(&top1);
            push(&top2,val);
        }
    }
    return pop(&top2);
}
void display(void){
    SLL* temp=top2;
    printf("Queue is : ");
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    int arr[100],i=0;
    temp=top1;
    while(temp!=NULL){
        arr[i++]=temp->val;
        temp=temp->next;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d ",arr[j]);
    }
    printf("\n");
}
int main(){
    int op;
    int data;
    while(1){
        printf("\nEnter the options : ");
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&op);
        switch(op){
            case 1: printf("Enter data : ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2: printf("Dequeued : %d\n",dequeue());break;
            case 3:display(); break;
            case 4:exit(0); break;
            default: printf("Enter the valid Option\n");
        }
    }
    return 0;
}