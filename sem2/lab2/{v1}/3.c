#include <stdio.h>

void larger_of(float *a, float *b)
{
    *a = *a>*b ? *a : *b;
    *b = *a;
}

int main()
 {
   float x;
   printf("Enter x: ");
   if (!scanf("%f", &x))
   {
     printf("Invlid value.\n");
     return -1;
   }
   float y;
   printf("Enter y: ");
   if (!scanf("%f", &y))
   {
     printf("Invlid value.\n");
     return -1;
   }
   printf("x = %f\n",x);
   printf("y = %f\n",y);
   larger_of(&x,&y);
   printf("larger_of...\n");
   printf("x = %f\n",x);
   printf("y = %f\n",y);
  return 0;
}
