#include <stdio.h>
#include <stdlib.h>


int
main()
{
  int i, sum = 0, *tab, n = 10, N = 100000;
  
  tab = malloc(n * sizeof(*tab));
  
  for(i = 1; i < n; i++)
    tab[i] = i + 10;

  for(i = 0; i < N; i++)
    sum += tab[i];

  if (sum)
    printf("sum = %d\n", sum);

  return EXIT_SUCCESS;
}
   
