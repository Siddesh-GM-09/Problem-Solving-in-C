/*Matrix Transpose */
#include<stdio.h>
#include<stdlib.h>
int** MemAlloc(int,int);
void scan(int** ,int,int);
void print(int* const*,int ,int );
void freeMem(int**,int,int);
void transpose(int ** arr,int row,int col);
int main(){
    int row,col;
    printf("Enter the number of rows & columns : ");
    scanf("%d %d",&row,&col);
    int** arr=MemAlloc(row,col);
    scan(arr,row,col);
    printf("Entered Matrix1 : \n");
    print(arr,row,col);
    transpose(arr,row,col);
    freeMem(arr,row,col);
}

void transpose(int** arr,int row,int col){
    int** res=MemAlloc(col,row);
    for(int j=0;j<col;j++){
        for(int i=0;i<row;i++){
            res[j][i]=arr[i][j];
        }
    }
    printf("Final : \n");
    print(res,col,row);
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