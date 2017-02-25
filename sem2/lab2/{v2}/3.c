#include <stdio.h>

void time(int s)
{
  printf("%d seconds is ", s );
  int h = s / 3600;
  s = s - h * 3600;
  /*printf("hours = %d\n",h );*/
  int m = s / 60;
  s = s - m * 60;
  /*printf("minutes = %d\n",m );
  printf("seconds = %d\n", s);*/
  printf("%d:%d:%d\n", h, m, s);
}

int main()
{
  int a;
  printf("Enter time: ");
  if (!scanf("%d", &a))
  {
    printf("Invlid value.\n");
    return -1;
  }
  time(a);
  return 0;
}
