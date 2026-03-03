/*Find length of longest substring without repeating characters.
Input: abcabcbb
Output:3 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int withOutRep(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the input :");
    scanf(" %[^\n]",str);
    printf("Entered Input : %s\n",str);
    int res=withOutRep(str);
    printf("The result is : %d\n",res);
    free(str);
    str=NULL;
    return 0;
}
int withOutRep(char* str){
    int last[256];
    for(int i=0;i<256;i++){
        last[i]=-1;
    }
    int maxlen=0,start=0;
    for(int i=0;str[i]!='\0';i++){
        unsigned char ch=str[i];
        if(last[ch]>=start){
            start=last[ch]+1;
        }
        last[ch]=i;
        int curlen=i-start+1;
        if(curlen>maxlen){
            maxlen=curlen;
        }
    }
    return maxlen;
}