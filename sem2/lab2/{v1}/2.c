#include <stdio.h>

void swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}

int main()
{
  int a;
  printf("Enter a: ");
  if (!scanf("%d", &a))
  {
    printf("Invlid value.\n");
    return -1;
  }
  int b;
  printf("Enter b: ");
  if (!scanf("%d", &b))
  {
    printf("Invlid value.\n");
    return -1;
  }
  printf("a = %d\n",a);
  printf("b = %d\n",b);
  swap(&a,&b);
  printf("Swapped:\n");
  printf("a = %d\n",a);
  printf("b = %d\n",b);

  return 0;
}
