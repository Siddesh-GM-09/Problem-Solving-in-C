#include<stdio.h>
void reverseString(char *str, int start, int end);
int main(){
    int size;
    printf("Enter the size os string : ");
    scanf("%d",&size);
    char str[size+1];
    printf("Enter the string : ");
    scanf(" %[^\n]",str);
    int len=0;
    for(len=0;str[len];len++);
    reverseString(str,0,len-1);
    printf("After string : %s\n",str);
    return 0;
}
void reverseString(char *str, int start, int end){
    if(start<end){
        char t=str[start];
        str[start]=str[end];
        str[end]=t;
        start++;
        end--;
        reverseString(str,start,end);
    }
}
