#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int a[COUNT];
float b[COUNT];
double c[COUNT];
long long int d[COUNT];
short int e[COUNT];
long int f[COUNT];

void pointerArithmetic(){
  int * pa;
  float *pb;
  double *pc;
  long long int* pd;
  short int* pe;
  long int* pf;

  printf("sizes are: int %d; float %d; double %d; long long int %d; short int %d, long int %d\n", sizeof(int),
    sizeof(float), sizeof(double), sizeof(long long int), sizeof(short int), sizeof(long int));
  pa = a;
  pb = b;
  pc = c;
  pd = d;
  pe = e;
  pf = f;
  for(int i =0; i < COUNT; i++){
    a[i] = i;
    b[i] = (float)i;
    c[i] = (double)i;
    d[i] = i;
    e[i] = i;
    f[i] = i;
  }
  pa += 1;
  pb += 1;
  pc += 1;
  pd += 1;
  pe += 1;
  pf += 1;
  printf("[INT] address of a is %p [%d]; value of pa is %p [%d]-in decimal; value pointed to by pa is %d\n", a, a, pa, pa, *pa);
  printf("[FLOAT] address of b is %p [%d]; value of pb is %p [%d]-in decimal; value pointed to by pb is %f\n", b, b, pb, pb, *pb);
  printf("[DOUBLE] address of c is %p [%d]; value of pc is %p [%d]-in decimal; value pointed to by pc is %f\n", c, c, pc, pc, *pc);
  printf("[LL INT] address of d is %p [%d]; value of pd is %p [%d]-in decimal; value pointed to by pd is %lld\n", d, d, pd, pd, *pd);
  printf("[SH INT]address of e is %p [%d]; value of pe is %p [%d]-in decimal; value pointed to by pe is %hd\n", e, e, pe, pe, *pe);
  printf("[L INT] address of f is %p [%d]; value of pf is %p [%d]-in decimal; value pointed to by pf is %ld\n", f, f, pf, pf, *pf);
}

void simplePointerArithmetic(){
  int *p;
  int a[COUNT];
  printf("size of an 'int' is %lu\n", sizeof(int));
  for(int i=0; i < COUNT; i++) a[i] = i;
  p=a;

  printf("address of a is %p; value of p is %p [%d]-in decimal; value pointed to by p is %d\n", a, p, p, *p);
  p = p + 1; /* + 1 sizeof(int) = 4 0x7ffeec525550 [-3301485 28] | difference 28 - 24*/
  printf("address of a is %p; value of p is %p [%d]-in decimal; value pointed to by p is %d\n", a, p, p, *p);
  p = p + 2;/* + 2 sizeof(int) = 2*4  0x7ffeec525554 [-3301485 24] | difference 24 - 16 */
  printf("address of a is %p; value of p is %p [%d]-in decimal; value pointed to by p is %d\n", a, p, p, *p);
  p = p + 1;/* + 1 sizeof(int) = 1*4 0x7ffeec52555c [-3301485 16] */
}

int main(){
  simplePointerArithmetic();
  pointerArithmetic();
  return 0;
}