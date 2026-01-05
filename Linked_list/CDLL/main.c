#include "header.h"
int main()
{
    int op, cnt;
    CDLL *headptr = NULL;
    while (1)
    {
        printf("1.Add Begin 2.Add End 3.Print Nodes 4.Count Node 5.Reverse Print 6.Delect Node ");
        printf("7.Exit\n");
        printf("Enter your Choice : ");
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
            cnt = countNode(headptr);
            printf("Total Nodes : %d\n", cnt);
            break;
        case 5:
            revPrint(headptr);
            break;
        case 6:
            delectNode(&headptr);
            break;
        case 7:
            exit(0);
        default:
            printf("Enter the valid option!!\n");
        }
    }
}
void addBeg(CDLL **ptr)
{
    CDLL *new = malloc(sizeof(CDLL));
    printf("Enter the number : ");
    scanf("%d", &new->num);
    if (*ptr == NULL)
    {
        *ptr = new->next = new->prev = new;
    }
    else
    {
        CDLL *last = (*ptr)->prev;
        last->next = new;
        new->prev = last;
        new->next = *ptr;
        (*ptr)->prev = new;
        *ptr = new;
    }
}
void display(CDLL *ptr)
{
    if (ptr == NULL)
    {
        printf("Record Not Found\n");
        return;
    }
    CDLL *temp = ptr;
    while (1)
    {
        printf("%d ", temp->num);
        temp = temp->next;
        if (temp == ptr)
        {
            break;
        }
    }
    printf("\n");
}
void addEnd(CDLL **ptr)
{
    CDLL *new = malloc(sizeof(CDLL));
    printf("Enter the number : ");
    scanf("%d", &new->num);
    if (*ptr == NULL)
    {
        *ptr = new->next = new->prev = new;
    }
    else
    {
        CDLL *last = (*ptr)->prev;
        last->next = new;
        new->prev = last;
        new->next = *ptr;
        (*ptr)->prev = new;
    }
}
int countNode(CDLL *ptr)
{
    int cnt = 0;
    CDLL *temp = ptr;
    while (1)
    {
        cnt++;
        temp = temp->next;
        if (temp == ptr)
        {
            break;
        }
    }
    return cnt;
}
void revPrint(CDLL *ptr)
{
    CDLL *last = ptr->prev;
    while (1)
    {
        printf("%d ", last->num);
        last = last->prev;
        if (last == ptr->prev)
        {
            break;
        }
    }
    printf("\n");
}
void delectNode(CDLL **ptr)
{
    if (*ptr == NULL)
    {
        printf("No Record Present\n");
        return;
    }
    int n1;
    printf("Enter the number : ");
    scanf("%d", &n1);
    CDLL *del = *ptr;
    char flag = 0;
    while (1)
    {
        if (del->num == n1)
        {
            if (del == *ptr)
            { // Found at 1st Node
                if (del == del->next)
                { // Only One Node
                    *ptr = NULL;
                }
                else
                { // multi Node
                    del->next->prev = del->prev;
                    *ptr = del->next;
                    del->prev->next = *ptr;
                }
            }
            else if (del->next == *ptr)
            { // Last Node
                del->prev->next = del->next;
                (*ptr)->prev = del->prev;
            }
            else
            {
                del->prev->next = del->next;
                del->next->prev = del->prev;
            }
            flag = 1;
            free(del);
            break;
        }
        del = del->next;
        if (del == *ptr)
        {
            break;
        }
    }
    if (!flag)
    {
        printf("Number not found\n");
    }
    else
    {
        printf("Number Delected\n");
    }
}