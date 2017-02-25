#include <stdio.h>

void swap(float *a, float *b)
{
    float buf = *a;
    *a = *b;
    *b = buf;
}

int main()
{
  float a;
  printf("Enter a: ");
  if (!scanf("%f", &a))
  {
    printf("Invlid value.\n");
    return -1;
  }
  float b;
  printf("Enter b: ");
  if (!scanf("%f", &b))
  {
    printf("Invlid value.\n");
    return -1;
  }
  printf("a = %f\n",a);
  printf("b = %f\n",b);
  swap(&a,&b);
  printf("Swapped:\n");
  printf("a = %f\n",a);
  printf("b = %f\n",b);

  return 0;
}
