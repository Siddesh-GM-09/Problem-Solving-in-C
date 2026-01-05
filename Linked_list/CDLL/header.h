#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct number
{
    struct number *prev;
    int num;
    struct number *next;
} CDLL;

void addBeg(CDLL **);
void addEnd(CDLL **);
void display(CDLL *);
int countNode(CDLL *);
void revPrint(CDLL *);
void delectNode(CDLL **);