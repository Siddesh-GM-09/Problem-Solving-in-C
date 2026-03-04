/*Insert node at end of circular linked list.
Sample Input:
10 20 30 Insert 40
Sample Output:
10 20 30 40 */

#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    int val;
    struct Data* next;
}CLL;

void addEnd(CLL**,int);
void display(CLL*);
int main(){
    int op,data;
    CLL* headptr=NULL;
    while(1){
        printf("Enter the option : ");
        printf("1.Insert 2.Display 3.Exit\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the data : ");
            scanf("%d",&data);
            addEnd(&headptr,data);
            break;
        case 2: 
            printf("Data is : ");
            display(headptr);
            break;
        case 3:
            exit(0);
        default:printf("Enter the valid option\n");
        }
    }
}

void addEnd(CLL** ptr,int data){
    CLL* new=malloc(sizeof(CLL));
    new->val=data;
    if(*ptr==NULL){
        new->next=new;
        *ptr=new;
    }
    else{
        CLL* last=*ptr;
        new->next=*ptr;
        while(last->next!=*ptr){
            last=last->next;
        }
        last->next=new;
    }
}
void display(CLL* ptr){
    CLL * temp=ptr;
    do{
        printf("%d ",temp->val);
        temp=temp->next;
    }while(temp!=ptr);
    printf("\n");
}