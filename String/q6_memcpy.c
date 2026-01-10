#include<stdio.h>
#include<stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n);
int main(){
    int size;
    printf("Enter the size of string : ");
    scanf("%d",&size);
    char *src=malloc(sizeof(char)*size+1);
    char *dest=malloc(sizeof(char)*size+1);
    printf("Enter the source ");
    scanf(" %[^\n]",src);
    int n;
    printf("Enter the copy size :");
    scanf("%d",&n);
    my_memcpy(dest,src,n);
    dest[n]='\0';
    printf("Dest is : %s\n",dest);
    return 0;
}
void *my_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for(size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
