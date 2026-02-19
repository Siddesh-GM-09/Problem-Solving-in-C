#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char isBalanced(char* );
int main(){
    int size;
    printf("Enter the size of sting : ");
    scanf("%d",&size);
    char *str=malloc(sizeof(int)*size+1);
    printf("Enter the input : ");
    scanf("%s",str);
    printf("Entered Data : %s\n",str);
    char res=isBalanced(str);
    if(res){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    free(str);
    str=0;
    return 0;
}
char isBalanced(char* str){
    char *stack=malloc(sizeof(char)*strlen(str)+1);
    int i,k=0;
    for(i=0;str[i]!='\0';i++){
        char ch=str[i];
        if(ch=='}' || ch==']' || ch==')'){
            if(k<0){
                return 0;
            }
            if(ch==')' && stack[k-1]!='('){
                return 0;
            }
            if(ch=='}' && stack[k-1]!='{'){
                return 0;
            }
            if(ch==']' && stack[k-1]!='['){
                return 0;
            }
            k--;
        }
        else{
            stack[k++]=ch;
        }
    }
    return k==0;
}