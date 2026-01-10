#include<stdio.h>
char firstNonRepeating(char *str);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char str[size+1];
    printf("Enter the input : ");
    scanf(" %[^\n]",str);
    char ch=firstNonRepeating(str);
    if(ch==-1){
        printf("No non-repeating character\n");
        return 0;
    }
    printf("Character is : %c\n",ch);
    return 0;
}
char firstNonRepeating(char *str){
    for(int i=0;str[i]!='\0';i++){
        int isUnique=1;
        for(int j=0;str[j];j++){
            if(str[i]==str[j] && i!=j){
                isUnique=0;
                break;
            }
        }
        if(isUnique){
            return str[i];
        }
    }
    return '\0';
}
