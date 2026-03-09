/*Generate all permutations of a string.
Input: ABC
Output:ABC ACB BAC BCA CAB CBA */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void genPerm(char*,int,int);
void swap(char*,char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input : ");
    scanf("%s",str);
    printf("Entered Input : %s\n",str);
    int len=strlen(str);
    genPerm(str,0,len-1);
    free(str);
    str=NULL;
    return 0;
}
void genPerm(char* str,int l,int r){
    if(l==r){
        printf("%s ",str);
        return;
    }
    for(int i=l;i<=r;i++){
        swap(&str[l],&str[i]);
        genPerm(str,l+1,r);
        swap(&str[l],&str[i]);
    }
}
void swap(char* st,char* ed){
    char temp=*st;
    *st=*ed;
    *ed=temp;
}