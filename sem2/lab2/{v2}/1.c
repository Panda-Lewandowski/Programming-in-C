#include <stdio.h>
#include <stdbool.h>



bool fibonacci(int n)
{
  if ((n == 1) || (n == 0))
  {
    return true;
  }
  else
  {
    int a = 1;
    int b = 1;
    int c = 0;
    while (c < n)
    {
      c = a + b;
      a = b;
      b = c;
    }
    if (c == n)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

int main()
{

  int a;
  int count = 0;
  printf("(Enter not digit to exist)\nEnter number: \n");
  while ((scanf("%d", &a) == 1))
    {
      /*printf("a =%d\n",a );*/
      if (fibonacci(a))
      {
        count++;
      }
    }
    printf("Quantity of Fibonacci numbers: %d\n", count);
  return 0;
}
