#include<stdio.h>
#include<limits.h>
int my_atoi(char*);
int main(int argc,char** argv){
    if(argc!=2){
        printf("Usage : a.out string\n");
        return 0;
    }
    int num=my_atoi(argv[1]);
    printf("Number is : %d\n",num);
    return 0;
}
int my_atoi(char *str){
    long long result=0;
    int sign=1;
    while(*str==' '){
        str++;
    }
    if(*str=='-'){
        sign=-1;
        str++;
    }
    else if(*str=='+'){
        str++;
    }
    while(*str && *str>='0'&& *str<='9'){
        result=result*10+(*str-'0');
        if(sign==1&&result>=INT_MAX){
            return INT_MAX;
        }
        if(sign==-1&&result<=INT_MIN){
            return INT_MIN;
        }
        str++;
    }
    return (int)(sign*result);
}