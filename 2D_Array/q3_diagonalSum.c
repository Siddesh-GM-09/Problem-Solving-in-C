/*Find diagonal sum.
Sample Input:
1 2
3 4
Sample Output: 5*/

#include<stdio.h>
#include<stdlib.h>
int sumDia(int**,int,int);
int main(){
    int row,col;
    printf("Enter the number of rows : ");
    scanf("%d",&row);
    printf("Enter the number of col : ");
    scanf("%d",&col);
    int **arr;
    arr=malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++){
        arr[i]=malloc(sizeof(int)*col);
    }
    printf("Enter Matrix \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Data is : \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int ans=sumDia(arr,row,col);
    printf("Result is : %d\n",ans);
    for(int i=0;i<row;i++){
        free(arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}

int sumDia(int** arr,int row,int col){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==j){
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}