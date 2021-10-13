#include <stdio.h>

/* call by reference */

void swap(int *p, int *q)
{
    int t;
    printf("\n Before %d, %d", *p, *q);
    t = *q;
    *q = *p;
    *p = t;
    printf("\n After %d, %d", *p, *q);
}

int increment(int n)
{
    printf("\nBefore : %d", n);
    n++;
    printf("\nAfter : %d", n);
    return n;
}

int main(int argc, char const *argv[])
{
    int a, b;
    int *q;
    a = 10;
    b = 15;
    //a = increment(a);
    swap(q, &b);
    printf("\nAfter swap %d, %d", a, b);
    printf("\n");
    return 0;
}
