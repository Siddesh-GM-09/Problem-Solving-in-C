#include<stdio.h>
void binaryNo(double );
int main(){
    double num;
    printf("Enter the number : ");
    scanf("%lf",&num);
    binaryNo(num);
    return 0;
}
void binaryNo(double num){
    char *ptr=(char*)&num;
    char *p1=(char*)&num;
    ptr=ptr+7;
    printf("Binary is : ");
    for(;ptr!=p1-1;ptr--){
        for(int i=7;i>=0;i--){
            printf("%d",*ptr>>i&1);
        }
        printf(" ");
    }
    printf("\n");
}