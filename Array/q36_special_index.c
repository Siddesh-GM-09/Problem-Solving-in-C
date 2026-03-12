/*Find the index where XOR of left elements becomes greater than XOR of right elements
i/p: size:5   arr : 1 3 5 2 2
o/p:Index = 2
Left sum  = 1 + 3 = 4
Right sum = 2 + 2 = 4
*/
#include<stdio.h>
#include<stdlib.h>
int findIndex(int*,int);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int* arr=malloc(sizeof(int)*size);
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Entered Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    int index=findIndex(arr,size);
    if(index!=-1){
        printf("\nFound at %d\n",index);
    }
    else{
        printf("\nNot Found\n");
    }
    free(arr);
    arr=NULL;
    return 0;
}

int findIndex(int* arr,int size){
    int total=0;
    for(int i=0;i<size;i++){
        total^=arr[i];
    }
    int left=0;
    for(int i=0;i<size;i++){
        left^=arr[i];
        int right=total^left;
        if(left>right){
            return i;
        }
    }
    return -1;
}
// int findIndex(int* arr,int size){
//     int res1=0,res2=0;
//     for(int i=0;i<size;i++){
//         res1^=arr[i];
//         res2=0;
//         for(int j=i+1;j<size;j++){
//             res2^=arr[j];
//         }
//         if(res1>res2){
//             return i;
//         }
//     }
//     return -1;
// }