#include <stdio.h>
#include <stdbool.h>



bool is_simple(int n)
{
  int i = 2;
  int j = 0;
  while ((i*i <= n) && (j != 1))
  {
    if (n % i == 0)
    {
      j = 1;
    }
    i++;
  }
  if (j == 1)
  {
    /*printf("noo\n" );*/
    return false;
  }
  else
  {
    /*printf("uyes\n" );*/
    return true;
  }
}

int main()
{

  int a;
  int count = 0;
  printf("(Enter not digit to exist)\nEnter number: \n");
  while ((scanf("%d", &a) == 1) || (!a))
    {
      /*printf("a =%d\n",a );*/
      if ((is_simple(a)) && (a != 1) && (a != 0))
      {
        count++;
      }
    }
    printf("Quantity of simple numbers: %d\n",count);
    /*int a;
    printf("Enter a: ");
    if (!scanf("%d", &a))
    {
      printf("Invlid value.\n");
      return -1;
    }
    is_simple(a);*/
  return 0;
}
