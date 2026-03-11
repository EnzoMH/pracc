#include <stdio.h>

int main() {
    int* p = malloc(4);
    int i = 10;
    p = &i;
    
    printf("addr of i : %p \n", &i);
    printf("value of p : %p \n", p);
    printf("*p : %d \n", *p);
    
    return 0;
}