/*Implement stack using array with push and pop operations*/
#include<stdio.h>
#include<stdlib.h>
int size=5;
int TOP=-1;
void pop(int*);
void push(int*);
void display(int*);
int main(){
    int op;
    int *arr=malloc(sizeof(int)*size);
    while(1){
        printf("\nEnter the options : \n");
        printf("1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:push(arr);break;
        case 2:pop(arr);break;
        case 3: display(arr);break;
        case 4:exit(0);
        default:printf("Enter Valid Options\n");
        }
    }
}
void push(int* arr){
    if(TOP>size){
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter the Data to push : ");
    scanf("%d",&arr[TOP++]);
    printf("Pushed to stack\n");
}
void pop(int* arr){
    if(TOP<0){
        printf("Stack Underflow\n");
        return ;
    }
    printf("Poped : %d\n",arr[--TOP]);
}
void display(int* arr){
    if(TOP==-1){
        printf("Stack is Empty\n");
        return ;
    }
    printf("Stack Data is : ");
    for(int i=0;i<TOP;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}