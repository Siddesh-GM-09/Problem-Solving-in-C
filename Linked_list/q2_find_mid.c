#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int num;
    struct number *next;
} SLL;
void addEnd(SLL **,int);
void display(SLL *);
SLL * Findmid(SLL *);
int main()
{
    int size;
    printf("Enter the number of inputs : ");
    scanf("%d",&size);
    SLL *headptr = NULL;
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        int data;
        scanf("%d",&data);
        addEnd(&headptr,data);
    }
    printf("Entered Data is : ");
    display(headptr);
    printf("\n");
    SLL *mid=Findmid(headptr);
    printf("Mid Node data is : %d\n",mid->num);
    return 0;
}
void addEnd(SLL **ptr,int data)
{
    SLL *new = malloc(sizeof(SLL));
    new->num=data;
    new->next = NULL;
    if (*ptr == NULL)
    {
        *ptr = new;
    }
    else
    {
        SLL *last = *ptr;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new;
    }
}
void display(SLL *ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->num);
        if (ptr->next != NULL)
        {
            display(ptr->next);
        }
    }
    else
    {
        printf("Record Not Found\n");
    }
}
SLL * Findmid(SLL *ptr){
    if (ptr==NULL || ptr->next==NULL)
    {
        /* code */
        return ptr;
    }
    SLL *slow=ptr;
    SLL *fast=ptr;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}