#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int maxLen(char*);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char *str=malloc(sizeof(char)*size);
    printf("Enter the input string : ");
    scanf(" %[^\n]",str);
    printf("Entered String is : %s\n",str);
    int len=maxLen(str);
    printf("Max length is %d\n",len);
    free(str);
    str=NULL;
    return 0;
}
int maxLen(char* str){
    int last[256];
    for(int i=0;i<256;i++){
        last[i]=-1;
    }
    int maxl=0,start=0;
    for(int i=0;str[i]!='\0';i++){
        unsigned char ch=str[i];
        if(last[ch]>=start){
            start=last[ch]+1;
        }
        last[ch]=i;
        int curlen=i-start+1;
        if(curlen>maxl){
            maxl=curlen;
        }
    }
    return maxl;
}