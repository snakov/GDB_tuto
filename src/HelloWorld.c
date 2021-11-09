#include <stdio.h>
#include <stdlib.h>

void
print(char *str)
{
  printf("%s \n", str);
}


int
main(int argc, char **argv)
{
  char *s = "Hello World";
  
  print(s);
  
  return EXIT_SUCCESS;
}
