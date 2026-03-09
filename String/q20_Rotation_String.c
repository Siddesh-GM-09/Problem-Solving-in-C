/*Check whether one string is a rotation of another.
Input: str1 => ABCD  str2 => CDAB
Output: Yes */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isRotation(char*,char*);
int main(){
    int s1,s2;
    printf("Enter the size of str1 & str2 : ");
    scanf("%d %d",&s1,&s2);
    char* str1=malloc(sizeof(char)*s1+1);
    char* str2=malloc(sizeof(char)*s2+1);
    printf("Enter the str1 : ");
    scanf("%s",str1);
    printf("Entert the str2 : ");
    scanf("%s",str2);
    printf("str1 : %s\nstr2 : %s\n",str1,str2);
    int flag=isRotation(str1,str2);
    if(flag){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    free(str1);
    free(str2);
    str2=str1=NULL;
    return 0;
}
int isRotation(char* str1,char* str2){
    char* res=malloc(sizeof(char)*strlen(str1)*2+1);
    strcpy(res,str1);
    strcat(res,str1);
    if(strstr(res,str2)){
        free(res);
        res=NULL;
        return 1;
    }
    free(res);
    res=NULL;
    return 0;
}