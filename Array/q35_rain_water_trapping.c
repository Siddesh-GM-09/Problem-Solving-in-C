/* Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include<stdio.h>
#include<stdlib.h>

int totalWater(int*,int);
int main(){
    int size;
    printf("Enter the Number of buildings : ");
    scanf("%d",&size);
    int* height=malloc(sizeof(int)*size);
    printf("Enter the building height : ");
    for(int i=0;i<size;i++){
        scanf("%d",&height[i]);
    }
    printf("Heights are : ");
    for(int i=0;i<size;i++){
        printf("%d ",height[i]);
    }
    int result=totalWater(height,size);
    printf("\nTotal Watered Trapped is : %d\n",result);
    free(height);
    height=NULL;
    return 0;
}
int totalWater(int* height,int size){
    int l=0,r=size-1;
    int lmax=0,rmax=0;
    int res=0;
    while(l<r){
        if(height[l]<height[r]){
            if(height[l]>=lmax){
                lmax=height[l];
            }
            else{
                res+=lmax-height[l];
            }
            l++;
        }
        else{
            if(height[r]>=rmax){
                rmax=height[r];
            }
            else{
                res+=rmax-height[r];
            }
            r--;
        }
    }
    return res;
}