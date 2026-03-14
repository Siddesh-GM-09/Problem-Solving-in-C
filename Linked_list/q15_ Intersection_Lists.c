/*Find intersection node of two singly linked lists.
Input:
List1: 1 → 2 → 3 → 4 → 5
List2: 9 → 4 → 5
Output: 4 */
#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}SLL;
void createNode(SLL**,int);
void display(SLL*);
SLL* InterSection(SLL*,SLL*);
int main(){
    int n1,n2;
    printf("Enter the number of nodes of L1 : ");
    scanf("%d",&n1);
    printf("Enter the number of nodes of L2 : ");
    scanf("%d",&n2);
    SLL* head1=NULL;
    SLL* head2=NULL;
    printf("Enter the data for Node 1  : ");
    for(int i=0;i<n1;i++){
        int data;
        scanf("%d",&data);
        createNode(&head1,data);
    }
    printf("Enter the data for Node 2  : ");
    for(int i=0;i<n2;i++){
        int data;
        scanf("%d",&data);
        createNode(&head2,data);
    }
    printf("Node 1 : ");
    display(head1);
    printf("\nNode 2 : ");
    SLL* t=head1;
    while(t->next!=NULL && t->next->next!=NULL){
        t=t->next;
    }
    SLL* t1=head2;
    if(t1){
        while(t1->next!=NULL){
            t1=t1->next;
        }
        t1->next=t;
    }
    display(head2);
    SLL* Result = InterSection(head1,head2);
    if(Result){
        printf("Found at : %d\n",Result->val);
    }
    else{
        printf("Not Found\n");
    }
    return 0;
}

SLL* InterSection(SLL* ptr1,SLL* ptr2){
    SLL* t1=ptr1;
    SLL *t2=ptr2;
    while(t1!=t2){
        t1=(t1==NULL)?ptr2:t1->next;
        t2=(t2==NULL)?ptr1:t2->next;
    }
    return t1;
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
        while(last->next!=NULL){
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
        printf("Not Data Found\n");
    }
}