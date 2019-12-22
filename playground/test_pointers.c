#include <stdio.h>
#include <stdlib.h>

void square(int *input){
  *input *= *input;
}

int squared(int input){
  return input *= input;
}

struct rectangle {
  int length;
  int width;
};

void staticValueCheck(){
  int static z = 0;
  z++;
  printf("Value of X: %d \n", z);
}

void pointers(){
  int i = 10;
  float f = 2.34;
  char ch = 'k';
  void *vptr;

  vptr =&i;
  printf("Value of i = %d\n", *(int *)vptr);
  vptr = &f;
  printf("Value of i = %.2f\n", *(float *)vptr);
  vptr = &ch;
  printf("Value of i = %c\n", *(char *)vptr);
}

void dynamicArray() {
  int size;
  printf("How many int elements u need ?");
  scanf("%d", &size);

  int *arr = malloc(size * sizeof(int));
  for(int i=0; i<size; i++){

    // make sure there is no space in between
    // it is treated as additional input
    scanf("%d", &arr[i]);
  }

  printf("This is your array: \n");
  for(int i=0; i<size; i++){
     printf("arr[%d] = %d\n", i, arr[i]);
  }
  // do not forget to free memory after use
  // not releasing it may lead to app crash
  free(arr);
}

int main(){
  int x = 5;
  int *pointer_x = &x;

  struct rectangle myRectangle = {5, 6};

  printf("Length is %d and width %d \n", myRectangle.length, myRectangle.width);
  square(&x);

  // value of x will be 25
  printf("result of X is %d\n", *pointer_x);
  printf("result of memory address where stored value of X %p\n", &pointer_x);

  int a = 5;
  int c = squared(a);

  // value of c will be 25
  printf("result of C is %d\n", c);

  for (int i=0; i< 4; i++){
    staticValueCheck();
  }

  dynamicArray();
  pointers();

  return 0;
}
