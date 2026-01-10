/*Write a C function to:
    Remove duplicate characters from a string
    Keep only the first occurrence
    Modify the string in place
*/
#include<stdio.h>
void removeDuplicates(char *str);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char str[size+1];
    printf("Enter the stirng : ");
    scanf(" %[^\n]",str);
    printf("Before : %s\n",str);
    removeDuplicates(str);
    printf("After  : %s\n",str);
}
void removeDuplicates(char *str){
    for(int i=0;str[i];i++){
        for(int j=i+1;str[j];){
            if(str[i]==str[j]){
                for(int k=j;str[k];k++){
                    str[k]=str[k+1];
                }
            }
            else{
                j++;
            }
        }
    }
}
