#include <stdio.h>

int main(){
	int t;
	int Sum = 0;
	int Odd = 0;

	printf("Enter \n");
	while(scanf("%d", &t))
	{
		if (t % 2)
		{
			Sum += t;
			Odd = 1;
		}
	}

	printf("\n");

	if (Odd)
	{
		printf("Sum of odd numbers: %d\n", Sum);
	}
	else
	{
		printf("There is not odd numbers.\n");
	}
	return 0;
}
