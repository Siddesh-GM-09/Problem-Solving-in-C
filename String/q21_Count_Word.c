/*Count number of words in a string.
Sample Input:I love programming
Sample Output: 3 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wordCnt(char*);
int main(){
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size+1);
    printf("Enter the inputs : ");
    scanf(" %[^\n]",str);
    printf("Entered Data : %s\n",str);
    int cnt=wordCnt(str);
    printf("Total words are : %d\n",cnt);
    free(str);
    str=NULL;
    return 0;
}
int wordCnt(char* str){
    int cnt=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' ' && (str[i+1]==' ' || str[i+1]=='\0') ){
            cnt++;
        }
    }
    return cnt;
}