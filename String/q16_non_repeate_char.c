/*Find first non-repeating character.
Input : aabbcdd
Output: c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char nonRep(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input : ");
    scanf(" %[^\n]",str);
    printf("Input is : %s\n",str);
    char res=nonRep(str);
    if(res!=0){
        printf("Char is : %c\n",res);
    }
    else{
        printf("No repateing char\n");
    }
    free(str);
    return 0;
}
char nonRep(char* str){
    int freq[256]={0};
    for(int i=0;str[i]!='\0';i++){
        freq[(int)str[i]]++;
    }
    for(int i=0;str[i]!='\0';i++){
        if(freq[(int)str[i]]==1){
            return str[i];
        }
    }
    return 0;
}


/*
char nonRep(char* str){
    int len=strlen(str);
    char *freq=malloc(sizeof(char)*len+1);
    for(int i=0;i<len;i++){
        freq[i]=-1;
    }
    for(int i=0;str[i]!='\0';i++){
        int cnt=0;
        if(freq[i]==-1){
            for(int j=i;str[j]!='\0';j++){
                if(str[i]==str[j]){
                    cnt++;
                    freq[j]=0;
                }
            }
        }
        freq[i]=cnt;
    }
    for(int i=0;i<len;i++){
        if(freq[i]==1){
            return str[i];
        }
    }
    return 0;
}
    */