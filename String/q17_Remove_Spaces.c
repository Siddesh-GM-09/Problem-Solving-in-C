/*Remove all spaces from string.
Sample Input:
hello world
Sample Output:
helloworld*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void spaceRem(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input : ");
    scanf(" %[^\n]",str);
    printf("Entered Data : %s\n",str);
    spaceRem(str);
    printf("After : %s\n",str);
    free(str);
    str=NULL;
    return 0;
}
void spaceRem(char* str){
    int index=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            str[index++]=str[i];
        }
    }
    str[index]='\0';
}