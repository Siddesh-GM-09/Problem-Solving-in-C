/*Print matrix in spiral order.
Sample Input: 
1 2 3
4 5 6
7 8 9
Sample Output: 1 2 3 6 9 8 7 4 5*/

#include<stdio.h>
#include<stdlib.h>

void spiralPrint(int row,int col,int *(arr)[row]);
int main(){
    int row,col;
    printf("Enter the row and columns : ");
    scanf("%d %d",&row,&col);
    int** arr=(int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++){
        arr[i]=malloc(sizeof(int)*col);
    }
    printf("Enter the inputs : ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Entered Data \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    spiralPrint(row,col,arr);
    return 0;
}
void spiralPrint(int row,int col,int *(arr)[row]){
    int *res=malloc(sizeof(int)*col*row);
    int left=0,right=col-1;
    int top=0,bottom=row-1;
    int k=0;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[k++]=arr[top][i];
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[k++]=arr[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                res[k++]=arr[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res[k++]=arr[i][left];
            }
            left++;
        }
    }
    for(int i=0;i<k;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}