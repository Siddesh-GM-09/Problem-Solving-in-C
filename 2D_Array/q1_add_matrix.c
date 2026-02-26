/*Add two matrices. Input 2x2 matrices Output summed matrix*/
#include<stdio.h>
#include<stdlib.h>
int** MemAlloc(int,int);
void scan(int** ,int,int);
void print(int* const*,int ,int );
void freeMem(int**,int,int);
void addMatrix(int**,int**,int,int);
int main(){
    int row,col;
    printf("Enter the number of rows & columns : ");
    scanf("%d %d",&row,&col);
    int** arr1=MemAlloc(row,col);
    int** arr2=MemAlloc(row,col);
    scan(arr1,row,col);
    scan(arr2,row,col);
    printf("Entered Matrix1 : \n");
    print(arr1,row,col);
    printf("Entered Matrix1 : \n");
    print(arr2,row,col);
    addMatrix(arr1,arr2,row,col);
    freeMem(arr1,row,col);
    freeMem(arr2,row,col);
}

void addMatrix(int** arr1,int** arr2,int row,int col){
    int **res=MemAlloc(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            res[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("Result Matrix1 : \n");
    print(res,row,col);
    freeMem(res,row,col);
}

int** MemAlloc(int r,int c){
    int** arr;
    arr=malloc(sizeof(int*)*r);
    for(int i=0;i<r;i++){
        arr[i]=malloc(sizeof(int)*c);
    }
    return arr;
}
void scan(int** arr,int row,int col){
    printf("Enter The data  : \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}
void print(int* const * arr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void freeMem(int** arr,int row,int col){
    for(int i=0;i<row;i++){
        free(arr[i]);
    }
    free(arr);
    arr=NULL;
}