#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
int my_Atoi(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the inputs : ");
    scanf(" %[^\n]",str);
    printf("Data is : %s\n",str);
    int res=my_Atoi(str);
    printf("Number is : %d\n",res);
    free(str);
    str=NULL;
    return 0;
}
int my_Atoi(char* str){
    int res=0;
    int sign=1;
    while(*str==' '){
        str++;
    }
    if(*str=='-'){
        sign=-1;
        str++;
    }
    else if(*str=='+'){
        str++;
    }
    while(*str>='0' && *str<='9' && *str!='\0'){
        res=res*10+(*str-'0');
        if(res>=INT_MAX && res>=0){
            return INT_MAX;
        }
        else if(res<=INT_MIN && res<0){
            return INT_MIN;
        }
        str++;
    }
    return res;
}