#include <stdio.h>

void swap(int *p, int *q){
    int t;
    printf("\n Before %d %d", *p, *q);
    t = *q;
    *q = *p;
    *p = t;
    printf("\n After %d %d", *p, *q);
}

int incr(int n)
{
    printf("\nPrevious value : %d", n);
    n++; // = *n + 1;//++;// = *n + 1;
    printf("\nNext value : %d", n);
    return n;
}

int main(int argc, char const *argv[])
{
    int a;
    int b;
    a = 10;
    b = 15;
    swap(&a, &b);
    printf("\nValue of a : %d, b : %d", a, b);
    printf("\n");
    return 0;
}
