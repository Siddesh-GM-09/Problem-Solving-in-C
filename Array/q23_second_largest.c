/*Find the second largest element in an array without sorting.
Sample Input:5
10 20 4 45 99
Sample Output: 45*/
#include<stdio.h>
#include<stdlib.h>

int secondMax(const int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the input Data : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int ans=secondMax(arr,size);
    printf("Second Max is : %d\n",ans);
    free(arr);
    arr=NULL;
    return 0;
}
int secondMax(const int* arr,int size){
    int La=arr[0],SLa=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>La){
            SLa=La;
            La=arr[i];
        }
    }
    return SLa;
}