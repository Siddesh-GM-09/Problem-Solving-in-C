#include<stdio.h>

float my_atof(char *);
int main(int argc,char** argv){
    if(argc!=2){
        printf("Usage : ./a.out string\n");
        return 0;
    }
    float num=my_atof(argv[1]);
    printf("Number is %f\n",num);
    return 0;
}
float my_atof(char* str){
    float result=0.0;
    float fact=1.0;
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
    while(*str>='0'&& *str<='9'){
        result=result*10+(*str-'0');
        str++;
    }
    if(*str=='.'){
        str++;
        while(*str){
            fact/=10;
            result=result+(*str-'0')*fact;
            str++;
        }
    }
    return (sign*result);
}