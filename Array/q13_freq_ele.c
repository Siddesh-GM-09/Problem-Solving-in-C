#include<stdio.h>
#include<stdlib.h>
void freqEle(int*,int);
int main(){
    int size,*arr;
    printf("Enter the size : ");
    scanf("%d",&size);
    arr=calloc(size,sizeof(int));
    printf("Enter the inputs : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Data : ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    freqEle(arr,size);
    free(arr);
    arr=NULL;
    return 0;
}
void freqEle(int* arr,int size){
    int *freq=malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        freq[i]=-1;
    }
    for(int i=0;i<size;i++){
        int cnt=0;
        if(freq[i]==-1){
            for(int j=i;j<size;j++){
                if(arr[i]==arr[j]){
                    cnt++;
                    freq[j]=0;
                }
            }
        }
        freq[i]=cnt;
    }
    printf("Freq of Each Elements are : \n");
    for(int i=0;i<size;i++){
        if(freq[i]!=0){
            printf("Ele : %d Freq : %d\n",arr[i],freq[i]);
        }
    }
    free(freq);
    freq=NULL;
}