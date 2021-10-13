#include <stdio.h>

void print_array(int a[], int n)
{
    printf("Array : \n");
    for(int i=0; i<n ; i++){
        printf("%d, ", a[i]);
    }
    printf("\n #### \n");
}

int main()
{
    int a1[] = {2, 4, 6, 8, 10};
    int a2[] = {1, 3, 5, 7, 11};
    int a3[10];

    int i;
    for(i=0; i<5; i++){
        a3[i] = a1[i];
    }
    int j;
    for(j=0; j<5; j++, i++){
        a3[i] = a2[j];
    }
    print_array(a3, 10);
}