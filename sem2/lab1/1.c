/*Решение квадратного уравнения. Вариант №2*/
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	printf("The equation: Ax^2 + Bx + C = 0\n");
	printf("Enter A: ");
	if (!scanf("%f", &a))
	{
		printf("Invalid value\n");
		return 1;
	}
	
	printf("Enter B: ");
	if (!scanf("%f", &b))
	{
		printf("Invalid value\n");
		return 1;
	}


	printf("Enter C: ");
	if (!scanf("%f", &c))
	{
		printf("Invalid value\n");
		return 1;
	}


	if (a != 0)
	{
		float d = b * b - 4 * a *c;
		if (d > 0)
		{
			printf("x1 = %.3f \n", (-b - sqrt(d)) / (2 * a ));
			printf("x2 = %.3f \n", (-b + sqrt(d)) / (2 * a ));
		} else if (d == 0)
		{
			printf("x = %.3f\n", -b / (2 * a));
		} else if (d < 0)
		{
			printf("There are no real solutions\n");
		}




	}else if (a == 0)
	{	
		if (b == 0)
		{
			printf(" 0 = %.3f\n ", -c);
		}
		else 
		{
			printf("x1 = 0 \n ");
			printf("x2 = %.3f \n", (-c / b ));
		}
	}



	return 0;
}
