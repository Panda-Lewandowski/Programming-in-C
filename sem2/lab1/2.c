#include <math.h>
#include <stdio.h>

int main()
{

  double x;
  printf("Enter x: ");
  if (!scanf("%lf", &x))
  {
    printf("Invalid value.\n");
	return 1;
  }

  double eps;
  printf("Enter eps: ");
  if (!scanf("%lf", &eps))
  {
	printf("Invalid value.\n");
	return 1;
  }

  double sum = 1;
  int fact = 1;
  double currX = 1;

  while (fabs(currX) >= eps)
  {
    /*printf(" %5.f %5.d %5.f %5.d\n ", sum, fact, currX, i);*/
    currX *= (x / fact);
    sum += currX; 
	fact += 1;
  }

  printf("\nSum: %.3f", sum);
  printf("\nExp: %.3f\n", exp(x));
  printf("Defferent is: %.6f\n", fabs(exp(x) - sum));


  return 1;
}
