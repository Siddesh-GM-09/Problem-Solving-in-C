#include<stdio.h>
#include<stdlib.h>

char* remDup(char*);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input data : ");
    scanf(" %[^\n]",str);
    printf("Entered Data : %s\n",str);
    char* fin=remDup(str);
    printf("After : %s\n",fin);
    free(str);
    str=NULL;
    fin=NULL;
    return 0;
}

char* remDup(char* str){
    unsigned char stack[256];
    for(int i=0;i<256;i++){
        stack[i]=0;
    }
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        unsigned char ch=str[i];
        if(!stack[ch]){
            str[index++]=ch;
            stack[ch]=1;
        }
    }
    str[index]='\0';
    return str;
}