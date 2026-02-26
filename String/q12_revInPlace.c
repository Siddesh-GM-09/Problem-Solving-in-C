/*Reverse a string without using library functions. 
Input: hello 
Output: olleh*/

#include<stdio.h>
#include<stdlib.h>
void revInPlace(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the inputs : ");
    scanf(" %[^\n]",str);
    printf("Before : %s\n",str);
    revInPlace(str);
    printf("After : %s\n",str);
    free(str);
    str=NULL;
    return 0;
}
void revInPlace(char* str){
    int len;
    for(len=0;str[len]!='\0';len++);
    char *st=str;
    char *en=str+len-1;
    while(st<en){
        char ch=*st;
        *st=*en;
        *en=ch;
        st++,en--;
    }
}