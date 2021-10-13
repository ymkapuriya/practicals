#include <stdio.h>

#define SIZE 5

int main()
{
  int array[] = {12, 32, 32, 443, 3};
  int a1[] = {3, 4};
  int a2[] = {2, 4};
  int arr2[SIZE];
  int i;
  printf("Enter array \n");
  for (i = 0; i < SIZE; i++)
  {
    printf("Enter number %d : ", (i + 1));
    scanf("%d", &arr2[i]);
  }

  printf("\nYou have entered  : ");
  for (i = 0; i < SIZE; i++)
  {
    printf("%d, ", arr2[i]);
  }

  return 0;
}
