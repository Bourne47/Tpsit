#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CONST 5

int main(){
    char *pc;
    int *pi;
    double *pd;
    printf("%d %d %d ", sizeof(pc), sizeof(pi), sizeof(pd));
    printf("%d %d %d\n", sizeof(char *), sizeof(int *), sizeof(double *));
    printf("%d %d %d ", sizeof(*pc), sizeof(*pi), sizeof(*pd));
    printf("%d %d %d\n", sizeof(char), sizeof(int), sizeof(double));

    return 0;
}