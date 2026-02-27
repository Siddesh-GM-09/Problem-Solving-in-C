/*Queue using Array*/
#include<stdio.h>
#include<stdlib.h>
int TOP=-1;
int size=5;

void push(int*);
void pop(int*);
void display(int*);
int main(){
    int arr[size];
    int op;
    while(1){
        printf("\nEnter the opion : 1.Push 2.Pop 3.Display 4.exit\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:push(arr);break;
        case 2:pop(arr);break;
        case 3:display(arr);break;
        case 4:exit(0);
        default:printf("Enter the valid option\n");
        }
    }
}

void push(int* arr){
    if(TOP>=size-1){
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter the Data : ");
    scanf("%d",&arr[++TOP]);
}
void pop(int* arr){
    if(TOP<0){
        printf("Queue Under Flow\n");
        return;
    }
    printf("Poped : %d\n",arr[0]);
    for(int i=0;i<TOP;i++){
        arr[i]=arr[i+1];
    }
    TOP--;
}
void display(int* arr){
    printf("Queue is : ");
    for(int i=0;i<=TOP;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}