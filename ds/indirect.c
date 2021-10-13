#include <stdio.h>

#define SIZE 6

void print_array(int a[])
{
  int i;
  printf("\n Array content \n");
  for (i = 0; i < SIZE; i++)
  {
    printf("%d, ", a[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int a[] = {12, 3, 13, 16, 23, 32};
  int i, j, k;
  print_array(a);

  int t[6];
  for (i = 0; i < SIZE; i++)
  {
    t[i] = i;
  }
  print_array(t);

  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE - 1; j++)
    {
      if (a[t[j + 1]] < a[t[j]])
      {
        k = t[j + 1];
        t[j + 1] = t[j];
        t[j] = k;
      }
    }
  }

  printf("Sorted \n");
  print_array(t);
  print_array(a);
  for (i = 0; i < SIZE; i++)
  {
    printf("%d, ", a[t[i]]);
  }
  printf("\n");

  return 0;
}
