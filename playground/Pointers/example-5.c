#include <stdio.h>
#include <stdlib.h>
#define COUNT 4

typedef struct {
  int a;
  double b;
  int c;
  long long int d;
} MYSTRUCT;

int main(){
  MYSTRUCT *p, *q;
  void *v;

  printf("size of MYSTRUCT = %lu\n", sizeof(MYSTRUCT));
  p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));

  for(int i=0; i < COUNT; i++){
    p[i].a = i;
    p[i].b = 1000000.0 + i;
    p[i].c = i * 20;
    p[i].d = 999999223 + i;
  }

  for(int i=0; i < COUNT; i++){
    q = p + i;
    printf("[V]alue [%d] \n a is %d\n b is %f\n c is %d\n d is %lld\n", i, q->a, q->b, q->c, q->d);
  }
  printf("addresses \n a is %p\n b is %p\n c is %p\n d is %p\n", &q->a, &q->b, &q->c, &q->d);
}