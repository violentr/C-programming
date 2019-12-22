#include <stdio.h>
#include <stdlib.h>

int main(void){
  const int size = sizeof(char)*16;
  _Bool bits[size];
  int k;
  int number;
  int user_input;
  // int *ptr = &number;
  //printf(" address %p ", ptr);
  printf("Please enter the number:");
  scanf("%d", &number);
// Save a user entered number
  user_input = number;

  for(k=0; k < size;k++){
    bits[size-k-1] = number&1;
    number>>= 1;
    //number >>= 1;
  }

  //printf(" address after modification %p ", ptr);
  printf("[+] Decimal number %d is equal to binary\n", user_input);
  for(k=0; k < size;k++){
      printf("| %d", bits[k]);
  }
  printf("|\n");

  return 0;
}
