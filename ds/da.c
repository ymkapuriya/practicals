#include <stdio.h>
#include <stdlib.h>

struct student
{
    int no;
    char *name;
};

int main(int argc, char const *argv[])
{
    int n;
    int *numbers;

    struct student *stus;
    stus = (struct student *)malloc(5 * sizeof(struct student));

    printf("Enter how many numbers : ");
    scanf("%d", &n);

    numbers = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d : ", i + 1);
        scanf("%d", numbers + i);
    }

    return 0;
}
