#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int num;
    struct number *next;
} SLL;
void addBeg(SLL **);
void addEnd(SLL **);
void display(SLL *);
int main()
{
    int op;
    SLL *headptr = NULL;
    while (1)
    {
        printf("\n1.Add at begin\n");
        printf("2.Add at End\n");
        printf("3.Display List\n");
        printf("4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            addBeg(&headptr);
            break;
        case 2:
            addEnd(&headptr);
            break;
        case 3:
            display(headptr);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter the valid choice : ");
        }
    }
    return 0;
}
void addBeg(SLL **ptr)
{
    SLL *new;
    new = malloc(sizeof(SLL));
    printf("Enter the number : ");
    scanf("%d", &new->num);
    new->next = *ptr;
    *ptr = new;
}
void addEnd(SLL **ptr)
{
    SLL *new = malloc(sizeof(SLL));
    printf("Enter the number : ");
    scanf("%d", &new->num);
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