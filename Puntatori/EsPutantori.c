#include <stdio.h>
#include <stdlib.h>

void main(){
    int *pi;
    *pi = 15;
    printf("%p\n", pi);
    pi = pi + 1;
    printf("%p\n", pi);
}