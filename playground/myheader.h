#include <stdio.h>

void printFactorial(int num){
  int place = num;
  int result = 1;

  while(place != 0){
    result = result * place;
    place = place -1;
  }
  printf("The factorial of number %d is %d\n", num, result);
}
