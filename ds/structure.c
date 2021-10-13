#include <stdio.h>

/**
 * Struture definition
 */
struct employee
{
    int number;
    char name[20];
    float marks;
};

int main()
{
    //initilisation of structure variable
    struct student s;
    struct employee emp[2];

    printf("Enter student detail : \n");
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter number : ");
        scanf("%d", &stu[i].number);
        printf("\nEnter name : ");
        scanf("%s", stu[i].name);
        printf("\nEnter marks : ");
        scanf("%f", &stu[i].marks);
    }

    printf("Number : %d, ", stu[0].number);
    printf("Name : %s, ", stu[0].name);
    printf("Marks : %f\n", stu[0].marks);
    return 0;
}
