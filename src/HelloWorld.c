#include <stdio.h>
#include <stdlib.h>

void
print(char *str)
{
  printf("%s \n", str);
}

void
print_all(char *str, int n)
{
  for (int i = 0; i < n; i++)
    print(str) ;
}

int
main(int argc, char **argv)
{
  char *s = "Hello World";
  int n = argc > 1 ? atoi(argv[1]) : 1;

  print_all(s, n);
  
  return EXIT_SUCCESS;
}
