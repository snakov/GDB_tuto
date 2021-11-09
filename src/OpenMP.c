#include <stdio.h>
#include <stdlib.h>
#include <omp.h>



int
main (int argc, char **argv)
{
  int   i, n;
  double *a, *b, result;

  n = 100;
  result = 0.0;
  a = malloc(n * sizeof(*a));
  b = malloc(n * sizeof(*b));
  
  for (i=0; i < n; i++) {
    a[i] = i;
    b[i] = i * 2.0;
  }
  
#pragma omp parallel for shared(a,b) private(i,n) num_threads(4) reduction(+:result)
  for (i=0; i < n; i++)
    result += (a[i] * b[i]);
  
  printf("Final result= %f\n",result);
  
  free(a); free(b);
  
  return EXIT_SUCCESS;
}
