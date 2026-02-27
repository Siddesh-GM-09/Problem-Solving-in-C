/*Problem: Count vowels and consonants in a string.
Input: education
Output: Vowels=5 Consonants=4 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void cntCntVow(char*);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char* str=malloc(sizeof(char)*size);
    printf("Enter the input : ");
    scanf(" %[^\n]",str);
    printf("Entered String : %s\n",str);
    cntCntVow(str);
    free(str);
    str=NULL;
    return 0;
}
void cntCntVow(char* str){
    int Vcnt=0,Ccnt=0;
    for(int i=0;str[i]!='\0';i++){
        char ch=str[i];
        if(ch>='A'&&ch<='Z'){
            ch=ch|32;
        }
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            Vcnt++;
        }
        else if(ch>='a' && ch<='z'){
            Ccnt++;
        }
    }
    printf("Total vowels : %d Consonants : %d\n",Vcnt,Ccnt);
}