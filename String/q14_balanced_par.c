/*Check balanced parenthesis.
Input: ((a+b)*c)
Output: Balanced
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char isBalanced(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input: ");
    scanf(" %[^\n]",str);
    printf("Entered Data : %s\n",str);
    char flag=isBalanced(str);
    if(flag){
        printf("Balanced\n");
    }
    else{
        printf("Imbalanced\n");
    }
    free(str);
    str=NULL;
    return 0;
}
char isBalanced(char* str){
    int len=strlen(str);
    char *stack=malloc(sizeof(char)*len);
    int k=0;
    for(int i=0;str[i]!='\0';i++){
        unsigned char ch=str[i];
        if(ch=='}'||ch==']' || ch==')'){
            if(k<0){
                return 0;
            }
            if(ch=='}' && stack[k-1]!='{'){
                return 0;
            }
            if(ch==']' && stack[k-1]!='['){
                return 0;
            }
            if(ch==')' && stack[k-1]!='('){
                return 0;
            }
            k--;
        }
        else if(ch=='{' || ch == '[' || ch=='('){
            stack[k++]=ch;
        }
    }
    return k==0;
}