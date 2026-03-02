/*Delete node at given position.
Input: 1 2 3 4 5
Delete position 3
Output: 1 2 4 5  */

#include<stdio.h>
#include<stdlib.h>
typedef struct Data{
    struct Data* prev;
    int val;
    struct Data* next;
}DLL;
void createNode(DLL**,int);
void display(DLL*);
void delNode(DLL**,int);
int main(){
    int size,pos;
    DLL* headptr=NULL;
    printf("Enter the number of nodes for DLL : ");
    scanf("%d",&size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        createNode(&headptr,data);
    }
    printf("Entered Data : ");
    display(headptr);
    printf("Enter the postion to delete : ");
    scanf("%d",&pos);
    delNode(&headptr,pos);
    printf("After : ");
    display(headptr);
    return 0;
}

void delNode(DLL** ptr,int pos){
    int cnt=0;
    DLL* temp=*ptr;
    DLL* del=NULL,*prev=NULL;
    while(temp!=NULL){
        if(cnt==pos){
            if(temp==*ptr){
                *ptr=temp->next;
                if(*ptr!=NULL){
                    (*ptr)->prev=NULL;
                }
            }
            else{
                prev->next=temp->next;
                if(temp->next!=NULL){
                    temp->next->prev=prev;
                }
            }
            free(temp);
            return;
        }
        cnt++;
        prev=temp;
        temp=temp->next;
    }
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