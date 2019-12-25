#include <stdlib.h>
#include <stdio.h>

void * my_malloc(size_t s)
{
  size_t * ret = malloc(sizeof(size_t) + s);
  *ret = s;
  return &ret[1];
}

void my_free(void * ptr)
{
  free( (size_t*)ptr - 1);
}

size_t allocated_size(void * ptr)
{
  return ((size_t*)ptr)[-1];
}

int main(int argc, const char ** argv) {
  int * array = my_malloc(sizeof(int) * 3);
  printf("%lu\n", allocated_size(array));
  my_free(array);
  return 0;
}
