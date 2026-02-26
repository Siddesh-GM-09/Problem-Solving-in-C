/*Reverse words in a sentence.
Input:
I love C programming
Output:
programming C love I
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void revWord(char*);
void revSen(char*,char*);
int main(){
    int size;
    printf("Enter the size of sentance : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input line : ");
    scanf(" %[^\n]",str);
    printf("Entered Line : %s\n",str);
    revWord(str);
    printf("After : %s\n",str);
    free(str);
    str=NULL;
    return 0;
}
void revWord(char* str){
    int len=strlen(str)-1;
    char* start=str;
    char* end=str;
    revSen(str,str+len);
    while(*end!='\0'){
        if(*end==' '){
            revSen(start,end-1);
            start=end+1;
        }
        end++;
    }
}
void revSen(char* st,char* ed){
    while(st<ed){
        char temp=*st;
        *st=*ed;
        *ed=temp;
        st++,ed--;
    }
}