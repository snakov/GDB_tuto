#include <stdio.h>
#include <stdlib.h>

void 
foo(int *i)
{
  int old = *i;
  for(int j =0; j < 100; j++)
    *i++;
  *i = old;
}

int
main(int argc, char **argv)
{
  int i, n = 10, sum = 0;
  
  for(i = 0; i < n; ) {
    foo(&i);
    sum += i;
  }
 
  printf("sum is %d\n", sum);

  return EXIT_SUCCESS;
}
